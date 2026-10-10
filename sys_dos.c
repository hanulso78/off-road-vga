/* ============================================================================
 *  sys_dos.c  -  도스(djgpp) 플랫폼: 옮긴 Off-Road 를 진짜 PC 에서 돌린다
 * ----------------------------------------------------------------------------
 *  화면    안내 화면은 글자 모드 3 (M[B8000] 글자+속성을 그대로 옮긴다), 게임은 CGA 모드 4.
 *          원판판(ORC.EXE)은 진짜 모드 4 로 M[B8000] 을 옮겨 보이고, 256색판(ORVGA.EXE)은
 *          모드 13h 에 orvga.c 가 그린 것을 보인다.  프레임 끝(폴 지점)에서만 보인다 -> 깜빡임 없음.
 *  속도    원판은 CPU 속도로 돈다 (처음에 고른 기계에 따라 프레임마다 빈 되돌이 [004C] 번).
 *          옮긴 코드가 센 8088 클럭(or_cyc)과 빈 되돌이 횟수(or_spins)를, 고른 기계의 빠르기로
 *          시간으로 바꿔 그만큼 흐르게 기다린다 -> 그 기계에서 원판이 돌던 빠르기.
 *  자판    IRQ1 을 직접 받아 스캔 코드를 모았다가 폴 지점에서 BIOS 자판 버퍼로 (자동 반복 그대로).
 *          Ctrl+Q : 바로 끝.
 *  시험    ORTEST=대본 : "틱 +키 [누름틱]" / "틱 스캔16진" / "틱 shot 이름" / "틱 quit"
 *          (시간을 맞추지 않고 빨리 돈다 -> 호스트 시험판과 같은 결과; ORREAL=1 이면 시간 맞춤)
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dpmi.h>
#include <go32.h>
#include <pc.h>
#include <sys/farptr.h>
#include <sys/movedata.h>
#include <sys/nearptr.h>
#include <time.h>
#include "cpu.h"
#include "plat.h"
#ifdef ORVGA
#include "orvga.h"
#endif

static int gfx;                 /* 0 글자, 4/5 CGA, 0x13 VGA */
static uint8_t vbuf[64000];
static uclock_t t_run0;
static long st_pres, st_behind;
static uclock_t st_prest, st_comp;
static int nskip;
static long st_skip;
static volatile int quit_req;
static int shown_valid;
static uint8_t shown_color = 0xFF;
static uint8_t shown_text[4000];
static uint16_t shown_cursor = 0xFFFF;

/* ---- 자판 IRQ1 ---------------------------------------------------------------- */
#define KQ 256
static volatile uint8_t kq[KQ];
static volatile unsigned kq_head, kq_tail;
static volatile int k_ctrl;
static _go32_dpmi_seginfo old_kb, new_kb;
static int kb_on;

static void kb_isr(void)
{
    uint8_t sc = inportb(0x60);
    uint8_t v = inportb(0x61);
    outportb(0x61, v | 0x80);
    outportb(0x61, v);
    if ((sc & 0x7F) == 0x1D)
        k_ctrl = !(sc & 0x80);
    if (sc == 0x10 && k_ctrl)
        quit_req = 1;
    if (sc != 0xE0 && ((kq_head + 1) & (KQ - 1)) != kq_tail) {
        kq[kq_head] = sc;
        kq_head = (kq_head + 1) & (KQ - 1);
    }
    outportb(0x20, 0x20);
}
static void kb_isr_end(void) {}

static void kb_install(void)
{
    if (kb_on)
        return;
    _go32_dpmi_lock_code((void *)kb_isr, (unsigned long)kb_isr_end - (unsigned long)kb_isr);
    _go32_dpmi_lock_data((void *)kq, sizeof kq);
    _go32_dpmi_lock_data((void *)&kq_head, sizeof kq_head);
    _go32_dpmi_lock_data((void *)&kq_tail, sizeof kq_tail);
    _go32_dpmi_lock_data((void *)&k_ctrl, sizeof k_ctrl);
    _go32_dpmi_lock_data((void *)&quit_req, sizeof quit_req);
    _go32_dpmi_get_protected_mode_interrupt_vector(9, &old_kb);
    new_kb.pm_offset = (unsigned long)kb_isr;
    new_kb.pm_selector = _go32_my_cs();
    _go32_dpmi_allocate_iret_wrapper(&new_kb);
    _go32_dpmi_set_protected_mode_interrupt_vector(9, &new_kb);
    kq_head = kq_tail = 0;
    kb_on = 1;
}

