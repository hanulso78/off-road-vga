/* ============================================================================
 *  orrt.c  -  옮긴 코드의 런타임: 메모리 초기화, BIOS/DOS 흉내, 포트, 폴 지점
 * ----------------------------------------------------------------------------
 *  tools/emu.py 와 한 동작씩 같게 한다 (같은 키 대본이면 폴마다 레지스터와 메모리가 같다).
 *
 *  시계: Off-Road 는 인터럽트를 걸지 않는다.  주 되돌이가 한 프레임을 그리고 "mov cx,[004C]
 *        / loop $" 로 쉬고 BIOS 자판 버퍼(0040:001A/001C)를 직접 들여다본다.  옮긴 C 는
 *        프레임 끝(폴 지점)마다 틱 하나를 흘리고 그 틱까지 들어온 스캔 코드를 BIOS int 9
 *        흉내로 자판 버퍼에 넣는다.  int 16h AH=0 이 빈 버퍼를 읽으려 하면 키가 올 때까지 폴.
 *  화면: 처음 안내/등록 화면은 글자 모드 3 (int 10h AH=0Ah, int 21h AH=09h) -> B800 글자
 *        메모리에 흉내 낸다.  게임은 CGA 모드 4 에 직접 그린다.
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "cpu.h"
#include "plat.h"
#ifdef ORVGA
#include "orvga.h"
#endif

uint8_t M[MEMSIZE];
#ifndef ORVGA
uint8_t cga_dirty[208];
#endif
reg16_t cpu_a, cpu_b, cpu_c, cpu_d;
uint16_t SI, DI, BP, SP, CS_, DS_, ES_, SS_;
int CF, ZF, SF, OF, DF, IF_;

uint32_t or_ticks, or_npoll, or_nirq, or_cyc, or_spins;
int or_exitcode, or_vmode;
uint8_t or_port60, or_cga_color;
void (*or_poll_hook)(int irq);

#define MEMTOP 0x9FFF

extern const uint8_t or_img[];
extern const uint32_t or_img_len;
extern const uint16_t or_img_regs[6];
extern const uint8_t or_romfont[1024];
void or_run_code(void);

static int k_ctrl, k_shift, k_alt;
static jmp_buf exit_jmp;

/* 스캔 코드 -> 아스키 (tools/emu.py ASCII 와 같은 표) */
static uint8_t ascii_of[128];

static void make_ascii(void)
{
    static const char *rows[4] = {"1234567890-=", "qwertyuiop[]", "asdfghjkl;'`", "\\zxcvbnm,./"};
    static const int base[4] = {2, 0x10, 0x1E, 0x2B};
    int r, k;
    memset(ascii_of, 0, sizeof ascii_of);
    for (r = 0; r < 4; r++)
        for (k = 0; rows[r][k]; k++)
            ascii_of[base[r] + k] = (uint8_t)rows[r][k];
    ascii_of[0x01] = 27;
    ascii_of[0x0E] = 8;
    ascii_of[0x0F] = 9;
    ascii_of[0x1C] = 13;
    ascii_of[0x39] = 32;
}

static void w16(uint32_t a, uint16_t v)
{
    M[a] = (uint8_t)v;
    M[a + 1] = (uint8_t)(v >> 8);
}

static uint16_t r16(uint32_t a)
{
    return (uint16_t)(M[a] | M[a + 1] << 8);
}

static void text_clear(void)
{
    uint32_t a;
    for (a = 0xB8000; a < 0xBC000; a += 2) {
        MWB(a, 0x20);
        MWB(a + 1, 0x07);
    }
}

