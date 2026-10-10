/* hosttest.c - 옮긴 C 를 윈도우(호스트)에서 키 대본대로 돌려 폴마다 상태를 적는다 (tools/emu.py 와 대조)
 *
 *   hosttest 대본.txt 최대틱 기록.txt|- [틱:이름.bmp ...]
 *   대본 줄: "틱 +키 [누름틱]"  또는 "틱 스캔16진"   (키: enter up down left right space esc a..z 0..9 f1..f10)
 *   기록 줄 (폴마다, EVERY 번에 한 번): 폴번호 틱 irq AX BX CX DX SI DI BP SP CS DS ES SS 메모리CRC CGA CRC
 *   틱 = 프레임 끝 폴 하나.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../cpu.h"
#include "../plat.h"
#ifdef ORVGA
#include "../orvga.h"
#endif

static FILE *trace;
static uint32_t maxticks;
static struct {
    uint32_t t;
    int n;
    int sc;
} ev[8192];
static int nev, evpos;
static struct {
    uint32_t t;
    char name[64];
} shots[512];
static int nshots;
static int every = 1;

static uint32_t crc_tab[256];
static void crc_init(void)
{
    uint32_t i, j, c;
    for (i = 0; i < 256; i++) {
        c = i;
        for (j = 0; j < 8; j++)
            c = (c & 1) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
        crc_tab[i] = c;
    }
}
static uint32_t crc32(const uint8_t *p, uint32_t n, uint32_t c)
{
    c = ~c;
    while (n--)
        c = crc_tab[(c ^ *p++) & 0xFF] ^ (c >> 8);
    return ~c;
}

/* CGA 모드 4/5 네 색 (tools/emu.py cga_rgb 와 같게) */
static void cga_pal(uint8_t pal[4][3])
{
    static const uint8_t base[16][3] = {{0, 0, 0}, {0, 0, 170}, {0, 170, 0}, {0, 170, 170}, {170, 0, 0}, {170, 0, 170},
        {170, 85, 0}, {170, 170, 170}, {85, 85, 85}, {85, 85, 255}, {85, 255, 85}, {85, 255, 255}, {255, 85, 85},
        {255, 85, 255}, {255, 255, 85}, {255, 255, 255}};
    int bg = or_cga_color & 15, p = (or_cga_color >> 5) & 1, in = (or_cga_color & 0x10) ? 8 : 0, k;
    int c[3];
    if (or_vmode == 5) {
        c[0] = 3; c[1] = 4; c[2] = 7;
    } else if (p) {
        c[0] = 3; c[1] = 5; c[2] = 7;
    } else {
        c[0] = 2; c[1] = 4; c[2] = 6;
    }
    memcpy(pal[0], base[bg], 3);
    for (k = 0; k < 3; k++)
        memcpy(pal[k + 1], base[c[k] + in], 3);
}

static void write_bmp(const char *name, const uint8_t *px, const uint8_t *rgb, int ncol)
{
    uint8_t hdr[54 + 1024];
    FILE *f = fopen(name, "wb");
    uint32_t sz = 54 + 1024 + 64000;
    int i, y;
    if (!f)
        return;
    memset(hdr, 0, sizeof hdr);
    hdr[0] = 'B'; hdr[1] = 'M';
    memcpy(hdr + 2, &sz, 4);
    hdr[10] = (uint8_t)((54 + 1024) & 0xFF); hdr[11] = (uint8_t)((54 + 1024) >> 8);
    hdr[14] = 40;
    hdr[18] = 320 & 0xFF; hdr[19] = 320 >> 8;
    hdr[22] = 200;
    hdr[26] = 1; hdr[28] = 8;
    for (i = 0; i < ncol; i++) {
        hdr[54 + i * 4] = rgb[i * 3 + 2];
        hdr[54 + i * 4 + 1] = rgb[i * 3 + 1];
        hdr[54 + i * 4 + 2] = rgb[i * 3];
    }
    fwrite(hdr, 1, sizeof hdr, f);
    for (y = 199; y >= 0; y--)
        fwrite(px + y * 320, 1, 320, f);
    fclose(f);
}