static void kb_remove(void)
{
    if (!kb_on)
        return;
    _go32_dpmi_set_protected_mode_interrupt_vector(9, &old_kb);
    _go32_dpmi_free_iret_wrapper(&new_kb);
    kb_on = 0;
    _farpokew(_dos_ds, 0x41A, _farpeekw(_dos_ds, 0x41C));
}

/* ---- 시험 대본 ------------------------------------------------------------------ */
static int test_on, real_test;
static struct {
    uint32_t t;
    int what;           /* 'k' 키, 's' 찍기, 'q' 끝 */
    int sc;
    char name[16];
} tev[8192];
static int ntev, tpos;

static int keycode(const char *k)
{
    static const struct { const char *n; int sc; } T[] = {
        {"enter", 0x1C}, {"up", 0x48}, {"down", 0x50}, {"left", 0x4B}, {"right", 0x4D}, {"space", 0x39},
        {"esc", 0x01}, {"tab", 0x0F}, {"home", 0x47}, {"end", 0x4F}, {"pgup", 0x49}, {"pgdn", 0x51}, {"ins", 0x52},
        {"del", 0x53}, {"ctrl", 0x1D}, {"alt", 0x38}, {"lshift", 0x2A}, {"rshift", 0x36}, {"scroll", 0x46},
        {"bksp", 0x0E}};
    static const char *rows[4] = {"1234567890", "qwertyuiop", "asdfghjkl", "zxcvbnm"};
    static const int base[4] = {2, 0x10, 0x1E, 0x2C};
    unsigned i;
    int r;
    for (i = 0; i < sizeof T / sizeof T[0]; i++)
        if (!strcmp(T[i].n, k))
            return T[i].sc;
    if (k[0] == 'f' && k[1] >= '1' && k[1] <= '9')
        return 0x3B + atoi(k + 1) - 1;
    if (k[0] && !k[1])
        for (r = 0; r < 4; r++) {
            const char *p = strchr(rows[r], k[0]);
            if (p)
                return base[r] + (int)(p - rows[r]);
        }
    return 0;
}

static void test_init(const char *fn)
{
    FILE *f = fopen(fn, "r");
    char ln[128], a[32], b[32];
    unsigned t;
    int n, i, j;
    if (!f)
        return;
    while (ntev < 8000 && fgets(ln, sizeof ln, f)) {
        char *h = strchr(ln, '#');
        if (h)
            *h = 0;
        b[0] = 0;
        n = sscanf(ln, "%u %31s %31s", &t, a, b);
        if (n < 2)
            continue;
        if (!strcmp(a, "shot")) {
            tev[ntev].t = t;
            tev[ntev].what = 's';
            strncpy(tev[ntev].name, b, 15);
            ntev++;
        } else if (!strcmp(a, "quit")) {
            tev[ntev].t = t;
            tev[ntev++].what = 'q';
        } else if (a[0] == '+') {
            int sc = keycode(a + 1), hold = n > 2 ? atoi(b) : 2;
            tev[ntev].t = t; tev[ntev].what = 'k'; tev[ntev++].sc = sc;
            tev[ntev].t = t + hold; tev[ntev].what = 'k'; tev[ntev++].sc = sc | 0x80;
        } else {
            tev[ntev].t = t; tev[ntev].what = 'k'; tev[ntev++].sc = (int)strtol(a, 0, 16);
        }
    }
    fclose(f);
    for (i = 1; i < ntev; i++)
        for (j = i; j > 0 && tev[j - 1].t > tev[j].t; j--) {
            tev[8191] = tev[j];
            tev[j] = tev[j - 1];
            tev[j - 1] = tev[8191];
        }
    test_on = 1;
}

/* ---- 화면 ----------------------------------------------------------------------- */
static void bios_mode(int m)
{
    __dpmi_regs r;
    memset(&r, 0, sizeof r);
    r.x.ax = (uint16_t)m;
    __dpmi_int(0x10, &r);
}

static void text_mode(void)
{
    if (!gfx)
        return;
    bios_mode(3);
    gfx = 0;
    shown_cursor = 0xFFFF;
    memset(shown_text, 0, sizeof shown_text);
}

static void gfx_mode(int m)
{
#ifdef ORVGA
    if (orvga_on)
        m = 0x13;
#endif
    if (gfx != m) {
        bios_mode(m);
        gfx = m;
        shown_valid = 0;
        shown_color = 0xFF;
    }
}

#ifdef ORVGA
static uint8_t *vram;
static uint8_t *frame_dst(void)
{
    if (!vram && __djgpp_nearptr_enable())
        vram = (uint8_t *)(0xA0000 + __djgpp_conventional_base);
    return vram ? vram : vbuf;
}
#endif

