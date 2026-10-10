# 코드 훑기: 함수 시작점, 명령, 인라인 분기표를 모은다 (image.py 의 그림)
#   code[선형주소] = capstone 명령 (주소 = 세그먼트*16+오프셋, LOADSEG 기준; 코드는 모두 세그먼트 0000)
#   funcs[함수 선형주소] = 그 함수의 CS
#
#   0F54 는 "call 0F54 / dw 대상, 대상, ..." 꼴의 분기표 함수다: 복귀 주소 뒤의 낱말표에서
#   AL 번째를 골라 그 주소로 ret 한다.  그래서 call 0F54 뒤는 명령이 아니라 표이고, 표의 길이는
#   '가장 작은 대상 주소' 앞까지다 (표 바로 뒤가 첫 대상 코드).
import struct, os, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_16
from capstone.x86 import *

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import image
from image import IMG, RELOC, ROOT, w16, GAME

md = Cs(CS_ARCH_X86, CS_MODE_16)
md.detail = True

DS = image.DSEG
CODE_RANGES = [(image.CSEG * 16, image.CEND)]
SWITCH_FN = -1


def in_code(a):
    return any(s <= a < e for s, e in CODE_RANGES)


def dis1(a):
    for i in md.disasm(bytes(IMG[a:a + 16]), a):
        return i
    return None


code = {}
iseg = {}
INLINE = {}
RETSITE = {}
funcs = {}
jtabs = {}                  # 간접 jmp 주소 -> [대상 선형 ...]
ncalls = {}                 # 간접 near call 주소 -> [대상 선형 ...]
swtabs = {}                 # call 0F54 주소 -> [대상 선형 ...]
problems = []
pending = []
IND_SITES = []

MANUAL_J = {}
MANUAL_C = {}
ROOTS = []
LABELS = []                 # ret 으로 가는 곳 등 (dispatch 대상)


def parse_roots():
    p = os.path.join(HERE, 'roots.txt')
    if not os.path.exists(p):
        return
    for ln in open(p, encoding='utf-8'):
        ln = ln.split(';')[0].split()
        if not ln:
            continue
        s, o = [int(x, 16) for x in ln[1].split(':')]
        a = s * 16 + o
        if ln[0] == 'func':
            ROOTS.append((s, o))
        elif ln[0] == 'label':
            LABELS.append(a)
        elif ln[0] == 'jlist':
            MANUAL_J[a] = [s * 16 + int(x, 16) for x in ln[2:]]
        elif ln[0] == 'clist':
            MANUAL_C[a] = [s * 16 + int(x, 16) for x in ln[2:]]


parse_roots()


def add_func(seg, off, why=''):
    a = seg * 16 + off
    if not in_code(a):
        problems.append('func outside code %04x:%04x %s' % (seg, off, why))
        return
    if a not in funcs:
        funcs[a] = seg
        pending.append((a, seg))


def switch_table(a):
    """call 0F54 (a) 뒤의 표"""
    t0 = a + 3
    tg = []
    lo = 0x10000
    p = t0
    while p < lo and len(tg) < 64:
        v = w16(p)
        if not in_code(v) or v <= t0:
            break
        tg.append(v)
        lo = min(lo, v)
        p += 2
    return tg


def walk(start, seg):
    work = [start]
    while work:
        a = work.pop()
        while True:
            if a in code:
                break
            i = dis1(a)
            if i is None:
                problems.append('bad insn at %04x:%04x' % (seg, a - seg * 16))
                break
            code[a] = i
            iseg[a] = seg
            m = i.mnemonic
            nxt = a + i.size
            off = a - seg * 16
            if m == 'call' and i.operands[0].type == X86_OP_IMM:
                t = (i.operands[0].imm - seg * 16) & 0xffff
                add_func(seg, t, 'near call at %04x:%04x' % (seg, off))
                if t == SWITCH_FN:
                    tg = switch_table(a)
                    swtabs[a] = tg
                    work.extend(tg)
                    break
            elif m == 'call':
                if a in MANUAL_C:
                    for t in MANUAL_C[a]:
                        add_func(seg, t - seg * 16, 'ncall list')
                    ncalls[a] = MANUAL_C[a]
                else:
                    IND_SITES.append(a)
            elif m == 'lcall':
                IND_SITES.append(a)
            if m in ('ret', 'retf', 'iret', 'hlt'):
                break
            if m == 'int' and i.operands[0].imm in (0x19, 0x20):
                break
            if m == 'jmp' or m == 'ljmp':
                op = i.operands[0]
                if m == 'jmp' and op.type == X86_OP_IMM:
                    a = seg * 16 + ((op.imm - seg * 16) & 0xffff)
                    continue
                if a in MANUAL_J:
                    jtabs[a] = MANUAL_J[a]
                    work.extend(MANUAL_J[a])
                    break
                IND_SITES.append(a)
                break
            if m.startswith('j') or m.startswith('loop') or m == 'jcxz':
                work.append(seg * 16 + ((i.operands[0].imm - seg * 16) & 0xffff))
            a = nxt


# 진입점 + 인터럽트 처리기 (int 8 = 0094, int 9 = 032C)
add_func(image.GSEG_SYS, image.GH[10], 'entry')
#
#
for s, o in ROOTS:
    add_func(s, o, 'roots')
LABEL_ROOTS = set(LABELS)
for a_ in LABELS:
    pending.append((a_, 0))
_cv = os.path.join(HERE, '_cover.txt')
if os.path.exists(_cv):
    for ln in open(_cv).read().split():
        s_, o_ = [int(x, 16) for x in ln.split(':')]
        a_ = s_ * 16 + o_
        if in_code(a_):
            LABEL_ROOTS.add(a_)
            if a_ not in code:
                pending.append((a_, s_))

while pending:
    a, seg = pending.pop()
    walk(a, seg)

OVERLAPS = []
_prev = None
for _a in sorted(code):
    if _prev is not None and _prev + code[_prev].size > _a:
        OVERLAPS.append((_prev, _a))
    _prev = _a

if __name__ == '__main__':
    print('funcs', len(funcs), 'insns', len(code), 'switches', len(swtabs), 'indirect', len(IND_SITES))
    for a, t in sorted(swtabs.items()):
        print('switch %04x: %s' % (a, ' '.join('%04x' % x for x in t)))
    for a in IND_SITES:
        print('indirect %04x: %s %s' % (a, code[a].mnemonic, code[a].op_str))
    for x, y in OVERLAPS:
        print('overlap %04x / %04x' % (x, y))
    cov = set()
    for a, i in code.items():
        cov.update(range(a, a + i.size))
    for a, t in swtabs.items():
        cov.update(range(a + 3, a + 3 + 2 * len(t)))
    a = 0
    while a < image.CEND:
        if a not in cov:
            s = a
            while a < image.CEND and a not in cov:
                a += 1
            if a - s > 1:
                print('gap %04x-%04x (%d) %s' % (s, a, a - s, bytes(IMG[s:min(a, s + 20)]).hex()))
        else:
            a += 1
    seen = set()
    for p in problems:
        if p not in seen:
            print(p)
            seen.add(p)