void or_init(void)
{
    static const char env[] = "PATH=C:\\\0COMSPEC=C:\\COMMAND.COM\0\0\x01\0C:\\OFFROAD.EXE";
    int n;
    make_ascii();
    memset(M, 0, sizeof M);
    memcpy(M + LOADSEG * 16, or_img, or_img_len);
    for (n = 0; n < 256; n++) {
        w16(n * 4, (uint16_t)(n * 4));
        w16(n * 4 + 2, BIOSSEG);
        M[BIOSSEG * 16 + n * 4] = 0xCD;
        M[BIOSSEG * 16 + n * 4 + 1] = (uint8_t)n;
        M[BIOSSEG * 16 + n * 4 + 2] = 0xCF;
        M[BIOSSEG * 16 + n * 4 + 3] = 0x90;
    }
    w16(0x410, 0x0021);
    w16(0x41A, 0x1E);
    w16(0x41C, 0x1E);
    w16(0x413, 640);
    M[0x449] = 3;
    w16(0x44A, 80);
    w16(0x463, 0x3D4);
    w16(0x480, 0x1E);
    w16(0x482, 0x3E);
    M[0xFFFFE] = 0xFC;
    memcpy(M + 0xFFA6E, or_romfont, 1024);
    M[PSPSEG * 16] = 0xCD;
    M[PSPSEG * 16 + 1] = 0x20;
    w16(PSPSEG * 16 + 2, MEMTOP + 1);
    w16(PSPSEG * 16 + 0x2C, 0x0F00);
    memcpy(M + 0xF000, env, sizeof env);
    M[PSPSEG * 16 + 0x80] = 0;
    M[PSPSEG * 16 + 0x81] = 0x0D;
    AX = BX = CX = DX = SI = DI = BP = 0;
    CS_ = SEG(or_img_regs[0]);
    SS_ = SEG(or_img_regs[2]);
    SP = or_img_regs[3];
    DS_ = ES_ = PSPSEG;
    CF = ZF = SF = OF = DF = 0;
    IF_ = 1;
    k_ctrl = k_shift = k_alt = 0;
    or_vmode = 3;
    or_cga_color = 0x30;
    or_ticks = or_npoll = or_nirq = or_cyc = or_spins = 0;
    or_port60 = 0;
    or_exitcode = 0;
    text_clear();
}

void or_run(void)
{
    if (setjmp(exit_jmp))
        return;
    or_run_code();
}

static void or_exit(int code)
{
    or_exitcode = code;
    longjmp(exit_jmp, 1);
}

/* ---- 잘못 ---- */
void or_fault(uint32_t at, int why)
{
    char b[120];
    static const char *what[] = {"?", "divide error", "hlt", "fell into data", "int 19h"};
    sprintf(b, "offroad: %s at %05X (tick %lu)", what[why % 5], (unsigned)at, (unsigned long)or_ticks);
    plat_fatal(b);
}

uint32_t or_unknown(uint32_t key)
{
    char b[120];
    sprintf(b, "offroad: jump to unknown %04X:%04X (tick %lu)", (unsigned)(CS_ - LOADSEG),
            (unsigned)(key - (uint32_t)(uint16_t)(CS_ - LOADSEG) * 16), (unsigned long)or_ticks);
    plat_fatal(b);
    return 0;
}

/* ---- BIOS int 9: 스캔 코드 -> 자판 버퍼 0040:001E-003D (tools/emu.py bios_key 와 같게) ---- */
static void bios_key(uint8_t sc)
{
    uint8_t k = sc & 0x7F, a;
    int up = sc & 0x80;
    uint16_t tail, nt;
    if (k == 0x1D) {
        k_ctrl = !up;
        return;
    }
    if (k == 0x2A || k == 0x36) {
        k_shift = !up;
        return;
    }
    if (k == 0x38) {
        k_alt = !up;
        return;
    }
    if (up || k == 0x3A || k == 0x45 || k == 0x46)
        return;
    a = ascii_of[k];
    if (k_alt)
        a = 0;
    else if (k_ctrl)
        a = (a >= 'a' && a <= 'z') ? (uint8_t)(a - 0x60) : a == 13 ? 10 : 0;
    else if (k_shift && a >= 'a' && a <= 'z')
        a = (uint8_t)(a - 0x20);
    tail = r16(0x41C);
    nt = (uint16_t)(tail + 2 >= 0x3E ? 0x1E : tail + 2);
    if (nt == r16(0x41A))
        return;                 /* 가득 (BIOS 는 삑) */
    w16(0x400 + tail, (uint16_t)((k << 8) | a));
    w16(0x41C, nt);
}