static void present_text(void)
{
    uint16_t cur = (uint16_t)(M[0x450] | M[0x451] << 8);
    if (memcmp(shown_text, M + 0xB8000, 4000)) {
        memcpy(shown_text, M + 0xB8000, 4000);
        dosmemput(shown_text, 4000, 0xB8000);
    }
    if (cur != shown_cursor) {
        __dpmi_regs r;
        memset(&r, 0, sizeof r);
        r.h.ah = 2;
        r.x.dx = cur;
        __dpmi_int(0x10, &r);
        shown_cursor = cur;
    }
}

static void present(void)
{
    uclock_t a;
    if (!gfx) {
        present_text();
        return;
    }
    a = uclock();
#ifdef ORVGA
    if (gfx == 0x13) {
        static uint32_t shown_pal = 0xFFFFFFFF;
        uint8_t *d;
        if (shown_pal != orvga_palgen()) {
            const uint8_t *p = orvga_palette();
            int i;
            outportb(0x3C8, 0);
            for (i = 0; i < 768; i++)
                outportb(0x3C9, (uint8_t)(p[i] >> 2));
            shown_pal = orvga_palgen();
        }
        /* 일반 메모리에서 합성하고 한 번에 옮긴다 (비디오 메모리에 점마다 쓰면 느리다) */
        d = frame_dst();
        if (!orvga_present(vbuf))
            return;
        st_comp += uclock() - a;
        if (d != vbuf)
            memcpy(d, vbuf, 64000);
        else
            dosmemput(vbuf, 64000, 0xA0000);
        goto done;
    }
#endif
    if (shown_color != or_cga_color) {
        __dpmi_regs r;
        memset(&r, 0, sizeof r);
        r.x.ax = 0x0B00;
        r.x.bx = (uint16_t)(or_cga_color & 0x1F);
        __dpmi_int(0x10, &r);
        memset(&r, 0, sizeof r);
        r.x.ax = 0x0B00;
        r.x.bx = (uint16_t)(0x0100 | ((or_cga_color >> 5) & 1));
        __dpmi_int(0x10, &r);
        shown_color = or_cga_color;
    }
#ifndef ORVGA
    /* 바뀐 64 바이트 토막만 옮긴다 (cpu.h MWB 가 표시): 화면 메모리 쓰기는 ISA 에서 느리다 */
    {
        int k, any = 0;
        for (k = 0; k < 256; k++) {
            uint32_t o = (uint32_t)k * 64, n = 64;
            if (shown_valid && !cga_dirty[k])
                continue;
            cga_dirty[k] = 0;
            dosmemput(M + 0xB8000 + o, n, 0xB8000 + o);
            any = 1;
        }
        shown_valid = 1;
        if (!any)
            return;
    }
#else
    dosmemput(M + 0xB8000, 0x4000, 0xB8000);
    shown_valid = 1;
#endif
#ifdef ORVGA
done:
#endif
    st_pres++;
    st_prest += uclock() - a;
}

