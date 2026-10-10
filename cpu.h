/* ============================================================================
 *  cpu.h  -  옮긴 코드(or_code.c)가 쓰는 8086 상태와 메모리
 * ----------------------------------------------------------------------------
 *  원본은 Off-Road (Montsoft 1988, IBM CGA) 의 OFFROAD.EXE (손 어셈블리).
 *  옮긴 C 는 함수 하나이고, 레지스터는 전역 변수, 메모리는 실모드 주소 그대로인 평면
 *  배열 M[] (1MB + 64KB) 이다.  세그먼트:오프셋 계산, 16비트 넘침, 스택 내용까지 원본과
 *  같아서 에뮬레이터(tools/emu.py)와 메모리를 통째로 대조할 수 있다.
 *
 *  B8000-BBFFF : CGA 화면 메모리 (M[] 그대로; 글자 모드면 80x25 글자+속성).
 *
 *  시간: 원판은 인터럽트 없이 CPU 속도로 돈다.  옮긴 코드는 블록마다 8088 클럭 어림을
 *  CYC() 로 더하고 (or_cyc), 프레임 끝 폴 지점에서 or_poll() 이 틱 하나를 흘린다.
 * ========================================================================== */
#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <string.h>

#define LOADSEG 0x1000
#define PSPSEG (LOADSEG - 0x10)
#define BIOSSEG 0xF000
#define SEG(x) ((uint16_t)(LOADSEG + (x)))
#define MEMSIZE 0x110000
/* dispatch 열쇠: LOADSEG 기준 선형 주소 */
#define KEY(s, o) ((((uint32_t)(uint16_t)((s) - LOADSEG)) << 4) + (uint16_t)(o))

extern uint8_t M[MEMSIZE];

typedef union {
    uint16_t x;
    struct {
        uint8_t l, h;
    } b;
} reg16_t;

extern reg16_t cpu_a, cpu_b, cpu_c, cpu_d;
extern uint16_t SI, DI, BP, SP, CS_, DS_, ES_, SS_;
extern int CF, ZF, SF, OF, DF, IF_;

#define AX cpu_a.x
#define AL cpu_a.b.l
#define AH cpu_a.b.h
#define BX cpu_b.x
#define BL cpu_b.b.l
#define BH cpu_b.b.h
#define CX cpu_c.x
#define CL cpu_c.b.l
#define CH cpu_c.b.h
#define DX cpu_d.x
#define DL cpu_d.b.l
#define DH cpu_d.b.h

#define LIN(s, o) (((uint32_t)(uint16_t)(s) << 4) + (uint16_t)(o))

/* 플래그 낱말 (pushf): C Z S O I D 만 (에뮬레이터도 pushf 뒤 같은 가면을 씌운다) */
#define GETFLAGS() ((uint16_t)(0x0002 | CF | (ZF << 6) | (SF << 7) | (IF_ << 9) | (DF << 10) | (OF << 11)))
#define SETFLAGS(f) do { uint16_t f_ = (f); CF = f_ & 1; ZF = (f_ >> 6) & 1; SF = (f_ >> 7) & 1; \
        IF_ = (f_ >> 9) & 1; DF = (f_ >> 10) & 1; OF = (f_ >> 11) & 1; } while (0)

/* 런타임 (orrt.c) */
void io_out(uint16_t port, uint8_t v);
void io_outw(uint16_t port, uint16_t v);
uint8_t io_in(uint16_t port);
void do_int(int n);
void or_fault(uint32_t at, int why);
uint32_t or_unknown(uint32_t key);
int or_poll(void);
int or_int16_wait(void);                 /* int 16h AH=0 인데 BIOS 자판 버퍼가 비었나 */

/* 8088 4.77MHz 클럭 어림 (도스판은 이만큼 실제 시간이 흐르게 맞춘다) */
extern uint32_t or_cyc;
#define CYC(n) (or_cyc += (n))
/* 제자리 빈 되돌이 "loop $": CX 번 (0 이면 65536 번) 돌고 CX = 0 */
void or_spin(uint32_t n);
uint32_t or_fast(uint32_t at);          /* orfast.c: 손으로 옮긴 빠른 판 (0 = 없음) */
#define SPIN() do { or_spin(CX ? CX : 0x10000u); CX = 0; } while (0)