extern const uint8_t or_romfont[1024];
static void save_text_bmp(const char *name)
{
    static uint8_t px[640 * 200];
    static const uint8_t rgb16[16 * 3] = {0, 0, 0, 0, 0, 170, 0, 170, 0, 0, 170, 170, 170, 0, 0, 170, 0, 170, 170, 85, 0,
        170, 170, 170, 85, 85, 85, 85, 85, 255, 85, 255, 85, 85, 255, 255, 255, 85, 85, 255, 85, 255, 255, 255, 85,
        255, 255, 255};
    uint8_t hdr[54 + 1024];
    uint32_t sz = 54 + 1024 + 640 * 200;
    int r, c, y, b, i;
    FILE *f;
    for (r = 0; r < 25; r++)
        for (c = 0; c < 80; c++) {
            uint8_t ch = M[0xB8000 + (r * 80 + c) * 2], at = M[0xB8000 + (r * 80 + c) * 2 + 1];
            for (y = 0; y < 8; y++)
                for (b = 0; b < 8; b++)
                    px[(r * 8 + y) * 640 + c * 8 + b] = (uint8_t)(((or_romfont[(ch & 0x7F) * 8 + y] >> (7 - b)) & 1)
                                                               ? (at & 15) : (at >> 4) & 7);
        }
    if (!(f = fopen(name, "wb")))
        return;
    memset(hdr, 0, sizeof hdr);
    hdr[0] = 'B'; hdr[1] = 'M';
    memcpy(hdr + 2, &sz, 4);
    hdr[10] = (uint8_t)((54 + 1024) & 0xFF); hdr[11] = (uint8_t)((54 + 1024) >> 8);
    hdr[14] = 40;
    hdr[18] = 640 & 0xFF; hdr[19] = 640 >> 8;
    hdr[22] = 200;
    hdr[26] = 1; hdr[28] = 8;
    for (i = 0; i < 16; i++) {
        hdr[54 + i * 4] = rgb16[i * 3 + 2];
        hdr[54 + i * 4 + 1] = rgb16[i * 3 + 1];
        hdr[54 + i * 4 + 2] = rgb16[i * 3];
    }
    fwrite(hdr, 1, sizeof hdr, f);
    for (y = 199; y >= 0; y--)
        fwrite(px + y * 640, 1, 640, f);
    fclose(f);
}

static void save_bmp(const char *name)
{
    static uint8_t px[64000];
    uint8_t pal[4][3];
    int x, y;
    if (or_vmode != 4 && or_vmode != 5) {
        save_text_bmp(name);
        return;
    }
#ifdef ORVGA
    if (orvga_on) {
        if (getenv("ORBENCH")) {
            /* 합성 빠르기: ORBENCH 번 되풀이 */
            int n = atoi(getenv("ORBENCH")), i;
            clock_t c0 = clock();
            for (i = 0; i < n; i++)
                orvga_frame(px);
            printf("orvga_frame: %.3f ms\n", (double)(clock() - c0) * 1000.0 / CLOCKS_PER_SEC / n);
        }
        orvga_frame(px);
        write_bmp(name, px, orvga_palette(), 256);
        return;
    }
#endif
    for (y = 0; y < 200; y++)
        for (x = 0; x < 320; x++) {
            uint8_t b = M[0xB8000 + (y & 1) * 0x2000 + (y >> 1) * 80 + (x >> 2)];
            px[y * 320 + x] = (uint8_t)((b >> (6 - 2 * (x & 3))) & 3);
        }
    cga_pal(pal);
    write_bmp(name, px, &pal[0][0], 4);
}

static void finish(void)
{
    if (trace)
        fclose(trace);
    trace = 0;
    printf("done: %lu ticks, %lu polls, %lu cycles\n", (unsigned long)or_ticks, (unsigned long)or_npoll, (unsigned long)or_cyc);
    exit(0);
}

void plat_tick(uint32_t tick)
{
    int i;
    for (i = 0; i < nshots; i++)
        if (shots[i].t == tick)
            save_bmp(shots[i].name);
    if (tick >= maxticks)
        finish();
}

int plat_key(uint32_t tick)
{
    if (evpos < nev && ev[evpos].t <= tick)
        return ev[evpos++].sc;
    return -1;
}

/* 시험용 치트 (tools/emu.py cheat 와 같게): INF=1 목숨이 셋 아래면 다섯으로,
 * WARP=n 레벨이 n 보다 작으면 이 레벨 거리 [417A] 를 끝(0C6C)으로 */
static int cheat_inf, cheat_warp;
#define DSL ((LOADSEG + 0x20) * 16)
static void cheat(void)
{
    if (cheat_inf && M[DSL + 0x4178] < 3 && M[DSL + 0x4179] == 0)
        M[DSL + 0x4178] = 5;
    if (cheat_warp && M[DSL + 0x5368] < cheat_warp && M[DSL + 0x5369] == 0 && M[DSL + 0x5368] >= 1) {
        M[DSL + 0x417A] = 0x6C;
        M[DSL + 0x417B] = 0x0C;
    }
}

