/* plat.h - 옮긴 프로그램 런타임(orrt.c)이 플랫폼(도스판 sys_dos.c / 시험판 hosttest.c)에 바라는 것 */
#ifndef PLAT_H
#define PLAT_H

#include <stdint.h>

/* 프레임 끝(폴 지점)에서 틱 하나가 흐를 때 (도스판: 원판 PC 속도만큼 기다리고 화면 내보내기,
 * 시험판: 찍기/끝) */
void plat_tick(uint32_t tick);
/* CPU 속도 빈 되돌이 (or_cyc 에 이미 더함): 도스판은 그만큼 기다린다 */
void plat_spin(void);
/* 지금 (tick 까지) 들어온 자판 스캔 코드 하나 (없으면 -1, 뗌은 |0x80) */
int plat_key(uint32_t tick);
/* PIT 0 계수기 읽기 (원판은 난수에 섞는다) */
uint8_t plat_pit(void);
/* 원판이 화면 모드를 바꿈 (int 10h AH=0) */
void plat_mode(int mode);
void plat_fatal(const char *msg);

/* orrt.c */
void or_init(void);
void or_run(void);                      /* 프로그램이 끝나면 (int 20h / retf PSP:0) 돌아온다 */
extern uint32_t or_ticks;               /* 흐른 틱 (= 프레임 끝 폴) */
extern uint32_t or_npoll;               /* 폴 지점 지난 횟수 */
extern uint32_t or_nirq;
extern uint32_t or_cyc;                 /* 8088 클럭 어림 (빈 되돌이 빼고) */
extern uint32_t or_spins;               /* 빈 되돌이 (loop $) 돈 횟수 */
extern int or_exitcode;
extern uint8_t or_port60;
extern uint8_t or_cga_color;            /* 3D9 (int 10h AH=0Bh 로 바뀜) */
extern int or_vmode;
/* 시험판이 폴마다 부르는 갈고리 (상태 기록) */
extern void (*or_poll_hook)(int irq);

#endif
