# 훑은 코드를 089D: 오프셋으로 늘어놓기 -> _list.txt
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan, image
from capstone import Cs, CS_ARCH_X86, CS_MODE_16
md = Cs(CS_ARCH_X86, CS_MODE_16)
B = image.CSEG * 16
out = []
for a in sorted(scan.code):
    i = scan.code[a]
    j = next(md.disasm(bytes(i.bytes), a - B))
    if a in scan.funcs:
        out.append('')
        out.append('; ---- f_%04x' % (a - B))
    out.append('%04x  %-14s %s %s' % (a - B, i.bytes.hex(), j.mnemonic, j.op_str))
open(os.path.join(image.ROOT, '_list.txt'), 'w').write('\n'.join(out) + '\n')