#ifdef ORVGA
/* 256색판: 그리는 명령 앞 갈고리 (tools/vhooks.txt -> VH) 와 CGA 화면 쓰기 가로채기 (orvga.c) */
void orvga_hook(uint32_t at);
#define VH(a) orvga_hook(a)
void trk_wb(uint32_t a, uint8_t v);
#define IS_TRK(a) ((uint32_t)((a) - 0xB8000u) < 0x4000u)
#define MWB(a, v) do { uint32_t a__ = (a); if (IS_TRK(a__)) trk_wb(a__, (v)); else M[a__] = (v); } while (0)
#else
#define VH(a) ((void)0)
/* CGA 판: 화면 메모리 80 바이트 줄마다 '바뀜' 표시 (도스판이 바뀐 줄만 옮긴다) */
extern uint8_t cga_dirty[208];
#define MWB(a, v) do { uint32_t a__ = (a); M[a__] = (v);         if ((uint32_t)(a__ - 0xB8000u) < 0x4000u) cga_dirty[(a__ - 0xB8000u) / 80] = 1; } while (0)
#endif

static inline __attribute__((always_inline)) uint8_t RB(uint16_t s, uint16_t o)
{
    return M[LIN(s, o)];
}

static inline __attribute__((always_inline)) uint16_t RW(uint16_t s, uint16_t o)
{
    return (uint16_t)(M[LIN(s, o)] | (M[LIN(s, (uint16_t)(o + 1))] << 8));
}

static inline __attribute__((always_inline)) void WB(uint16_t s, uint16_t o, uint8_t v)
{
    MWB(LIN(s, o), v);
}

static inline __attribute__((always_inline)) void WW(uint16_t s, uint16_t o, uint16_t v)
{
    MWB(LIN(s, o), (uint8_t)v);
    MWB(LIN(s, (uint16_t)(o + 1)), (uint8_t)(v >> 8));
}

static inline __attribute__((always_inline)) void PUSH(uint16_t v)
{
    SP -= 2;
    WW(SS_, SP, v);
}

static inline __attribute__((always_inline)) uint16_t POP(void)
{
    uint16_t v = RW(SS_, SP);
    SP += 2;
    return v;
}

#define STEP(w) (DF ? (uint16_t)-(w) : (uint16_t)(w))

#ifdef ORVGA
extern uint32_t vga_src;        /* 256색판: movs 로 옮기는 값이 온 곳 (선형, 0 = 없음) */
#define MOVS_ON(a) (vga_src = (a))
#define MOVS_OFF() (vga_src = 0)
#else
#define MOVS_ON(a) ((void)0)
#define MOVS_OFF() ((void)0)
#endif

static inline __attribute__((always_inline)) void MOVSB(uint16_t sseg)
{
    MOVS_ON(LIN(sseg, SI));
    WB(ES_, DI, RB(sseg, SI));
    MOVS_OFF();
    SI += STEP(1);
    DI += STEP(1);
}

static inline __attribute__((always_inline)) void MOVSW(uint16_t sseg)
{
    MOVS_ON(LIN(sseg, SI));
    WW(ES_, DI, RW(sseg, SI));
    MOVS_OFF();
    SI += STEP(2);
    DI += STEP(2);
}

static inline __attribute__((always_inline)) void REP_MOVSB(uint16_t sseg)
{
    while (CX) {
        MOVSB(sseg);
        CX--;
    }
}

static inline __attribute__((always_inline)) void STOSB(void)
{
    WB(ES_, DI, AL);
    DI += STEP(1);
}

static inline __attribute__((always_inline)) void STOSW(void)
{
    WW(ES_, DI, AX);
    DI += STEP(2);
}

static inline __attribute__((always_inline)) void LODSB(uint16_t sseg)
{
    AL = RB(sseg, SI);
    SI += STEP(1);
}

static inline __attribute__((always_inline)) void LODSW(uint16_t sseg)
{
    AX = RW(sseg, SI);
    SI += STEP(2);
}

/* 명령마다 추적 (-DORTRACE: 시험판 대조용) */
#ifdef ORTRACE
void or_trace(uint32_t a);
#define TR(a) or_trace(a)
#else
#define TR(a) ((void)0)
#endif

#endif
