/* ============================================================================
 *  orvga.c  -  Off-Road 256색 리마스터 (모드 13h)
 * ----------------------------------------------------------------------------
 *  게임 코드는 원판 그대로 CGA 화면 메모리(M[B8000])에 그린다.  여기서는 그 화면과 게임 변수를
 *  읽어 한 프레임을 256색으로 새로 짓는다 (프레임 끝 폴 지점마다).
 *
 *    하늘      테마(레벨)별 그러데이션 + 먼 산 (산 능선 스크롤의 절반 빠르기) + 밤이면 별
 *    산        원판의 산 능선은 한 점 굵기 선 (2987: 높이표 DS:417E 를 [417A] 부터 한 칸에 한 점).
 *              같은 표로 능선 높이를 읽어 그 아래를 결 있는 산으로 채운다.
 *    땅        180-199 줄 초록 띠 -> 흙길 무늬, 프레임마다 속도 [004A] 만큼 흐른다 (땅 위 물체와 같이).
 *    스프라이트 원판은 XOR 로 그리고 같은 자리에 다시 XOR 해서 지운다 (2455).  그리기/지우기를
 *              짝으로 목록에 두었다가 tools/mkvga.py 가 미리 칠한 그림(orvgatab.c)으로 덧그린다.
 *    글자      24B0 (덮어쓰기) 로 그린 점에 '글자 몇째 줄' 꼬리표 -> 금속 그러데이션.
 *    그 밖     CGA 색 그대로 (밝은 초록/빨강/노랑).
 *
 *  갈고리 (tools/vhooks.txt -> asm2c 가 그 명령 앞에 VH(주소)):
 *    2455/247D 스프라이트 들어감/나감, 24B0/24D8 글자, 30F0/3119 화면 지우기,
 *    2AB0 땅 물체 움직임 (땅 무늬 스크롤), 0633 게임 프레임, 078B 제목 프레임
 * ========================================================================== */
#include <stdio.h>
#include <string.h>
#include "cpu.h"
#include "plat.h"
#include "orvga.h"

#define CODEL 0x089D0u                      /* 코드 세그먼트 089D 의 선형 (LOADSEG 기준) */
#define DSL ((LOADSEG + 0x20) * 16u)        /* 자료 세그먼트 0020 */
#define DSW(o) ((uint16_t)(M[DSL + (o)] | M[DSL + (o) + 1] << 8))

extern const uint8_t orv_pal[768];
extern const uint8_t orv_theme[][84 * 3];
extern const uint8_t orv_theme_stars[];
extern const int orv_nspr;
extern const struct orv_spr { uint16_t addr; uint8_t w, h; uint32_t off; } orv_spr[];
extern const uint8_t orv_art[];
extern const uint8_t orv_tex_mtn[64 * 128];
extern const uint8_t orv_tex_gnd[20 * 256];
extern const uint8_t orv_far_h[1024];
extern const int orv_nstars;
extern const uint16_t orv_stars[];
extern const uint8_t or_romfont[1024];

int orvga_on;
static uint8_t pal[768];
static uint32_t palgen = 1;
static int cur_theme = -1;

/* 글자 꼬리표: 0 = 아님, (색 묶음 + 1) << 4 | 글자 안 위치 0..15 (위 -> 아래) */
static uint8_t lab[64000];

static const uint8_t txg[4] = {2, 2, 0, 1};      /* CGA 색 -> 글자 램프 (빨강 0, 금 1, 초록 2) */

/* 그리는 중인 것 */
enum { C_NONE, C_SPR, C_TEXT, C_CLEAR };
static int ctx;
static int t_y0, t_h;

/* XOR 스프라이트 목록 */
#define NINST 160
static struct inst {
    uint16_t addr;
    int16_t x, y;               /* 화면 점 (x = 바이트*4 + 밀기) */
    uint8_t w, h;               /* 바이트 폭, 줄 */
    int16_t spr;                /* orv_spr 번호 (-1 없음) */
} inst[NINST];
static int ninst;

static uint32_t gscroll;        /* 땅 무늬 */
static int title;

