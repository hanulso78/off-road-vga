/* ============================================================================
 *  orfast.c  -  자주 도는 원판 함수 두 개를 손으로 옮긴 빠른 판
 * ----------------------------------------------------------------------------
 *  에뮬레이터로 세어 보니 한 프레임 일의 3/4 이 이 둘 (+ 둘이 부르는 24FA 줄 주소) 이었다.
 *    2455  XOR 스프라이트: DS:[0036] 자료, DL 폭 바이트, CH 줄, [002C] 바이트 x, [002E] 줄, [003A] ror 수
 *    2987  산 능선: 높이표 DS:417E 를 [417A] 부터 한 점씩 XOR (80 바이트 x 4 점)
 *  끝난 뒤 레지스터, 메모리 (화면, 변수, 스택에 남는 24FA 복귀 주소까지), 8088 클럭 어림(CYC)이
 *  번역판(or_code.c)과 같다.  플래그는 돌아간 뒤 쓰이지 않는다 (번역판도 계산하지 않음).
 *  tools/asm2c.py FAST 가 함수 첫 명령 앞에서 부른다: 0 이 아니면 돌아갈 곳 (ret 끝낸 뒤).
 * ========================================================================== */
#include <string.h>
#include "cpu.h"
#include "plat.h"
#ifdef ORVGA
#include "orvga.h"
#endif

#define CODEL 0x089D0u

/* 24FA: bx = [667E + 2*bx] + [002C] (부르는 쪽이 넣은 복귀 주소가 SS:SP-2 에 남는다) */
static inline uint16_t rowaddr(uint16_t bx)
{
    return (uint16_t)(RW(DS_, (uint16_t)(bx + bx + 0x667E)) + RW(DS_, 0x2C));
}

static uint32_t fast_2455(void)
{
    uint8_t cl = RB(DS_, 0x3A), n = cl & 0x1F, k = n % 16;
    uint8_t rows = CH;
    SI = RW(DS_, 0x36);
    do {
        uint8_t cnt = DL;
        CYC(41 + 63);
        BX = rowaddr(RW(DS_, 0x2E));
        do {
            uint16_t a = RB(DS_, SI);
            if (n && k)
                a = (uint16_t)((a >> k) | (a << (16 - k)));
            AX = a;
            WW(ES_, BX, (uint16_t)(RW(ES_, BX) ^ a));
            SI++;
            BX++;
            CYC(106);
        } while (--cnt);
        DL = DH;
        WW(DS_, 0x2E, (uint16_t)(RW(DS_, 0x2E) + 1));
        CYC(55);
    } while (--rows);
    CL = cl;
    CH = 0;
    WW(SS_, (uint16_t)(SP - 2), 0x2460);
#ifdef ORVGA
    orvga_hook(CODEL + 0x247D);
#endif
    CYC(20);
    {
        uint16_t o = POP();
        return CODEL + o;
    }
}

static uint32_t fast_2987(void)
{
    uint16_t si = RW(DS_, 0x417A), col;
    uint16_t bx = BX;
    for (col = 0; col < 0x50; col++) {
        uint16_t m = 0x80;
        WW(DS_, 0x2C, col);
        CYC(36);
        for (;;) {
            bx = (uint16_t)(RW(DS_, (uint16_t)(RB(DS_, (uint16_t)(si + 0x417E)) * 2 + 0x667E)) + col);
            WW(ES_, bx, (uint16_t)(RW(ES_, bx) ^ m));
            si++;
            CYC(47 + 63 + 78 + 36);
            if (si == 0xC77) {
                si = 0;
                CYC(12);
            }
            if (m == 0x02) {
                m = 0x8000;
                break;
            }
            m >>= 2;
        }
        CYC(67);
    }
    /* 변수/레지스터 끝 모습: [417C]=8000, [002C]=50, AX = 마지막 [417C] 값 0002, CX = 0002 */
    WW(DS_, 0x417C, 0x8000);
    WW(DS_, 0x2C, 0x50);
    AX = 0x0002;
    CX = 0x0002;
    BX = bx;
    SI = si;
    WW(SS_, (uint16_t)(SP - 2), 0x29A3);
    CYC(20);
    {
        uint16_t o = POP();
        return CODEL + o;
    }
}

/* 2A42 난수: AL = PIT0 + [4DFA] + [4DFB], 그리고 [4DF9..4DFB] 를 한 칸씩 민다 (AH 그대로) */
static uint32_t fast_2a42(void)
{
    uint8_t a, b, s;
    io_out(0x43, 0);
    s = io_in(0x40);
    a = RB(DS_, 0x4DFA);
    b = RB(DS_, 0x4DFB);
    s = (uint8_t)(s + a + b);
    AL = s;
    WW(SS_, (uint16_t)(SP - 2), AX);          /* push ax 가 남긴 값 */
    WB(DS_, 0x4DF9, a);
    WB(DS_, 0x4DFA, b);
    WB(DS_, 0x4DFB, s);
    {
        uint16_t o = POP();
        return CODEL + o;
    }
}

/* 30F0 화면 21..179 줄 지우기 */
static uint32_t fast_30f0(void)
{
    uint16_t row;
    WW(DS_, 0x2C, 0);
    for (row = 0x15; row < 0xB4; row++) {
        uint16_t bx;
        int i;
        WW(DS_, 0x44, row);
        bx = rowaddr(row);
#ifdef ORVGA
        /* 256색판: 꼬리표를 바이트마다 따라가지 않고 줄째로 (orvga_clear_row) */
        if (LIN(ES_, bx) >= 0xB8000u && LIN(ES_, bx) + 0x50 <= 0xBC000u && (uint16_t)(bx + 0x4F) > bx) {
            memset(M + LIN(ES_, bx), 0, 0x50);
            orvga_clear_row(row);
            bx = (uint16_t)(bx + 0x50);
        } else
#endif
        for (i = 0; i < 0x50; i++, bx++)
            WB(ES_, bx, 0);
        BX = bx;
        CYC(41 + 63 + 12 + 0x50 * 37 + 67);
    }
    WW(DS_, 0x44, 0xB4);
    CX = 0;
    WW(SS_, (uint16_t)(SP - 2), 0x3103);
#ifdef ORVGA
    orvga_hook(CODEL + 0x3119);
#endif
    CYC(20);
    {
        uint16_t o = POP();
        return CODEL + o;
    }
}

uint32_t or_fast(uint32_t at)
{
    switch (at - CODEL) {
    case 0x2A42:
        return fast_2a42();
    case 0x30F0:
        return fast_30f0();
    case 0x2455:
        return fast_2455();
    case 0x2987:
        return fast_2987();
    }
    return 0;
}
