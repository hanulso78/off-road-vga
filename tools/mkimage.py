# 원판 EXE 를 LOADSEG 에 올린 모습 (재배치 끝낸 것) 을 C 배열로: orimg.c
import sys, os, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import image

img = bytearray(image.GIMG)
for r in image.RELOC:
    v = struct.unpack('<H', img[r:r + 2])[0]
    img[r:r + 2] = struct.pack('<H', (v + image.LOADSEG) & 0xFFFF)
n = len(img)
while n and img[n - 1] == 0:
    n -= 1
h = image.GH
out = ['/* orimg.c - %s 를 LOADSEG(%04X) 에 올린 모습 (tools/mkimage.py 가 만든다) */' % (image.EXE, image.LOADSEG),
       '#include <stdint.h>',
       'const uint32_t or_img_len = %d;' % n,
       '/* CS IP SS SP (LOADSEG 기준), 최소 할당(문단), 그림 크기(문단) */',
       'const uint16_t or_img_regs[6] = {0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x, 0x%04x};' % (
           h[11], h[10], h[7], h[8], h[5], (len(image.GIMG) + 15) // 16),
       'const uint8_t or_img[%d] = {' % n]
for k in range(0, n, 32):
    out.append(','.join(str(b) for b in img[k:min(k + 32, n)]) + ',')
out.append('};')
open(os.path.join(image.ROOT, 'orimg.c'), 'w', newline='\n').write('\n'.join(out) + '\n')
print('orimg.c %d bytes' % n)