/* ---- 자료 ---- */
static int find_spr(uint16_t a)
{
    int lo = 0, hi = orv_nspr - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (orv_spr[m].addr == a)
            return m;
        if (orv_spr[m].addr < a)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

static void set_theme(int t)
{
    if (t == cur_theme)
        return;
    cur_theme = t;
    memcpy(pal + 16 * 3, orv_theme[t], 84 * 3);
    palgen++;
}

int orvga_load(void)
{
    memcpy(pal, orv_pal, 768);
    cur_theme = -1;
    set_theme(0);
    orvga_on = 1;
    return 1;
}

const uint8_t *orvga_palette(void)
{
    return pal;
}

uint32_t orvga_palgen(void)
{
    return palgen;
}

void orvga_mode(int mode)
{
    (void)mode;
    ninst = 0;
    memset(lab, 0, sizeof lab);
    ctx = C_NONE;
}

/* ---- 갈고리 ---- */
static void spr_toggle(void)
{
    struct inst n;
    int k;
    n.addr = DSW(0x36);
    n.x = (int16_t)(DSW(0x2C) * 4 + (M[DSL + 0x3A] >> 1));     /* [003A] 낮은 바이트 = ror 수 */
    n.y = (int16_t)DSW(0x2E);
    n.w = DL;
    n.h = CH;
    for (k = 0; k < ninst; k++)
        if (inst[k].addr == n.addr && inst[k].x == n.x && inst[k].y == n.y && inst[k].w == n.w) {
            memmove(inst + k, inst + k + 1, (size_t)(ninst - k - 1) * sizeof inst[0]);
            ninst--;
            return;
        }
    n.spr = (int16_t)find_spr(n.addr);
    if (ninst == NINST) {
        memmove(inst, inst + 1, (NINST - 1) * sizeof inst[0]);
        ninst--;
    }
    inst[ninst++] = n;
}

void orvga_hook(uint32_t at)
{
    switch (at - CODEL) {
    case 0x2455:
        spr_toggle();
        ctx = C_SPR;
        break;
    case 0x24B0:
        ctx = C_TEXT;
        t_y0 = DSW(0x2E);
        t_h = CH ? CH : 1;
        break;
    case 0x30F0: {
        /* 21..179 줄 지움: 그 안의 스프라이트는 사라진다 */
        int k, j = 0;
        for (k = 0; k < ninst; k++)
            if (!(inst[k].y >= 0x15 && inst[k].y < 0xB4))
                inst[j++] = inst[k];
        ninst = j;
        ctx = C_CLEAR;
        break;
    }
    case 0x247D:
    case 0x24D8:
    case 0x3119:
        ctx = C_NONE;
        break;
    case 0x2AB0:
        gscroll += DSW(0x4A);
        break;
    case 0x0633:
        title = 0;
        break;
    case 0x078B:
        title = 1;
        break;
    }
}

/* CGA 화면 쓰기 (cpu.h MWB): 글자 꼬리표 */
void trk_wb(uint32_t a, uint8_t v)
{
    uint32_t o = a - 0xB8000u, oo;
    int y, xb, k;
    M[a] = v;
    oo = o & 0x1FFF;
    /* 꼬리표는 글자를 쓸 때와 화면을 지울 때만 바꾼다: 능선/스프라이트 XOR 가 글자를 지나가도
     * 꼬리표(원래 글자 색)는 남아, 지나간 뒤 글자가 제 색으로 돌아온다 */
    if (oo >= 8000 || (ctx != C_TEXT && ctx != C_CLEAR))
        return;
    y = (int)(oo / 80) * 2 + (o >= 0x2000);
    xb = (int)(oo % 80);
    for (k = 0; k < 4; k++) {
        int nv = (v >> (6 - 2 * k)) & 3, p = y * 320 + xb * 4 + k;
        if (ctx == C_TEXT && nv) {
            int r = y - t_y0;
            if (r < 0)
                r = 0;
            if (r >= t_h)
                r = t_h - 1;
            lab[p] = (uint8_t)(((txg[nv] + 1) << 4) | (t_h > 1 ? r * 15 / (t_h - 1) : 7));
        } else if (!nv)
            lab[p] = 0;
    }
}

/* ---- 합성 ---- */
static inline int cga_px(int x, int y)
{
    uint8_t b = M[0xB8000 + (y & 1) * 0x2000 + (y >> 1) * 80 + (x >> 2)];
    return (b >> (6 - 2 * (x & 3))) & 3;
}

/* 스프라이트가 화면에 아직 있나 (원판이 따로 지운 경우 목록에서 뺀다) */
static int inst_alive(const struct inst *s)
{
    int W = s->w * 4, y, x, on = 0, off = 0;
    for (y = 0; y < s->h; y += 2) {
        int sy = s->y + y;
        if (sy < 0 || sy >= 200)
            continue;
        for (x = y & 2 ? 1 : 0; x < W; x += 2) {
            int sx = s->x + x, sv;
            uint8_t b;
            if (sx < 0 || sx >= 320)
                continue;
            b = M[DSL + s->addr + y * s->w + (x >> 2)];
            sv = (b >> (6 - 2 * (x & 3))) & 3;
            if (!sv)
                continue;
            if (cga_px(sx, sy))
                on++;
            else
                off++;
        }
    }
    return on + off == 0 || off * 10 < (on + off) * 6;
}

static const uint8_t cga_fallback[4] = {0, 10, 12, 14};
#define TEXT_SHADOW (100 + 16 * 3 + 0)          /* 강철 램프 가장 어두운 색 */
static int ridge[320];

/* 빠른 합성용 표 */
static int tabs_ok;
static uint8_t ex4[256][4];             /* CGA 바이트 -> 점 넷 */
static int8_t texo[64 * 128];           /* 산 결 흔들림 */
static int16_t dysh[200];               /* 능선 아래 깊이 -> 밝기 */
static uint8_t fardiv[64][200];         /* 먼 산 (높이, 깊이) -> 색 */
static uint8_t fhx[320];
static int16_t ftop[320];
static uint8_t grass0[512], grass1[512], gndrow[20][512];   /* 두 번 이어 붙여 memcpy 320 */
static uint8_t skycol[200];
static uint8_t texm[64 * 128];
static uint8_t mcol[200][16];           /* (능선 아래 깊이, 결) -> 색 */
/* 하늘+먼 산 넓은 그림 (줄 20..179, 폭 1024 + 320 이어 붙임): 줄마다 memcpy */
#define FARW (1024 + 320)
static uint8_t farimg[160][FARW];
/* 산 몸 세계 그림: 세계 열 w (능선 높이표 칸 0..C76) 마다, 앞 320 열은 끝에 한 번 더 (감김 없이 memcpy).
 * 능선 높이가 바뀐 열만 다시 칠한다 (레벨마다 원판이 높이표를 새로 만든다) */
#define NWCOL 0xC77
#define WIMGW (NWCOL + 320)
static uint8_t wimg[160][WIMGW];
static uint8_t wcol_r[NWCOL];           /* 칠할 때의 능선 (0 = 아직) */

static void wcol_paint(int w, int r)
{
    int y, u = w & 127;
    for (y = 20; y < 0xB4; y++) {
        uint8_t c = y < r ? 0 : y == r ? 75 : y == r + 1 ? 74 : mcol[y - r][texm[(y & 63) * 128 + u]];
        wimg[y - 20][w] = c;
        if (w < 320)
            wimg[y - 20][w + NWCOL] = c;
    }
    wcol_r[w] = (uint8_t)r;
}

/* 능선 단조 조각: 줄마다 산이 덮는 구간 (r(x) <= y) 의 경계만 옮긴다 */
static struct piece {
    int16_t a, b, dir, c;
} pcs[320];
static int npcs;


static void make_tabs(void)
{
    int i, k;
    for (i = 0; i < 256; i++)
        for (k = 0; k < 4; k++)
            ex4[i][k] = (uint8_t)((i >> (6 - 2 * k)) & 3);
    for (i = 0; i < 64 * 128; i++)
        texo[i] = (int8_t)((orv_tex_mtn[i] - 8) / 2);
    for (i = 0; i < 200; i++)
        dysh[i] = (int16_t)(15 - i / 3);
    for (i = 0; i < 64; i++)
        for (k = 0; k < 200; k++)
            fardiv[i][k] = (uint8_t)(48 + k * 7 / (i + 62));
    for (i = 0; i < 512; i++) {
        grass0[i] = (uint8_t)(92 + ((i * 5 + (i >> 2)) % 4));
        grass1[i] = (uint8_t)(92 + ((i >> 1) & 1));
        for (k = 2; k < 20; k++)
            gndrow[k][i] = (uint8_t)(76 + orv_tex_gnd[k * 256 + (i & 255)]);
    }
    for (i = 0; i < 200; i++)
        skycol[i] = (uint8_t)(16 + (i < 20 ? 0 : (i - 20) * 32 / 160));
    for (i = 0; i < 64 * 128; i++)
        texm[i] = orv_tex_mtn[i];
    for (i = 0; i < 200; i++)
        for (k = 0; k < 16; k++) {
            int sh = 15 - i / 3 + (k - 8) / 2;
            mcol[i][k] = (uint8_t)(sh > 15 ? 73 : 56 + (sh < 0 ? 0 : sh));
        }
    for (i = 0; i < FARW; i++) {
        int fh = orv_far_h[i & 1023], t = 118 - fh;
        for (k = 20; k < 0xB4; k++)
            farimg[k - 20][i] = k >= t ? fardiv[fh][k - t] : skycol[k];
    }
    memset(wcol_r, 0, sizeof wcol_r);
    tabs_ok = 1;
}

void orvga_frame(uint8_t *dst)
{
    int x, y, k, th, lv;
    uint16_t smt = DSW(0x417A);
    int scroll_far = smt / 2;
    lv = DSW(0x5368);
    th = (title || lv < 1 || lv > 8) ? 0 : lv;
    set_theme(th);

    /* 능선: 높이표 [417E + (417A + x) mod C77], 화면에 실제로 그 점이 있을 때만 */
    {
        int ok = 0;
        int si = smt % 0xC77;
        for (x = 0; x < 320; x++, si = si + 1 == 0xC77 ? 0 : si + 1) {
            int r = M[DSL + 0x417E + si];
            ridge[x] = (r >= 0x15 && r < 0xB4) ? r : 999;
            if (ridge[x] != 999 && cga_px(x, r))
                ok++;
        }
        /* 글자/스프라이트가 덮은 열도 있으니 대부분 맞으면 표 전체를 믿는다 */
        if (ok < 320 * 4 / 10)
            for (x = 0; x < 320; x++)
                ridge[x] = 999;
    }

    if (!tabs_ok)
        make_tabs();
    /* 1) 배경: 줄마다 하늘+먼 산 memcpy, 그 위에 산이 덮는 구간만 산 세계 그림에서 memcpy */
    {
        int fo = (scroll_far / 2) & 1023, s0 = smt % NWCOL, hasr = ridge[0] != 999;
        npcs = 0;
        if (hasr) {
            int w = s0;
            for (x = 0; x < 320; x++, w = w + 1 == NWCOL ? 0 : w + 1)
                if (wcol_r[w] != ridge[x])
                    wcol_paint(w, ridge[x]);
            x = 0;
            while (x < 320) {
                struct piece *p = &pcs[npcs++];
                int dir = 0;
                p->a = (int16_t)x;
                x++;
                while (x < 320) {
                    int d = ridge[x] > ridge[x - 1] ? 1 : ridge[x] < ridge[x - 1] ? -1 : 0;
                    if (d && dir && d != dir)
                        break;
                    if (d)
                        dir = d;
                    x++;
                }
                p->b = (int16_t)(x - 1);
                p->dir = (int16_t)dir;
                p->c = (int16_t)(dir >= 0 ? p->a : p->b + 1);
            }
        }
        for (y = 20; y < 0xB4; y++) {
            uint8_t *d = dst + y * 320;
            const uint8_t *wr = wimg[y - 20] + s0;
            memcpy(d, farimg[y - 20] + fo, 320);
            for (k = 0; k < npcs; k++) {
                struct piece *p = &pcs[k];
                int x0, x1;
                if (p->dir >= 0) {
                    while (p->c <= p->b && ridge[p->c] <= y)
                        p->c++;
                    x0 = p->a;
                    x1 = p->c;
                } else {
                    while (p->c > p->a && ridge[p->c - 1] <= y)
                        p->c--;
                    x0 = p->c;
                    x1 = p->b + 1;
                }
                if (x1 > x0)
                    memcpy(d + x0, wr + x0, (size_t)(x1 - x0));
            }
        }
    }
    /* 2) 점수판, 땅 */
    for (y = 0; y < 20; y++)
        memset(dst + y * 320, y == 19 ? 100 + 16 * 3 + 9 : y == 18 ? 100 + 16 * 3 + 2 : 100 + 16 * 3 + (y < 2 ? 3 : 1), 320);
    for (y = 0xB4; y < 200; y++) {
        int gy = y - 0xB4;
        const uint8_t *tg = gy == 0 ? grass0 : gy == 1 ? grass1 : gndrow[gy];
        memcpy(dst + y * 320, tg + (gscroll & 255), 320);
    }
    /* 3) CGA 화면에서 0 이 아닌 점: 글자 / 그 밖 (땅 띠의 초록은 땅) */
    for (y = 0; y < 200; y++) {
        const uint8_t *src = M + 0xB8000 + (y & 1) * 0x2000 + (y >> 1) * 80;
        const uint8_t *L = lab + y * 320;
        uint8_t *d = dst + y * 320;
        int gnd = y >= 0xB4;
        for (x = 0; x < 80; x++) {
            uint8_t b;
            int k;
            if ((x & 3) == 0 && !(src[x] | src[x + 1] | src[x + 2] | src[x + 3])) {
                x += 3;
                continue;
            }
            b = src[x];
            if (!b)
                continue;
            for (k = 0; k < 4; k++) {
                int v = ex4[b][k], px = x * 4 + k;
                if (!v)
                    continue;
                if (L[px]) {
                    d[px] = (uint8_t)(244 + ((L[px] >> 4) - 1) * 4 + (L[px] & 15) / 4);
                    /* 놀이 화면 위 글자: 오른쪽 아래 1점 그림자 (하늘/산과 떨어지게) */
                    if (y >= 20 && y < 199 && px < 319 && !L[px + 321])
                        d[px + 321] = TEXT_SHADOW;
                } else if (gnd ? v != 1 : y != ridge[px])
                    d[px] = cga_fallback[v];
            }
        }
    }
    /* 별 (밤 테마): 하늘 점에만 */
    if (orv_theme_stars[th])
        for (k = 0; k < orv_nstars; k++) {
            int sx = (orv_stars[k * 3] - scroll_far / 4) & 511, sy = orv_stars[k * 3 + 1];
            if (sx < 320 && sy < ridge[sx] && dst[sy * 320 + sx] >= 16 && dst[sy * 320 + sx] < 48)
                dst[sy * 320 + sx] = (uint8_t)(96 + orv_stars[k * 3 + 2]);
        }

    /* 스프라이트 */
    for (k = 0; k < ninst; k++) {
        struct inst *s = &inst[k];
        int W = s->w * 4;
        if (!inst_alive(s)) {
            memmove(inst + k, inst + k + 1, (size_t)(ninst - k - 1) * sizeof inst[0]);
            ninst--;
            k--;
            continue;
        }
        for (y = 0; y < s->h; y++) {
            int sy = s->y + y;
            if (sy < 0 || sy >= 200)
                continue;
            for (x = 0; x < W; x++) {
                int sx = s->x + x;
                uint8_t c;
                if (sx < 0 || sx >= 320)
                    continue;
                if (s->spr >= 0) {
                    c = orv_art[orv_spr[s->spr].off + y * W + x];
                } else {
                    uint8_t b = M[DSL + s->addr + y * s->w + (x >> 2)];
                    c = cga_fallback[(b >> (6 - 2 * (x & 3))) & 3];
                }
                if (c)
                    dst[sy * 320 + sx] = c;
            }
        }
    }

    /* 제목 화면: 만든이 */
    if (title) {
        static const char msg[] = "VGA REMASTER BY IN-HAK MIN";
        int n = (int)sizeof msg - 1, x0 = (320 - n * 8) / 2, y0 = 188, i, b;
        int pass;
        for (pass = 0; pass < 2; pass++)
            for (i = 0; i < n; i++)
                for (y = 0; y < 8; y++) {
                    uint8_t g = or_romfont[(msg[i] & 0x7F) * 8 + y];
                    for (b = 0; b < 8; b++)
                        if (g >> (7 - b) & 1) {
                            if (pass == 0) {
                                if (y0 + y + 1 < 200)
                                    dst[(y0 + y + 1) * 320 + x0 + i * 8 + b + 1] = 76;
                            } else
                                dst[(y0 + y) * 320 + x0 + i * 8 + b] = (uint8_t)(244 + 4 + y / 2);
                        }
                }
    }
}

int orvga_present(uint8_t *dst)
{
    orvga_frame(dst);
    return 1;
}
