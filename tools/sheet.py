# 모은 스프라이트(tools/sprites.txt)를 한 장에 (CGA 팔레트 0 밝음) -> _spr_sheet.png
import sys, os, glob
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import image
from PIL import Image, ImageDraw
D = 0x20 * 16
spr = {}
for ln in open(os.path.join(image.HERE, 'sprites.txt'), encoding='utf-8'):
    p = ln.split(';')[0].split()
    if p:
        spr[int(p[0], 16)] = (int(p[1][1:]), int(p[2][1:]))
PAL = [(0, 0, 0), (85, 255, 85), (255, 85, 85), (255, 255, 85)]
S = 3
cells = []
for a, (w, h) in sorted(spr.items()):
    im = Image.new('RGB', (w * 4, h))
    for y in range(h):
        for xb in range(w):
            b = image.GIMG[D + a + y * w + xb]
            for k in range(4):
                im.putpixel((xb * 4 + k, y), PAL[(b >> (6 - 2 * k)) & 3])
    cells.append((a, im.resize((w * 4 * S, h * S), Image.NEAREST)))
W = 1200
x = y = 0
rowh = 0
pos = []
for a, im in cells:
    if x + im.width + 10 > W:
        x = 0
        y += rowh + 16
        rowh = 0
    pos.append((x, y))
    x += im.width + 12
    rowh = max(rowh, im.height)
out = Image.new('RGB', (W, y + rowh + 20), (40, 40, 60))
d = ImageDraw.Draw(out)
for (a, im), (x, y) in zip(cells, pos):
    out.paste(im, (x, y + 12))
    d.text((x, y), '%04x' % a, fill=(200, 200, 200))
out.save(os.path.join(image.ROOT, '_spr_sheet.png'))
print(len(cells))
