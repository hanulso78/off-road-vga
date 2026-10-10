# 메모리 그림: 원판 OFFROAD.EXE (압축 없는 MZ) 를 LOADSEG 에 올린 모습
#   IMG[선형 - LOADSEG*16] 로 본다.  재배치 값은 모두 "LOADSEG 기준" (실제 세그먼트 = LOADSEG + 값)
#   자료 세그먼트 = 0020 (DS:0000-87CF), 코드 세그먼트 = 089D (스택은 SS=0000 SP=0200 = PSP 뒤 머리 자리)
import os, struct

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..'))
EXE = 'OFFROAD.EXE'
GAME = 'or'

LOADSEG = 0x1000
PSP = LOADSEG - 0x10
DSEG = 0x0020


def load_mz(fn):
    d = open(fn, 'rb').read()
    h = struct.unpack('<14H', d[:28])
    size = (h[2] - 1) * 512 + h[1] if h[1] else h[2] * 512
    img = bytearray(d[h[4] * 16:size])
    rel = []
    for i in range(h[3]):
        o, s = struct.unpack('<HH', d[h[12] + 4 * i:h[12] + 4 * i + 4])
        rel.append(s * 16 + o)
    return h, img, rel


GH, GIMG, GREL = load_mz(os.path.join(ROOT, 'orig', EXE))
IMG = bytearray(GIMG) + bytearray(0x10000)
RELOC = set(GREL)
GSEG_SYS = GH[11]           # 시작 CS
CSEG = 0x089D
CEND = len(GIMG)


def w16(a):
    return struct.unpack('<H', IMG[a:a + 2])[0]
