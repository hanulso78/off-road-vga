# -*- coding: utf-8 -*-
"""256색 리마스터 자료 -> orvgatab.c

   python tools/mkvga.py

   - 팔레트: 0-15 EGA, 16-99 테마 (하늘 32 / 먼 산 8 / 산 몸 16 / 능선 4 / 땅 20 / 별 4),
             100-255 재질 램프 16 단 x 9 (빨강 도장, 금, 초록, 강철, 불, 돌, 나무, 국방, 보라) + 글자 12
   - 테마: 레벨 0(제목)~8 마다 하늘/산/땅 색 (팔레트만 바뀐다)
   - 스프라이트 그림: 원판 CGA 스프라이트(tools/sprites.txt: tools/sprites.py 가 모은 주소)를 재질 램프로
     입체 칠 (위가 밝고, 윗가장자리 빛, 아랫가장자리 그늘).  둘러싸인 검은 점(타이어, 창)은 어둡게 채운다.
   - 무늬: 산 몸 (128x64), 땅 (256x20), 먼 산 높이 (1024), 별 (512x160 성긴 점)
"""
import sys, os, glob, math, random, colorsys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import image

D = 0x20 * 16
OUT = os.path.join(image.ROOT, 'orvgatab.c')
R = random.Random(1988)

EGA = [(0, 0, 0), (0, 0, 170), (0, 170, 0), (0, 170, 170), (170, 0, 0), (170, 0, 170), (170, 85, 0), (170, 170, 170),
       (85, 85, 85), (85, 85, 255), (85, 255, 85), (85, 255, 255), (255, 85, 85), (255, 85, 255), (255, 255, 85), (255, 255, 255)]


def lerp(a, b, t):
    return tuple(int(round(a[k] + (b[k] - a[k]) * t)) for k in range(3))


def ramp(stops, n):
    """stops: [(t, rgb)...] -> n 색"""
    out = []
    for i in range(n):
        t = i / (n - 1)
        for k in range(len(stops) - 1):
            if stops[k][0] <= t <= stops[k + 1][0]:
                u = (t - stops[k][0]) / max(1e-9, stops[k + 1][0] - stops[k][0])
                out.append(lerp(stops[k][1], stops[k + 1][1], u))
                break
    return out


# ---- 재질 램프 (어두움 -> 밝음, 16 단) ----
MAT = {
    'red':    [(0, (40, 4, 8)), (0.45, (170, 20, 24)), (0.8, (250, 80, 60)), (1, (255, 220, 200))],
    'gold':   [(0, (50, 28, 0)), (0.45, (190, 130, 10)), (0.8, (255, 215, 60)), (1, (255, 255, 210))],
    'green':  [(0, (0, 30, 10)), (0.5, (30, 170, 60)), (0.85, (130, 255, 120)), (1, (230, 255, 220))],
    'steel':  [(0, (20, 24, 34)), (0.5, (110, 120, 140)), (0.85, (200, 210, 225)), (1, (255, 255, 255))],
    'fire':   [(0, (60, 0, 0)), (0.3, (200, 30, 0)), (0.6, (255, 140, 0)), (0.85, (255, 230, 60)), (1, (255, 255, 230))],
    'stone':  [(0, (30, 22, 16)), (0.5, (120, 100, 80)), (0.85, (190, 175, 150)), (1, (240, 230, 210))],
    'wood':   [(0, (40, 20, 6)), (0.5, (150, 90, 35)), (0.85, (220, 165, 90)), (1, (255, 230, 170))],
    'olive':  [(0, (18, 24, 8)), (0.5, (90, 110, 40)), (0.85, (165, 185, 95)), (1, (230, 240, 190))],
    'purple': [(0, (25, 0, 35)), (0.5, (130, 30, 170)), (0.85, (220, 110, 255)), (1, (255, 220, 255))],
}
MATS = ['red', 'gold', 'green', 'steel', 'fire', 'stone', 'wood', 'olive', 'purple']
MBASE = {m: 100 + 16 * k for k, m in enumerate(MATS)}
TEXT_BASE = 244          # 글자 12: 빨강 4, 금 4, 초록 4 (위 -> 아래 그러데이션)

