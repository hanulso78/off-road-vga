/* orvga.h - 256색 리마스터 (orvga.c) */
#ifndef ORVGA_H
#define ORVGA_H

#include <stdint.h>

extern int orvga_on;                    /* 자료가 있어 256색으로 보이나 */
int orvga_load(void);                   /* 자료 준비 (orvgatab.c 가 실행 파일 안에 있다) */
void orvga_mode(int mode);              /* 원판이 화면 모드를 바꿈 */
void orvga_frame(uint8_t *dst);         /* 320x200 256색 한 장 합성 */
int orvga_present(uint8_t *dst);        /* 합성해서 dst 로 (1 = 그렸다) */
const uint8_t *orvga_palette(void);     /* 768 바이트 (0..255) */
uint32_t orvga_palgen(void);            /* 팔레트가 바뀔 때마다 늘어남 */
void orvga_clear_row(int y);            /* CGA 한 줄을 통째로 0 으로 (30F0 빠른 판): 꼬리표도 지움 */

#endif
