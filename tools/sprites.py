# 그리는 함수에 들어올 때마다 (자료 주소, 폭 바이트, 높이, 부른 곳) 를 모은다 -> tools/_sprites.txt
#   python tools/sprites.py 대본.txt 틱수     (환경 INF/WARP 그대로 씀)
#   2455 = XOR 스프라이트 (DS:[0036] 자료, DL 폭 바이트, CH 줄, [002C] 바이트 x, [002E] y, [003A] 밀기)
#   24B0 = 글자 (덮어쓰기, [002A] 색 가면)
import sys, os, struct, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import emu, image
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import *

L = image.LOADSEG * 16
B = image.CSEG * 16
D = (image.LOADSEG + 0x20) * 16
m = emu.Machine(keys=emu.parse_keys(sys.argv[1]))
seen = collections.Counter()
info = {}


def w(a):
    return struct.unpack('<H', m.mu.mem_read(D + a, 2))[0]


def hk(mu, addr, size, kind):
    r = mu.reg_read
    sp = r(UC_X86_REG_SP)
    ret = struct.unpack('<H', mu.mem_read(r(UC_X86_REG_SS) * 16 + sp, 2))[0]
    dl, ch = r(UC_X86_REG_DX) & 0xFF, r(UC_X86_REG_CX) >> 8
    k = (kind, w(0x36), dl, ch, ret)
    seen[k] += 1
    info.setdefault(k, (w(0x2c), w(0x2e), w(0x3a), w(0x2a), m.ticks))


m.mu.hook_add(UC_HOOK_CODE, hk, 'X', L + B + 0x2455, L + B + 0x2455)
m.mu.hook_add(UC_HOOK_CODE, hk, 'T', L + B + 0x24B0, L + B + 0x24B0)
print(m.run(int(sys.argv[2])))
out = []
for k, n in sorted(seen.items(), key=lambda e: (e[0][0], e[0][1])):
    x, y, sh, col, t = info[k]
    out.append('%s %04x w%d h%d from %04x  n=%d  first x%d y%d sh%d col%04x t%d' % (k[0], k[1], k[2], k[3], k[4], n, x, y, sh, col, t))
open(os.path.join(image.HERE, '_sprites_%s.txt' % os.environ.get('WARP', '0')), 'w').write('\n'.join(out) + '\n')
print('\n'.join(out))