# ---- 테마 (레벨 0..8) ----
#   하늘: 위 -> 아래 32 단, 먼 산 8, 산 몸 16 (능선 쪽 밝음 -> 아래 어두움), 능선 4, 땅 20, 별 4
THEMES = [
    # 0 제목: 노을
    dict(sky=[(0, (20, 10, 60)), (0.55, (150, 50, 110)), (0.85, (250, 130, 70)), (1, (255, 200, 110))],
         far=((90, 50, 110), (130, 70, 120)), mtn=((170, 80, 70), (60, 25, 40)), ridge=(255, 170, 120),
         ground=((150, 100, 50), (90, 55, 25)), grass=(80, 140, 40), stars=0),
    # 1 사막 낮
    dict(sky=[(0, (30, 80, 190)), (0.6, (90, 160, 235)), (1, (210, 230, 250))],
         far=((150, 160, 200), (175, 180, 210)), mtn=((205, 140, 80), (120, 70, 35)), ridge=(255, 220, 160),
         ground=((200, 150, 90), (130, 90, 45)), grass=(110, 160, 50), stars=0),
    # 2 붉은 바위 협곡 (늦은 오후)
    dict(sky=[(0, (40, 70, 160)), (0.6, (120, 150, 220)), (1, (250, 210, 160))],
         far=((160, 120, 150), (190, 150, 160)), mtn=((200, 80, 40), (100, 30, 20)), ridge=(255, 160, 100),
         ground=((190, 110, 60), (120, 60, 30)), grass=(120, 150, 40), stars=0),
    # 3 노을
    dict(sky=[(0, (30, 20, 80)), (0.5, (170, 60, 100)), (0.85, (255, 140, 60)), (1, (255, 220, 120))],
         far=((110, 50, 100), (150, 70, 100)), mtn=((120, 50, 70), (40, 15, 30)), ridge=(255, 150, 90),
         ground=((140, 80, 50), (70, 35, 20)), grass=(90, 120, 40), stars=0),
    # 4 밤 (달빛)
    dict(sky=[(0, (2, 4, 20)), (0.7, (15, 30, 80)), (1, (40, 70, 130))],
         far=((25, 35, 70), (35, 50, 90)), mtn=((60, 70, 110), (12, 15, 35)), ridge=(170, 200, 255),
         ground=((80, 80, 100), (40, 40, 55)), grass=(40, 90, 60), stars=1),
    # 5 새벽 안개
    dict(sky=[(0, (60, 80, 140)), (0.6, (170, 160, 190)), (1, (255, 210, 190))],
         far=((150, 150, 180), (180, 175, 200)), mtn=((110, 120, 140), (50, 55, 75)), ridge=(230, 235, 255),
         ground=((150, 140, 120), (90, 80, 70)), grass=(90, 140, 80), stars=0),
    # 6 초원 낮
    dict(sky=[(0, (20, 90, 200)), (0.6, (80, 170, 240)), (1, (190, 230, 255))],
         far=((120, 160, 200), (150, 185, 210)), mtn=((70, 140, 70), (20, 60, 30)), ridge=(190, 255, 160),
         ground=((140, 110, 70), (80, 60, 35)), grass=(70, 170, 50), stars=0),
    # 7 화산 (붉은 밤)
    dict(sky=[(0, (10, 0, 0)), (0.6, (70, 10, 10)), (1, (200, 60, 20))],
         far=((60, 20, 20), (90, 30, 20)), mtn=((70, 40, 40), (20, 10, 12)), ridge=(255, 110, 40),
         ground=((70, 50, 45), (35, 25, 22)), grass=(90, 70, 30), stars=0),
    # 8 눈 덮인 산 (겨울 낮)
    dict(sky=[(0, (40, 90, 170)), (0.6, (130, 180, 230)), (1, (230, 240, 255))],
         far=((170, 185, 210), (200, 210, 225)), mtn=((235, 240, 250), (110, 125, 150)), ridge=(255, 255, 255),
         ground=((220, 225, 235), (150, 160, 175)), grass=(140, 160, 150), stars=0),
]