/* ---- 폴 지점: 틱 하나 + 그 틱까지 온 키를 BIOS 버퍼로 ---- */
int or_poll(void)
{
    int k;
    or_npoll++;
    or_ticks++;
    plat_tick(or_ticks);
    while ((k = plat_key(or_ticks)) >= 0) {
        or_port60 = (uint8_t)k;
        bios_key((uint8_t)k);
    }
    if (or_poll_hook)
        or_poll_hook(0);
    return 0;
}

int or_int16_wait(void)
{
    if (AH == 0 || AH == 0x10)
        return r16(0x41A) == r16(0x41C);
    return 0;
}

void or_spin(uint32_t n)
{
    or_spins += n;
    plat_spin();
}

/* ---- 포트 ---- */
void io_out(uint16_t port, uint8_t v)
{
    switch (port) {
    case 0x3D9:
        or_cga_color = v;
        return;
    }
}

void io_outw(uint16_t port, uint16_t v)
{
    io_out(port, (uint8_t)v);
    io_out((uint16_t)(port + 1), (uint8_t)(v >> 8));
}

uint8_t io_in(uint16_t port)
{
    switch (port) {
    case 0x60: return or_port60;
    case 0x40: return plat_pit();
    case 0x21: return 0xB8;
    }
    return 0xFF;
}

/* ---- 글자 모드 (2/3): 80x25, B800 글자+속성 ---- */
static int is_text(void)
{
    return or_vmode <= 3 || or_vmode == 7;
}

static void text_put(int col, int row, uint8_t ch, int attr)
{
    uint32_t a = 0xB8000 + (uint32_t)(row * 80 + col) * 2;
    MWB(a, ch);
    if (attr >= 0)
        MWB(a + 1, (uint8_t)attr);
}

static void text_scroll(void)
{
    uint32_t a;
    for (a = 0xB8000; a < 0xB8000 + 24 * 160; a++)
        MWB(a, M[a + 160]);
    for (a = 0xB8000 + 24 * 160; a < 0xB8000 + 25 * 160; a += 2) {
        MWB(a, 0x20);
        MWB(a + 1, 0x07);
    }
}

static void text_tty(uint8_t ch)
{
    int col = M[0x450], row = M[0x451];
    if (ch == 13)
        col = 0;
    else if (ch == 10)
        row++;
    else if (ch == 7)
        ;
    else if (ch == 8)
        col = col > 0 ? col - 1 : 0;
    else {
        text_put(col, row, ch, -1);
        if (++col >= 80) {
            col = 0;
            row++;
        }
    }
    if (row > 24) {
        text_scroll();
        row = 24;
    }
    M[0x450] = (uint8_t)col;
    M[0x451] = (uint8_t)row;
}