static void hook(int irq)
{
    uint32_t c1, c2;
    cheat();
    if (!trace || or_npoll % every)
        return;
    c1 = crc32(M, 0xA0000, 0);
    c2 = crc32(M + 0xB8000, 0x4000, 0);
    fprintf(trace, "%lu %lu %d %04X %04X %04X %04X %04X %04X %04X %04X %04X %04X %04X %04X %08X %08X\n",
            (unsigned long)or_npoll, (unsigned long)or_ticks, irq, AX, BX, CX, DX, SI, DI, BP, SP, CS_, DS_, ES_, SS_,
            (unsigned)c1, (unsigned)c2);
}

uint8_t plat_pit(void) { return 0x5A; }
void plat_spin(void) { }
void plat_mode(int mode)
{
#ifdef ORVGA
    orvga_mode(mode);
#else
    (void)mode;
#endif
}

void plat_fatal(const char *msg)
{
    if (trace)
        fclose(trace);
    printf("FATAL %s\n", msg);
    exit(1);
}

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
    fprintf(stderr, "unknown key %s\n", k);
    exit(2);
}

static int cmpev(const void *a, const void *b)
{
    const int *x = a, *y = b;
    if ((uint32_t)x[0] != (uint32_t)y[0])
        return (uint32_t)x[0] < (uint32_t)y[0] ? -1 : 1;
    return x[1] - y[1];
}

int main(int argc, char **argv)
{
    FILE *f;
    char ln[256];
    int i;
    if (argc < 4) {
        fprintf(stderr, "usage: hosttest script maxticks trace [tick:name.bmp...]\n");
        return 2;
    }
    crc_init();
    f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 2;
    }
    while (fgets(ln, sizeof ln, f)) {
        char *h = strchr(ln, '#'), k[64];
        unsigned t;
        int hold = 2;
        if (h)
            *h = 0;
        if (sscanf(ln, "%u %63s %d", &t, k, &hold) < 2 || !strcmp(k, "shot") || !strcmp(k, "quit"))
            continue;
        if (k[0] == '+') {
            int sc = keycode(k + 1);
            ev[nev].t = t; ev[nev].n = nev; ev[nev++].sc = sc;
            ev[nev].t = t + hold; ev[nev].n = nev; ev[nev++].sc = sc | 0x80;
        } else {
            ev[nev].t = t; ev[nev].n = nev; ev[nev++].sc = (int)strtol(k, 0, 16);
        }
    }
    fclose(f);
    qsort(ev, nev, sizeof ev[0], cmpev);
    maxticks = (uint32_t)atoi(argv[2]);
    if (strcmp(argv[3], "-"))
        trace = fopen(argv[3], "w");
    if (getenv("EVERY"))
        every = atoi(getenv("EVERY"));
    for (i = 4; i < argc && nshots < 512; i++) {
        char *c = strchr(argv[i], ':');
        if (!c)
            continue;
        shots[nshots].t = (uint32_t)atoi(argv[i]);
        snprintf(shots[nshots].name, sizeof shots[nshots].name, "%s", c + 1);
        nshots++;
    }
    or_poll_hook = hook;
    cheat_inf = getenv("INF") ? atoi(getenv("INF")) : 0;
    cheat_warp = getenv("WARP") ? atoi(getenv("WARP")) : 0;
#ifdef ORVGA
    if (!getenv("ORCGA"))
        orvga_load();
#endif
    or_init();
    or_run();
    printf("exit %d at tick %lu\n", or_exitcode, (unsigned long)or_ticks);
    finish();
    return 0;
}

#ifdef ORTRACE
/* 명령마다 추적: 처음 TRACEN 개를 _trace_host.txt 로 (tools/itrace.py 와 대조) */
void or_trace(uint32_t a)
{
    static FILE *tf;
    static long n, lim = -1;
    if (getenv("TRACEN") == 0)
        return;
    if (lim < 0) {
        lim = atol(getenv("TRACEN"));
        tf = fopen("_trace_host.txt", "w");
    }
    if (n++ >= lim) {
        if (tf) {
            fclose(tf);
            tf = 0;
        }
        return;
    }
    fprintf(tf, "%05X %04X %04X %04X %04X %04X %04X %04X %04X %04X %04X %04X\n", (unsigned)a, AX, BX, CX, DX, SI, DI, BP, SP,
            DS_, ES_, SS_);
}
#endif