def theme_colors(th):
    c = []
    c += ramp(th['sky'], 32)                                       # 16-47
    c += ramp([(0, th['far'][0]), (1, th['far'][1])], 8)          # 48-55
    c += ramp([(0, th['mtn'][1]), (1, th['mtn'][0])], 16)         # 56-71 (어두움 -> 밝음)
    r = th['ridge']
    c += [lerp(th['mtn'][0], r, t) for t in (0.4, 0.65, 0.85, 1.0)]   # 72-75
    g0, g1 = th['ground']
    c += ramp([(0, g1), (1, g0)], 16)                              # 76-91 땅 (어두움 -> 밝음)
    gr = th['grass']
    c += [lerp(gr, (0, 0, 0), 0.45), lerp(gr, (0, 0, 0), 0.2), gr, lerp(gr, (255, 255, 200), 0.35)]   # 92-95 풀 가장자리
    c += [(255, 255, 255), (200, 210, 255), (255, 240, 200), (140, 150, 200)]                  # 96-99 별
    assert len(c) == 84
    return c


def base_palette():
    pal = list(EGA)
    pal += theme_colors(THEMES[0])
    for m in MATS:
        pal += ramp(MAT[m], 16)
    # 글자: 빨강 4, 금 4, 초록 4 (위 밝음 -> 아래 진함)
    pal += [(255, 175, 110), (255, 100, 55), (235, 45, 35), (190, 20, 30)]
    pal += [(255, 255, 200), (255, 230, 90), (240, 170, 20), (170, 100, 0)]
    pal += [(220, 255, 210), (120, 255, 120), (40, 200, 70), (10, 120, 40)]
    assert len(pal) == 256, len(pal)
    return pal


# ---- 스프라이트 재질 (CGA 색 1=초록 2=빨강 3=노랑) ----
def mats_for(a):
    if a == 0x6be0:
        return {2: 'red', 3: 'steel', 1: 'green'}, 'truck'
    if a == 0x6c2a:
        return {1: 'green', 2: 'green', 3: 'gold'}, ''
    if 0x6c40 <= a <= 0x6c9e:
        return {2: 'stone', 1: 'stone', 3: 'stone'}, 'rock'
    if a == 0x6ccf:
        return {3: 'fire', 2: 'fire', 1: 'fire'}, 'glow'
    if 0x6cda <= a <= 0x6de8:
        return {3: 'fire', 2: 'red', 1: 'fire'}, 'fire'      # 트럭이 부서질 때 먼지/불 구름
    if 0x71ff <= a <= 0x7263 or a == 0x7ab4:
        return {1: 'gold', 2: 'gold', 3: 'gold'}, 'glow'      # 점수 숫자, NEW LEVEL
    if 0x728d <= a <= 0x72b3:
        return {3: 'wood', 2: 'red', 1: 'wood'}, ''          # 새 날갯짓
    if 0x72d7 <= a <= 0x76c3:
        return {3: 'steel', 2: 'red', 1: 'green'}, ''
    if a == 0x7729:
        return {3: 'steel', 2: 'red', 1: 'green'}, ''
    if a == 0x776e:
        return {2: 'red', 3: 'steel', 1: 'green'}, ''         # 적 버기카
    if 0x77ca <= a <= 0x7a6c:
        return {3: 'wood', 2: 'wood', 1: 'wood'}, 'crate'
    if a in (0x7af6, 0x7afe):
        return {2: 'red', 3: 'gold', 1: 'green'}, 'glow'
    if 0x7b1c <= a <= 0x80a8:
        return {3: 'fire', 2: 'fire', 1: 'fire'}, 'fire'
    if a in (0x8138, 0x8140):
        return {3: 'fire', 2: 'red', 1: 'green'}, 'glow'
    if 0x8154 <= a <= 0x82b4:
        return {3: 'olive', 2: 'steel', 1: 'green'}, ''
    if a == 0x82f7:
        return {1: 'olive', 2: 'red', 3: 'gold'}, ''
    if 0x83d9 <= a <= 0x8421:
        return {2: 'purple', 3: 'gold', 1: 'green'}, ''
    if 0x843b <= a <= 0x85dd:
        return {2: 'purple', 3: 'gold', 1: 'green'}, 'face'
    if a in (0x87bc, 0x87c6):
        return {2: 'stone', 1: 'green', 3: 'gold'}, ''
    return {1: 'green', 2: 'red', 3: 'gold'}, ''


def sprite_pixels(a, w, h):
    px = [[0] * (w * 4) for _ in range(h)]
    for y in range(h):
        for xb in range(w):
            b = image.GIMG[D + a + y * w + xb]
            for k in range(4):
                px[y][xb * 4 + k] = (b >> (6 - 2 * k)) & 3
    return px