static void save_bmp(const char *name)
{
    uint8_t hdr[54];
    char fn[40];
    FILE *f;
    int y, x, i;
    uint32_t v;
    present();
    sprintf(fn, "%s.BMP", name);
    if (!(f = fopen(fn, "wb")))
        return;
    memset(hdr, 0, sizeof hdr);
    hdr[0] = 'B';
    hdr[1] = 'M';
    v = 54 + 1024 + 64000; memcpy(hdr + 2, &v, 4);
    v = 54 + 1024; memcpy(hdr + 10, &v, 4);
    v = 40; memcpy(hdr + 14, &v, 4);
    v = 320; memcpy(hdr + 18, &v, 4);
    v = 200; memcpy(hdr + 22, &v, 4);
    hdr[26] = 1;
    hdr[28] = 8;
    fwrite(hdr, 1, 54, f);
    if (gfx == 0x13) {
        outportb(0x3C7, 0);
        for (i = 0; i < 256; i++) {
            uint8_t q[4];
            q[2] = (uint8_t)(inportb(0x3C9) << 2);
            q[1] = (uint8_t)(inportb(0x3C9) << 2);
            q[0] = (uint8_t)(inportb(0x3C9) << 2);
            q[3] = 0;
            fwrite(q, 1, 4, f);
        }
        dosmemget(0xA0000, 64000, vbuf);
    } else {
        static const uint8_t base[16][3] = {{0, 0, 0}, {0, 0, 170}, {0, 170, 0}, {0, 170, 170}, {170, 0, 0},
            {170, 0, 170}, {170, 85, 0}, {170, 170, 170}, {85, 85, 85}, {85, 85, 255}, {85, 255, 85}, {85, 255, 255},
            {255, 85, 85}, {255, 85, 255}, {255, 255, 85}, {255, 255, 255}};
        int c[4], in = (or_cga_color & 0x10) ? 8 : 0;
        c[0] = or_cga_color & 15;
        if (or_vmode == 5) {
            c[1] = 3 + in; c[2] = 4 + in; c[3] = 7 + in;
        } else if (or_cga_color & 0x20) {
            c[1] = 3 + in; c[2] = 5 + in; c[3] = 7 + in;
        } else {
            c[1] = 2 + in; c[2] = 4 + in; c[3] = 6 + in;
        }
        for (i = 0; i < 256; i++) {
            uint8_t q[4] = {0, 0, 0, 0};
            if (i < 4) {
                q[2] = base[c[i]][0];
                q[1] = base[c[i]][1];
                q[0] = base[c[i]][2];
            }
            fwrite(q, 1, 4, f);
        }
        for (y = 0; y < 200; y++)
            for (x = 0; x < 320; x++) {
                uint8_t b = M[0xB8000 + (y & 1) * 0x2000 + (y >> 1) * 80 + (x >> 2)];
                vbuf[y * 320 + x] = (uint8_t)((b >> (6 - 2 * (x & 3))) & 3);
            }
    }
    for (y = 199; y >= 0; y--)
        fwrite(vbuf + y * 320, 1, 320, f);
    fclose(f);
}

/* ---- 속도: 고른 기계 흉내 ------------------------------------------------------ */
/* [004C] (빈 되돌이 횟수) 로 고른 기계를 안다.  work = 8088 4.77MHz 대비 빠르기,
 * spin = 빈 되돌이 한 번 (loop $) 의 시간 (마이크로초) */
static const struct { uint16_t delay; double work, spin_us; const char *name; } MACH[] = {
    {1, 1.0, 17 / 4.77, "IBM PC/XT 4.77MHz"},
    {5000, 1.68, 17 / 8.0, "XT-TURBO 8MHz"},
    {10000, 3.3, 8 / 8.0, "IBM AT 8MHz"},
    {20000, 4.1, 8 / 10.0, "AT-TURBO 10MHz"},
    {50000, 8.0, 11 / 16.0, "PS/2 386 16MHz"},
};
static uclock_t pace_t;          /* 원판이라면 지금쯤이었을 시각 */
static uint32_t pace_cyc, pace_spins;

static void pace(void)
{
    uint16_t dly = (uint16_t)(M[(LOADSEG + 0x20) * 16 + 0x4C] | M[(LOADSEG + 0x20) * 16 + 0x4D] << 8);
    unsigned k, m = 0;
    double us;
    uclock_t now;
    for (k = 0; k < sizeof MACH / sizeof MACH[0]; k++)
        if (MACH[k].delay == dly)
            m = k;
    us = (double)(or_cyc - pace_cyc) / (4.77 * MACH[m].work) + (double)(or_spins - pace_spins) * MACH[m].spin_us;
    pace_cyc = or_cyc;
    pace_spins = or_spins;
    if (quit_req) {
        text_mode();
        kb_remove();
        exit(0);
    }
    if (test_on && !real_test)
        return;
    pace_t += (uclock_t)(us * UCLOCKS_PER_SEC / 1e6);
    now = uclock();
    if (now > pace_t + UCLOCKS_PER_SEC / 4) {       /* 너무 뒤처짐 (느린 PC): 기준을 다시 잡는다 */
        st_behind++;
        pace_t = now;
    }
    while (uclock() < pace_t)
        ;
}

/* ---- 플랫폼 ---------------------------------------------------------------------- */
static void leave(int code)
{
    text_mode();
    kb_remove();
    exit(code);
}

void plat_mode(int mode)
{
    if (mode == 4 || mode == 5)
        gfx_mode(mode);
    else
        text_mode();
#ifdef ORVGA
    orvga_mode(mode);
#endif
}

static uclock_t t_tick_end, st_game;
static long st_ngame;
static void plat_tick2(uint32_t tick);

/* 틱 사이 = 게임 계산 시간 (화면 내보내기, 기다림 빼고) 을 잰다 (ORLOG) */
void plat_tick(uint32_t tick)
{
    if (t_tick_end && tick > 50) {
        st_game += uclock() - t_tick_end;
        st_ngame++;
    }
    plat_tick2(tick);
    t_tick_end = uclock();
}