/* ---- BIOS 글자 (그림 모드 4/5): tools/emu.py gchar 와 같게 ---- */
static void gchar(uint8_t ch, uint8_t attr, int count, int tty)
{
    int col = M[0x450], row = M[0x451], k, y, b;
    const uint8_t *glyph;
    if (tty) {
        if (ch == 13)
            col = 0;
        else if (ch == 10)
            row = row + 1 > 24 ? 24 : row + 1;
        else if (ch == 7)
            ;
        else if (ch == 8)
            col = col > 0 ? col - 1 : 0;
        else {
            gchar(ch, attr, 1, 0);
            col++;
            if (col >= 40) {
                col = 0;
                row = row + 1 > 24 ? 24 : row + 1;
            }
        }
        M[0x450] = (uint8_t)col;
        M[0x451] = (uint8_t)row;
        return;
    }
    if (or_vmode != 4 && or_vmode != 5)
        return;
    glyph = M + 0xFFA6E + (ch & 0x7F) * 8;
    for (k = 0; k < count; k++) {
        int x = col + k;
        if (x >= 40)
            break;
        for (y = 0; y < 8; y++) {
            uint8_t g = glyph[y];
            uint16_t v = 0;
            int py = row * 8 + y;
            uint32_t a = 0xB8000 + (py & 1) * 0x2000 + (py >> 1) * 80 + x * 2;
            for (b = 0; b < 8; b++)
                if (g >> (7 - b) & 1)
                    v |= (uint16_t)((attr & 3) << (14 - 2 * b));
            if (attr & 0x80)
                v ^= (uint16_t)(M[a] << 8 | M[a + 1]);
            MWB(a, (uint8_t)(v >> 8));
            MWB(a + 1, (uint8_t)v);
        }
    }
}

static void int10(void)
{
    switch (AH) {
    case 0x00:
        or_vmode = AL & 0x7F;
        M[0x449] = (uint8_t)or_vmode;
        w16(0x450, 0);
        if (is_text())
            text_clear();
        else {
            uint32_t a;
            for (a = 0xB8000; a < 0xBC000; a++)
                MWB(a, 0);
        }
        or_cga_color = 0x30;
        plat_mode(or_vmode);
        break;
    case 0x05:
        M[0x462] = AL;
        break;
    case 0x0B:
        if (BH == 0)
            or_cga_color = (uint8_t)((or_cga_color & 0xE0) | (BL & 0x1F));
        else
            or_cga_color = (uint8_t)((or_cga_color & 0xDF) | ((BL & 1) << 5));
        break;
    case 0x0F:
        AX = (uint16_t)(((or_vmode <= 1 || or_vmode == 4 || or_vmode == 5) ? 0x2800 : 0x5000) | or_vmode);
        BH = 0;
        break;
    case 0x02:
        w16(0x450, DX);
        break;
    case 0x03:
        DX = r16(0x450);
        CX = 0x0607;
        break;
    case 0x09:
    case 0x0A:
        if (is_text()) {
            int col = M[0x450], row = M[0x451], k;
            for (k = 0; k < CX; k++) {
                int p = row * 80 + col + k;
                if (p >= 2000)
                    break;
                text_put(p % 80, p / 80, AL, AH == 0x09 ? BL : -1);
            }
        } else
            gchar(AL, BL, CX, 0);
        break;
    case 0x0E:
        if (is_text())
            text_tty(AL);
        else
            gchar(AL, BL, 1, 1);
        break;
    }
}

void do_int(int n)
{
    switch (n) {
    case 0x10: int10(); break;
    case 0x11: AX = 0x21; break;
    case 0x16:
        if (AH == 0 || AH == 0x10) {
            uint16_t h = r16(0x41A);
            if (h == r16(0x41C)) {
                or_fault(0, 0);
                return;
            }
            AX = r16(0x400 + h);
            w16(0x41A, (uint16_t)(h + 2 >= 0x3E ? 0x1E : h + 2));
        } else if (AH == 1 || AH == 0x11) {
            uint16_t h = r16(0x41A);
            if (h != r16(0x41C)) {
                AX = r16(0x400 + h);
                ZF = 0;
            } else
                ZF = 1;
        } else if (AH == 2)
            AL = (uint8_t)((k_ctrl ? 4 : 0) | (k_alt ? 8 : 0) | (k_shift ? 2 : 0));
        break;
    case 0x20: or_exit(0); break;
    case 0x21:
        if (AH == 0x09) {
            uint16_t o = DX;
            uint8_t c;
            while ((c = RB(DS_, o)) != '$') {
                if (is_text())
                    text_tty(c);
                else
                    gchar(c, 7, 1, 1);
                o++;
            }
            AL = 0x24;
        } else if (AH == 0x4C)
            or_exit(AL);
        break;
    }
}