def enclosed(px):
    """0 인 점 중 테두리에서 0 을 따라 닿지 않는 것 (타이어/창 같은 속)"""
    h, W = len(px), len(px[0])
    out = [[False] * W for _ in range(h)]
    seen = [[False] * W for _ in range(h)]
    st = [(x, y) for y in range(h) for x in (0, W - 1)] + [(x, y) for x in range(W) for y in (0, h - 1)]
    while st:
        x, y = st.pop()
        if not (0 <= x < W and 0 <= y < h) or seen[y][x] or px[y][x]:
            continue
        seen[y][x] = True
        st += [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
    for y in range(h):
        for x in range(W):
            out[y][x] = px[y][x] == 0 and not seen[y][x]
    return out


def paint(a, w, h):
    px = sprite_pixels(a, w, h)
    mats, kind = mats_for(a)
    W = w * 4
    inside = enclosed(px)
    art = [0] * (W * h)

    def on(x, y):
        return 0 <= x < W and 0 <= y < h and px[y][x] != 0

    cx = sum(x for y in range(h) for x in range(W) if px[y][x]) / max(1, sum(1 for y in range(h) for x in range(W) if px[y][x]))
    cy = sum(y for y in range(h) for x in range(W) if px[y][x]) / max(1, sum(1 for y in range(h) for x in range(W) if px[y][x]))
    for y in range(h):
        for x in range(W):
            v = px[y][x]
            if v == 0:
                if inside[y][x] and kind not in ('fire',):
                    m = mats.get(2) or 'steel'
                    if kind == 'truck':
                        art[y * W + x] = MBASE['steel'] + (7 if y < 4 else 1)     # 유리창 / 휠 속
                    else:
                        art[y * W + x] = MBASE[m] + 1
                continue
            m = mats.get(v, 'steel')
            # 기본 밝기: CGA 색의 밝기 차이를 살린다 (노랑 > 빨강 > 초록 같은 재질 안에서)
            L = {3: 0.66, 2: 0.52, 1: 0.58}[v] if len(set(mats.values())) == 1 else 0.6
            L += 0.22 * (0.5 - y / max(1, h - 1))             # 위가 밝다
            if not on(x, y - 1):
                L += 0.22                                     # 윗가장자리 빛
            if not on(x - 1, y):
                L += 0.08
            if not on(x, y + 1):
                L -= 0.22                                     # 아랫가장자리 그늘
            if not on(x + 1, y):
                L -= 0.08
            if kind == 'fire':
                d = math.hypot((x - cx) / max(1, W / 2), (y - cy) / max(1, h / 2))
                L = 0.95 - 0.55 * d + (0.12 if v == 3 else -0.1)
            elif kind == 'boulder' or kind == 'rock':
                d = math.hypot((x - cx - W * 0.15) / max(1, W / 2), (y - cy - h * 0.15) / max(1, h / 2))
                L = 0.85 - 0.5 * d + (0.08 if v == 3 else -0.12) + R.uniform(-0.05, 0.05)
            elif kind == 'crate':
                L += 0.1 * math.sin(y * 1.3) - 0.04
            elif kind == 'glow':
                L += 0.15
            if kind == 'truck':
                # 바퀴 (8 줄 아래): 노랑 = 고무 타이어, 빨강 = 은색 휠.  위 노랑 = 철제 지붕 틀
                if y >= 8:
                    if v == 3:
                        m, L = 'steel', 0.12 + (0.12 if not on(x, y - 1) else 0) + (0.06 if y <= 9 else 0)
                    else:
                        m, L = 'steel', 0.9 if (x + y) % 2 else 0.75
                elif v == 3:
                    m, L = 'steel', 0.85 if y == 0 else 0.6
                elif v == 2 and y >= 4 and x == W - 1:
                    m, L = 'gold', 0.95       # 전조등
            k = max(0, min(15, int(round(L * 15))))
            art[y * W + x] = MBASE[m] + k
    return art


def main():
    spr = {}
    for ln in open(os.path.join(image.HERE, 'sprites.txt'), encoding='utf-8'):
        p = ln.split(';')[0].split()
        if p:
            spr[int(p[0], 16)] = (int(p[1][1:]), int(p[2][1:]))
    pal = base_palette()
    themes = [theme_colors(t) for t in THEMES]
    o = ['/* orvgatab.c - tools/mkvga.py 가 만든다 (256색 리마스터 자료).  손대지 말 것. */',
         '#include <stdint.h>', '']
    o.append('const uint8_t orv_pal[768] = {')
    o.append(','.join(str(v) for c in pal for v in c) + '};')
    o.append('const uint8_t orv_theme[%d][84 * 3] = {' % len(themes))
    for t in themes:
        o.append('{' + ','.join(str(v) for c in t for v in c) + '},')
    o.append('};')
    o.append('const uint8_t orv_theme_stars[%d] = {%s};' % (len(THEMES), ','.join(str(t['stars']) for t in THEMES)))
    # 스프라이트
    pool = []
    rows = []
    for a, (w, h) in sorted(spr.items()):
        art = paint(a, w, h)
        rows.append('{0x%04x, %d, %d, %d}' % (a, w, h, len(pool)))
        pool += art
    o.append('const int orv_nspr = %d;' % len(rows))
    o.append('const struct orv_spr { uint16_t addr; uint8_t w, h; uint32_t off; } orv_spr[%d] = {' % len(rows))
    o.append(',\n'.join(rows) + '};')
    o.append('const uint8_t orv_art[%d] = {' % len(pool))
    for k in range(0, len(pool), 40):
        o.append(','.join(str(v) for v in pool[k:k + 40]) + ',')
    o.append('};')
    # 무늬: 산 몸 128x64 (0..15 더함 값의 흔들림 -8..7 을 0..15 로), 땅 256x20 (0..15), 먼 산 높이 1024
    tm = []
    for y in range(64):
        for x in range(128):
            n = (math.sin(x * 0.35 + y * 0.9) * 0.5 + math.sin(x * 0.11 - y * 0.23) * 0.7 + R.uniform(-0.6, 0.6))
            strata = math.sin(y * 0.7 + math.sin(x * 0.05) * 2) * 0.8
            tm.append(max(0, min(15, int(round(8 + 2.2 * n + 1.5 * strata)))))
    o.append('const uint8_t orv_tex_mtn[64 * 128] = {' + ','.join(map(str, tm)) + '};')
    tg = []
    for y in range(20):
        for x in range(256):
            base = 13 - y * 0.45
            n = R.uniform(-1.6, 1.6) + math.sin(x * 0.7 + y) * 0.6
            # 바퀴 자국 두 줄
            if y in (6, 7, 13, 14):
                n -= 3
            if (x * 7 + y * 13) % 37 == 0:
                n += 3          # 자갈
            tg.append(max(0, min(15, int(round(base + n)))))
    o.append('const uint8_t orv_tex_gnd[20 * 256] = {' + ','.join(map(str, tg)) + '};')
    fh = []
    for x in range(1024):
        t = x / 1024 * 2 * math.pi
        v = 18 + 9 * math.sin(t * 3 + 0.5) + 6 * math.sin(t * 7 + 1.7) + 3 * math.sin(t * 17 + 0.3)
        fh.append(int(round(v)))
    o.append('const uint8_t orv_far_h[1024] = {' + ','.join(map(str, fh)) + '};')
    st = []
    for k in range(90):
        st.append('%d,%d,%d' % (R.randrange(512), R.randrange(21, 140), R.randrange(4)))
    o.append('const int orv_nstars = 90;')
    o.append('const uint16_t orv_stars[90 * 3] = {' + ','.join(st) + '};')
    open(OUT, 'w', encoding='utf-8', newline='\n').write('\n'.join(o) + '\n')
    print('orvgatab.c: %d sprites, art %d bytes' % (len(rows), len(pool)))
    if '--sheet' in sys.argv:
        from PIL import Image
        cells = []
        for a, (w, h) in sorted(spr.items()):
            art = paint(a, w, h)
            im = Image.new('RGB', (w * 4, h), (0, 60, 120))
            for y in range(h):
                for x in range(w * 4):
                    v = art[y * w * 4 + x]
                    if v:
                        im.putpixel((x, y), pal[v])
            cells.append(im.resize((w * 16, h * 4), Image.NEAREST))
        Wd = 1280
        x = y = rh = 0
        out = Image.new('RGB', (Wd, 1000), (0, 60, 120))
        for im in cells:
            if x + im.width > Wd:
                x, y, rh = 0, y + rh + 6, 0
            out.paste(im, (x, y))
            x += im.width + 6
            rh = max(rh, im.height)
        out.crop((0, 0, Wd, y + rh)).save(os.path.join(image.ROOT, '_vga_sheet.png'))


if __name__ == '__main__':
    main()