static void plat_tick2(uint32_t tick)
{
    pace();
    if (test_on) {
        while (tpos < ntev && tev[tpos].t <= tick && tev[tpos].what != 'k') {
            if (tev[tpos].what == 's')
                save_bmp(tev[tpos].name);
            else {
                FILE *f = fopen("ORLOG.TXT", "w");
                if (f) {
                    double el = (double)(uclock() - t_run0) / UCLOCKS_PER_SEC;
                    fprintf(f, "tick %lu in %.1f s (%.1f frames/s), presents %ld avg %.2f ms (compose %.2f), game %.2f ms/frame, behind %ld, skipped %ld\n",
                            (unsigned long)tick, el, el > 0 ? tick / el : 0.0, st_pres,
                            st_pres ? (double)st_prest * 1000.0 / UCLOCKS_PER_SEC / st_pres : 0.0,
                            st_pres ? (double)st_comp * 1000.0 / UCLOCKS_PER_SEC / st_pres : 0.0,
                            st_ngame ? (double)st_game * 1000.0 / UCLOCKS_PER_SEC / st_ngame : 0.0, st_behind, st_skip);
#ifdef ORVPROF
                    {
                        extern long long prof_t[16];
                        int i;
                        for (i = 0; i < 8; i++)
                            fprintf(f, "part %d: %.2f ms/present\n", i, st_pres ? (double)prof_t[i] * 1000.0 / UCLOCKS_PER_SEC / st_pres : 0.0);
                    }
#endif
                    fclose(f);
                }
                leave(0);
            }
            tpos++;
        }
        if (!real_test) {
            if ((tick & 15) == 0)
                present();
            return;
        }
    }
    /* 느린 PC: 원판 시각보다 15ms 넘게 뒤처졌으면 이번 화면은 건너뛴다 (게임 빠르기는 그대로,
     * 화면만 성기게).  그래도 세 프레임에 한 번은 보인다 */
    if (uclock() > pace_t + UCLOCKS_PER_SEC * 15 / 1000 && nskip < 2) {
        nskip++;
        st_skip++;
        return;
    }
    nskip = 0;
    present();
}

void plat_spin(void)
{
    /* 긴 빈 되돌이 (트럭이 부서진 뒤 쉼): 그만큼 기다린다 */
    if (or_spins - pace_spins > 200000) {
        pace();
        present();
    }
}

int plat_key(uint32_t tick)
{
    if (test_on) {
        if (tpos < ntev && tev[tpos].what == 'k' && tev[tpos].t <= tick)
            return tev[tpos++].sc;
        return -1;
    }
    /* 원판은 프레임마다 BIOS 버퍼에서 키를 하나만 꺼낸다.  누르고 있는 키의 자동 반복이 버퍼에
     * 쌓이면 새로 누른 키(오른쪽을 누른 채 위 = 점프)가 그 뒤로 밀리거나 가득 차서 버려진다.
     * 그래서 자동 반복(이미 눌린 키의 누름 코드)은 BIOS 버퍼가 비었을 때만 넣는다. */
    while (kq_tail != kq_head) {
        static uint8_t held[128];
        int k = kq[kq_tail];
        kq_tail = (kq_tail + 1) & (KQ - 1);
        if (k & 0x80)
            held[k & 0x7F] = 0;
        else if (held[k]) {
            if (M[0x41A] != M[0x41C])
                continue;               /* 반복인데 아직 앞 키가 남았다: 버림 */
        } else
            held[k] = 1;
        return k;
    }
    return -1;
}

uint8_t plat_pit(void)
{
    if (test_on)
        return 0x5A;
    outportb(0x43, 0x00);
    return inportb(0x40);
}

void plat_fatal(const char *msg)
{
    text_mode();
    kb_remove();
    printf("%s\n", msg);
    exit(1);
}

static void on_break(int sig)
{
    (void)sig;
    leave(1);
}

int main(int argc, char **argv)
{
    const char *ts = getenv("ORTEST");
    (void)argc;
    (void)argv;
    signal(SIGINT, on_break);
    uclock();
    if (ts)
        test_init(ts);
    real_test = getenv("ORREAL") != 0;
#ifdef ORVGA
    if (!getenv("ORCGA") && !orvga_load())
        printf("ORVGA: art table missing - running with CGA colours\n");
#endif
    bios_mode(3);
    kb_install();
    t_run0 = pace_t = uclock();
    or_init();
    or_run();
    leave(0);
    return 0;
}
