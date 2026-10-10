# -*- coding: utf-8 -*-
"""Off-Road (Montsoft 1988, IBM CGA) 코드를 C 로 옮긴다 (기계적 변환, 명령 하나씩 원본과 같게)

   python tools/asm2c.py   -> or_code.c

   - 손 어셈블리 프로그램 전체를 함수 하나 (or_run_code) 로 옮긴다:
       call -> 복귀 주소를 원본처럼 스택(M[])에 넣고 goto
       ret/iret, 간접 jmp -> 주소를 계산해 dispatch switch 로 goto
     => 스택 메모리까지 원본과 똑같다.
   - 레지스터는 전역 변수(cpu.h), 메모리는 1MB 평면 배열 M[] (실모드 선형 주소).
   - 플래그(C Z S O)는 쓰이는 것만 계산한다 (프로그램 전체 흐름에서 생존 분석).
   - 원판은 인터럽트를 걸지 않고 CPU 속도로 시간을 끈다.  옮긴 C 는 프레임 끝(tools/polls.py
     POLLAT)과 int 16h 기다림에서만 폴한다 (틱 하나 + 자판 스캔 코드를 BIOS 버퍼로).
     에뮬레이터(tools/emu.py)도 같은 자리에서 같은 규칙 -> 결정적, 대조 가능.
   - 블록마다 CYC(8088 클럭 어림) 을 더해 도스판이 원판 PC 속도로 맞춘다 (sys_dos.c).
"""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan, polls, image
from scan import code, iseg, funcs, RELOC, IMG
from capstone.x86 import *

GAME = image.GAME
ROOT = image.ROOT
PFX = GAME                      # 레이블/함수 이름 앞붙이
POLL = {a: t for a, t in polls.POLLS}
INT16 = set(polls.INT16)
# CPU 속도로 시간을 끄는 빈 되돌이: 그 명령 앞에서 or_delay(8088 클럭 수) (도스판만 실제로 기다린다)
DELAYS = {}
POLLAT = set(polls.POLLAT)
SPINS = set(polls.SPINS)

# 256색 개선판 갈고리 (tools/vhooks_<game>.txt): 그 명령 앞에 VH(선형)
VHOOKS = set()
for _fn in ('vhooks.txt',):
    if not os.path.exists(os.path.join(scan.HERE, _fn)):
        continue
    for ln in open(os.path.join(scan.HERE, _fn), encoding='utf-8'):
        ln = ln.split(';')[0].split()
        if ln:
            _s, _o = [int(x, 16) for x in ln[0].split(':')]
            VHOOKS.add(_s * 16 + _o)
FAST = {}

names = {}
NAMES_TXT = os.path.join(scan.HERE, 'names.txt')
if os.path.exists(NAMES_TXT):
    for ln in open(NAMES_TXT, encoding='utf-8'):
        ln, _, note = ln.partition(';')
        p = ln.split()
        if len(p) >= 2:
            s, o = p[0].split(':')
            names[int(s, 16) * 16 + int(o, 16)] = p[1]

R16 = {'ax': 'AX', 'bx': 'BX', 'cx': 'CX', 'dx': 'DX', 'si': 'SI', 'di': 'DI', 'bp': 'BP', 'sp': 'SP',
       'cs': 'CS_', 'ds': 'DS_', 'es': 'ES_', 'ss': 'SS_'}
R8 = {'al': 'AL', 'ah': 'AH', 'bl': 'BL', 'bh': 'BH', 'cl': 'CL', 'ch': 'CH', 'dl': 'DL', 'dh': 'DH'}
JCC = {'je', 'jne', 'jl', 'jg', 'jge', 'jle', 'jb', 'jae', 'jns', 'js', 'ja', 'jbe'}
JCC_USES = {'je': 'Z', 'jne': 'Z', 'jl': 'SO', 'jge': 'SO', 'jg': 'ZSO', 'jle': 'ZSO', 'jb': 'C', 'jae': 'C',
            'jns': 'S', 'js': 'S', 'ja': 'CZ', 'jbe': 'CZ'}
ALLF = frozenset('CZSO')


MEMOP = lambda i: any(o.type == X86_OP_MEM for o in i.operands)


def icost(i):
    """8088 (4.77MHz) 에서 이 명령이 먹는 클럭 어림 (명령 바이트 가져오기 4클럭/바이트 하한)"""
    m = i.mnemonic
    mem = MEMOP(i)
    w = 2 if (i.operands and i.operands[0].size == 2) else 1
    c = 4
    if m.startswith('rep'):
        c = 9
    elif m in ('mov', 'lea'):
        c = (14 + 4 * (w - 1)) if mem else 2
    elif m == 'push':
        c = 15
    elif m == 'pop':
        c = 12
    elif m == 'xchg':
        c = 4
    elif m in ('add', 'sub', 'adc', 'sbb', 'and', 'or', 'xor', 'cmp', 'test'):
        c = ((24 + 4 * (w - 1)) if i.operands[0].type == X86_OP_MEM else (13 + 4 * (w - 1))) if mem else 3
    elif m in ('inc', 'dec'):
        c = (23 + 4 * (w - 1)) if mem else 3
    elif m in ('neg', 'not'):
        c = 24 if mem else 3
    elif m in ('shl', 'shr', 'sar', 'rcl', 'rcr', 'rol', 'ror'):
        if len(i.operands) > 1 and i.operands[1].type != X86_OP_IMM:
            c = 12
        else:
            c = 23 if mem else 2
    elif m in ('mul', 'imul'):
        c = (133 if w == 2 else 77) + (16 if mem else 0)
    elif m in ('div', 'idiv'):
        c = (160 if w == 2 else 90) + (16 if mem else 0)
    elif m == 'call':
        c = 23
    elif m == 'ret':
        c = 20
    elif m == 'retf':
        c = 34
    elif m == 'jmp':
        c = 15
    elif m in JCC:
        c = 12
    elif m.startswith('loop'):
        c = 17
    elif m == 'jcxz':
        c = 14
    elif m == 'int':
        c = 71
    elif m in ('in', 'out'):
        c = 10
    elif m in ('movsb', 'movsw', 'stosb', 'stosw', 'lodsb', 'lodsw'):
        c = {'movsb': 18, 'movsw': 26, 'stosb': 11, 'stosw': 15, 'lodsb': 12, 'lodsw': 16}[m]
    return max(c, 4 * i.size)


def tgt(i):
    s = iseg[i.address]
    return s * 16 + ((i.operands[0].imm - s * 16) & 0xffff)


def far_tgt(a):
    return scan.w16(a + 3) * 16 + scan.w16(a + 1)


def next_of(a):
    """call 다음 (인라인 인자 건너뛴) 복귀 자리"""
    return scan.RETSITE.get(a, a + code[a].size)


# ---- 복귀 자리, dispatch 대상 ----
RETS = set()
for a, i in code.items():
    if i.mnemonic in ('call', 'lcall'):
        r = next_of(a)
        if r in code and a not in scan.swtabs:
            RETS.add(r)
for _t in scan.swtabs.values():
    RETS |= set(x for x in _t if x in code)
DISPATCH = set(RETS) | set(funcs) | set(x for x in scan.LABEL_ROOTS if x in code) | set(POLL.values())
for _t in list(scan.jtabs.values()) + list(scan.ncalls.values()):
    DISPATCH |= set(_t)
DISPATCH |= set(v[1] for v in FAST.values() if v[1] in code)
DISPATCH = set(x for x in DISPATCH if x in code)

# ---- 흐름 ----
RETP = 'RET'
DISP = 'DISP'


def succs(a):
    i = code[a]
    m = i.mnemonic
    op = i.operands
    nxt = a + i.size
    if m in ('ret', 'retf', 'iret'):
        return [RETP]
    if m == 'hlt' or (m == 'int' and op[0].imm in (0x19, 0x20)):
        return []
    if m == 'jmp':
        if a in POLL:
            return [tgt(i), DISP]
        return [tgt(i)] if op[0].type == X86_OP_IMM else [DISP]
    if m == 'ljmp':
        return [far_tgt(a)] if op[0].type == X86_OP_IMM else [DISP]
    if m == 'call':
        return [tgt(i)] if op[0].type == X86_OP_IMM else [DISP]
    if m == 'lcall':
        return [far_tgt(a)] if op[0].type == X86_OP_IMM else [DISP]
    if m in JCC or m.startswith('loop') or m == 'jcxz':
        s = [nxt, tgt(i)]
        if a in POLL:
            s.append(DISP)
        return s
    return [nxt]


def flag_du(i):
    m = i.mnemonic
    if m in ('add', 'sub', 'cmp', 'neg', 'and', 'or', 'xor', 'test'):
        return ALLF, frozenset()
    if m in ('adc', 'sbb'):
        return ALLF, frozenset('C')
    if m in ('inc', 'dec'):
        return frozenset('ZSO'), frozenset()
    if m in ('shl', 'shr', 'sar'):
        if i.operands[1].type == X86_OP_REG:
            return frozenset(), frozenset()      # cl 번: 0 이면 그대로 (보수적으로 정의 안 함)
        return ALLF, frozenset()
    if m in ('rcl', 'rcr'):
        return frozenset('CO'), frozenset('C')
    if m in ('rol', 'ror'):
        if i.operands[1].type == X86_OP_REG:
            return frozenset(), frozenset()
        return frozenset('CO'), frozenset()
    if m == 'pushf':
        return frozenset(), ALLF
    if m == 'lahf':
        return frozenset(), frozenset('CZS')
    if m == 'sahf':
        return frozenset('CZS'), frozenset()
    if m == 'daa':
        return frozenset('CZS'), frozenset('C')
    if m == 'aaa':
        return frozenset('C'), frozenset()
    if m in ('idiv', 'div'):
        return ALLF, frozenset()
    if m in ('popf', 'iret'):
        return ALLF, frozenset()
    if m in ('mul', 'imul'):
        return frozenset('CO'), frozenset()
    if m in ('stc', 'clc'):
        return frozenset('C'), frozenset()
    if m == 'cmc':
        return frozenset('C'), frozenset('C')
    if m == 'int':
        return (frozenset('C') if i.operands[0].imm == 0x21 else frozenset('Z') if i.operands[0].imm == 0x16
                else frozenset()), frozenset()
    if m in JCC:
        return frozenset(), frozenset(JCC_USES[m])
    return frozenset(), frozenset()


def liveness():
    addrs = sorted(code)
    S = {a: succs(a) for a in addrs}
    DU = {a: flag_du(code[a]) for a in addrs}
    lin = {a: frozenset() for a in addrs}
    lout = {a: frozenset() for a in addrs}
    ret_live = frozenset()
    disp_live = frozenset()
    changed = True
    it = 0
    while changed:
        changed = False
        it += 1
        for a in reversed(addrs):
            out = set()
            for s in S[a]:
                if s == RETP:
                    out |= ret_live
                elif s == DISP:
                    out |= disp_live
                elif s in lin:
                    out |= lin[s]
            d, u = DU[a]
            inn = frozenset((out - d) | u)
            out = frozenset(out)
            if out != lout[a] or inn != lin[a]:
                lout[a] = out
                lin[a] = inn
                changed = True
        r = frozenset().union(*[lin[x] for x in RETS]) if RETS else frozenset()
        r |= frozenset().union(*[lin[x] for x in POLL.values()]) if POLL else frozenset()
        d = frozenset().union(*[lin[x] for x in DISPATCH])
        if r != ret_live or d != disp_live:
            ret_live, disp_live = r, d
            changed = True
    return lin, lout, it


# ---- 피연산자 ----
def has_reloc_at(a, k):
    return (a + k) in RELOC


def imm_text(i, v, size):
    # 즉치값은 명령 끝에 있다: 그 자리가 재배치되면 세그먼트
    if (i.address + i.size - 2) in RELOC and size == 2:
        return 'SEG(0x%x)' % (v & 0xffff)
    if size == 1:
        return '0x%x' % (v & 0xff)
    return '0x%x' % (v & 0xffff)


def mem_addr(i, op):
    mm = op.mem
    parts = []
    base = i.reg_name(mm.base) if mm.base else None
    index = i.reg_name(mm.index) if mm.index else None
    if base:
        parts.append(R16[base])
    if index:
        parts.append(R16[index])
    if mm.disp or not parts:
        parts.append('0x%x' % (mm.disp & 0xffff))
    off = ' + '.join(parts)
    if len(parts) > 1:
        off = '(uint16_t)(%s)' % off
    if mm.segment:
        seg = R16[i.reg_name(mm.segment)]
    elif base == 'bp':
        seg = 'SS_'
    else:
        seg = 'DS_'
    return seg, off


def rd(i, op, size=None):
    if op.type == X86_OP_REG:
        r = i.reg_name(op.reg)
        return R16.get(r) or R8[r]
    if op.type == X86_OP_IMM:
        return imm_text(i, op.imm, size or op.size)
    seg, off = mem_addr(i, op)
    return '%s(%s, %s)' % ('RB' if op.size == 1 else 'RW', seg, off)


def wr(i, op, val):
    if op.type == X86_OP_REG:
        r = i.reg_name(op.reg)
        return '%s = %s;' % (R16.get(r) or R8[r], val)
    seg, off = mem_addr(i, op)
    return '%s(%s, %s, %s);' % ('WB' if op.size == 1 else 'WW', seg, off, val)


def cast(sz):
    return 'uint8_t' if sz == 1 else 'uint16_t'


def scast(sz):
    return 'int8_t' if sz == 1 else 'int16_t'


def signbit(sz):
    return 7 if sz == 1 else 15


def lab(a):
    return 'L%05x' % a


class Gen:
    def __init__(self, lin, lout, labels):
        self.li, self.lo = lin, lout
        self.labels = labels
        self.fold = {}
        self.out = []

    def emit(self, s):
        self.out.append(s)

    def flags_code(self, live, kind, sz, A, B, R):
        sb = signbit(sz)
        mask = '0xff' if sz == 1 else '0xffff'
        c = []
        if 'Z' in live:
            c.append('ZF = ((%s & %s) == 0);' % (R, mask))
        if 'S' in live:
            c.append('SF = ((%s >> %d) & 1);' % (R, sb))
        if 'C' in live:
            if kind in ('add', 'adc'):
                c.append('CF = (%s > %s);' % (R, mask))
            elif kind in ('sub', 'cmp', 'sbb'):
                c.append('CF = ((%s >> %d) & 1);' % (R, sb + 1))
            elif kind in ('and', 'or', 'xor', 'test'):
                c.append('CF = 0;')
            elif kind == 'neg':
                c.append('CF = (%s != 0);' % A)
        if 'O' in live:
            if kind in ('add', 'adc', 'inc'):
                c.append('OF = (((%s ^ %s) & (%s ^ %s)) >> %d) & 1;' % (A, R, B, R, sb))
            elif kind in ('sub', 'cmp', 'dec', 'sbb'):
                c.append('OF = (((%s ^ %s) & (%s ^ %s)) >> %d) & 1;' % (A, B, A, R, sb))
            elif kind in ('and', 'or', 'xor', 'test'):
                c.append('OF = 0;')
            elif kind == 'neg':
                c.append('OF = (%s == %s);' % (A, '0x80' if sz == 1 else '0x8000'))
        return c

    def cond_expr(self, jcc, kind, sz, A, B, R):
        st = scast(sz)
        ut = cast(sz)
        if kind == 'cmp':
            return {'je': '%s == %s' % (A, B), 'jne': '%s != %s' % (A, B),
                    'jl': '(%s)%s < (%s)%s' % (st, A, st, B), 'jge': '(%s)%s >= (%s)%s' % (st, A, st, B),
                    'jg': '(%s)%s > (%s)%s' % (st, A, st, B), 'jle': '(%s)%s <= (%s)%s' % (st, A, st, B),
                    'jb': '%s < %s' % (A, B), 'jae': '%s >= %s' % (A, B),
                    'ja': '%s > %s' % (A, B), 'jbe': '%s <= %s' % (A, B),
                    'js': '(%s)(%s - %s) < 0' % (st, A, B), 'jns': '(%s)(%s - %s) >= 0' % (st, A, B)}.get(jcc)
        if kind in ('test', 'and', 'or', 'xor'):
            v = R
            return {'je': '(%s)%s == 0' % (ut, v), 'jne': '(%s)%s != 0' % (ut, v),
                    'js': '(%s)%s < 0' % (st, v), 'jns': '(%s)%s >= 0' % (st, v),
                    'jl': '(%s)%s < 0' % (st, v), 'jge': '(%s)%s >= 0' % (st, v),
                    'jg': '(%s)%s > 0' % (st, v), 'jle': '(%s)%s <= 0' % (st, v),
                    'jb': '0', 'jae': '1', 'ja': '(%s)%s != 0' % (ut, v), 'jbe': '(%s)%s == 0' % (ut, v)}.get(jcc)
        if kind in ('inc', 'dec', 'add', 'sub', 'shl', 'shr', 'neg'):
            if jcc in ('je', 'jne', 'js', 'jns'):
                v = R
                return {'je': '(%s)%s == 0' % (ut, v), 'jne': '(%s)%s != 0' % (ut, v),
                        'js': '(%s)%s < 0' % (st, v), 'jns': '(%s)%s >= 0' % (st, v)}[jcc]
        return None

    def can_fold(self, a, i, defs):
        nxt = a + i.size
        j = code.get(nxt)
        ok = (j is not None and j.mnemonic in JCC and not (self.lo[nxt] & defs) and nxt not in self.labels)
        return j if ok else None

    def alu(self, a, i):
        m = i.mnemonic
        ops = i.operands
        dst = ops[0]
        sz = dst.size
        ct = cast(sz)
        defs = flag_du(i)[0]
        live = self.lo[a] & defs
        j = self.can_fold(a, i, defs)
        nxt = a + i.size
        A0 = rd(i, dst)
        if m in ('cmp', 'test'):
            B0 = rd(i, ops[1], sz)
            if j:
                ce = (self.cond_expr(j.mnemonic, 'cmp', sz, A0, B0, None) if m == 'cmp' else
                      self.cond_expr(j.mnemonic, 'test', sz, None, None, '(%s & %s)' % (A0, B0)))
                if ce:
                    self.fold[nxt] = ce
                    return
            if not live:
                return
            self.emit('{ %s a_ = %s, b_ = %s; unsigned r_ = %s;' % (
                ct, A0, B0, '(unsigned)a_ - b_' if m == 'cmp' else '(unsigned)(a_ & b_)'))
            for c in self.flags_code(live, m, sz, 'a_', 'b_', 'r_'):
                self.emit('  ' + c)
            self.emit('}')
            return
        if m in ('inc', 'dec', 'neg', 'not'):
            B0 = '1'
            if m == 'not':
                self.emit(wr(i, dst, '(%s)~%s' % (ct, A0)))
                return
            opx = {'inc': '(unsigned)a_ + 1', 'dec': '(unsigned)a_ - 1', 'neg': '0u - a_'}[m]
            if dst.type == X86_OP_REG:
                short = {'inc': '%s++;' % A0, 'dec': '%s--;' % A0, 'neg': '%s = (%s)(0u - %s);' % (A0, ct, A0)}[m]
            else:
                short = wr(i, dst, '(%s)(%s)' % (ct, {'inc': A0 + ' + 1', 'dec': A0 + ' - 1', 'neg': '0u - ' + A0}[m]))
        else:
            B0 = rd(i, ops[1], sz)
            opx = {'add': '(unsigned)a_ + b_', 'sub': '(unsigned)a_ - b_', 'adc': '(unsigned)a_ + b_ + CF',
                   'sbb': '(unsigned)a_ - b_ - CF',
                   'and': '(unsigned)(a_ & b_)', 'or': '(unsigned)(a_ | b_)', 'xor': '(unsigned)(a_ ^ b_)'}[m]
            same = (dst.type == X86_OP_REG and ops[1].type == X86_OP_REG and ops[0].reg == ops[1].reg)
            if m in ('xor', 'sub') and same:
                self.emit('%s = 0;' % A0)
                if live:
                    self.emit(' '.join(c for c in ['CF = 0;' if 'C' in live else '', 'ZF = 1;' if 'Z' in live else '',
                                                   'SF = 0;' if 'S' in live else '', 'OF = 0;' if 'O' in live else ''] if c))
                return
            if m == 'sbb' and same:
                self.emit('%s = CF ? 0x%s : 0;' % (A0, 'ff' if sz == 1 else 'ffff'))
                if live:
                    self.emit(' '.join(c for c in ['ZF = !CF;' if 'Z' in live else '', 'SF = CF;' if 'S' in live else '',
                                                   'OF = 0;' if 'O' in live else ''] if c))
                return
            sop = {'add': '+', 'sub': '-', 'and': '&', 'or': '|', 'xor': '^'}.get(m)
            if sop is None:
                short = None
            elif dst.type == X86_OP_REG:
                short = '%s %s= %s;' % (A0, sop, B0)
            else:
                short = wr(i, dst, '(%s)(%s %s %s)' % (ct, A0, sop, B0))
        if short and not live:
            self.emit(short)
            return
        if short and j and dst.type == X86_OP_REG and m != 'neg':
            ce = self.cond_expr(j.mnemonic, m, sz, None, None, A0)
            if ce:
                self.emit(short)
                self.fold[nxt] = ce
                return
        self.emit('{ %s a_ = %s, b_ = %s; unsigned r_ = %s;' % (ct, A0, B0, opx))
        self.emit('  ' + wr(i, dst, '(%s)r_' % ct))
        for c in self.flags_code(live, m, sz, 'a_', 'b_', 'r_'):
            self.emit('  ' + c)
        self.emit('}')

    def shift(self, a, i):
        m = i.mnemonic
        dst, cnt = i.operands
        sz = dst.size
        ct = cast(sz)
        A0 = rd(i, dst)
        live = self.lo[a] & ALLF
        n = '1' if (cnt.type == X86_OP_IMM and cnt.imm == 1) else rd(i, cnt)
        sb = signbit(sz)
        if m in ('rcl', 'rcr'):
            assert n == '1', '%05x' % a
            if m == 'rcl':
                self.emit('{ %s a_ = %s; unsigned c_ = CF; CF = (a_ >> %d) & 1; %s' % (
                    ct, A0, sb, wr(i, dst, '(%s)((a_ << 1) | c_)' % ct)))
                if 'O' in live:
                    self.emit('  OF = ((a_ >> %d) & 1) ^ CF;' % sb)
            else:
                self.emit('{ %s a_ = %s; unsigned c_ = CF; CF = a_ & 1; %s' % (
                    ct, A0, wr(i, dst, '(%s)((a_ >> 1) | (c_ << %d))' % (ct, sb))))
                if 'O' in live:
                    self.emit('  OF = ((a_ >> %d) & 1) ^ c_;' % sb)
            self.emit('}')
            return
        if m == 'sar':
            expr = '(%s)((%s)a_ >> n_)' % (ct, scast(sz))
        elif m == 'shl':
            expr = '(%s)((unsigned)a_ << n_)' % ct
        else:
            expr = '(%s)(a_ >> n_)' % ct
        if not live:
            if dst.type == X86_OP_REG and m != 'sar':
                self.emit('%s %s= %s;' % (A0, '<<' if m == 'shl' else '>>', n if n == '1' else '(%s & 0x1f)' % n))
            else:
                self.emit('{ %s a_ = %s; unsigned n_ = %s & 0x1f; %s }' % (ct, A0, n, wr(i, dst, expr)))
            return
        self.emit('{ %s a_ = %s; unsigned n_ = %s & 0x1f;' % (ct, A0, n))
        self.emit('  if (n_) { %s r_ = %s;' % (ct, expr))
        self.emit('    ' + wr(i, dst, 'r_'))
        if 'C' in live:
            if m == 'shl':
                self.emit('    CF = n_ <= %d ? (a_ >> (%d - n_)) & 1 : 0;' % (sb + 1, sb + 1))
            elif m == 'sar':
                self.emit('    CF = (((%s)a_ >> (n_ - 1)) & 1);' % scast(sz))
            else:
                self.emit('    CF = n_ <= %d ? (a_ >> (n_ - 1)) & 1 : 0;' % (sb + 1))
        if 'Z' in live:
            self.emit('    ZF = (r_ == 0);')
        if 'S' in live:
            self.emit('    SF = (r_ >> %d) & 1;' % sb)
        if 'O' in live:
            if m == 'shl':
                self.emit('    OF = ((r_ >> %d) & 1) ^ CF;' % sb)
            elif m == 'sar':
                self.emit('    OF = 0;')
            else:
                self.emit('    OF = (a_ >> %d) & 1;' % sb)
        self.emit('  }')
        self.emit('}')
        # 접을 수 있으면 (shl/shr 뒤 je/jne/js/jns): 결과로 판단 -- 여기서는 접지 않는다

    def rot(self, a, i):
        m = i.mnemonic
        dst, cnt = i.operands
        sz = dst.size
        ct = cast(sz)
        bits = sz * 8
        A0 = rd(i, dst)
        live = self.lo[a] & frozenset('CO')
        n = '1' if (cnt.type == X86_OP_IMM and cnt.imm == 1) else rd(i, cnt)
        sb = bits - 1
        if m == 'rol':
            expr = '(%s)((a_ << k_) | (a_ >> (%d - k_)))' % (ct, bits)
        else:
            expr = '(%s)((a_ >> k_) | (a_ << (%d - k_)))' % (ct, bits)
        self.emit('{ %s a_ = %s; unsigned n_ = %s & 0x1f, k_ = n_ %% %d;' % (ct, A0, n, bits))
        self.emit('  if (n_) { %s r_ = k_ ? %s : a_;' % (ct, expr))
        self.emit('    ' + wr(i, dst, 'r_'))
        if live:
            if m == 'rol':
                self.emit('    CF = r_ & 1;')
                if 'O' in live:
                    self.emit('    OF = ((r_ >> %d) & 1) ^ CF;' % sb)
            else:
                self.emit('    CF = (r_ >> %d) & 1;' % sb)
                if 'O' in live:
                    self.emit('    OF = ((r_ >> %d) ^ (r_ >> %d)) & 1;' % (sb, sb - 1))
        self.emit('  }')
        self.emit('}')

    def jcc_cond(self, a, m):
        if a in self.fold:
            return self.fold[a]
        return {'je': 'ZF', 'jne': '!ZF', 'jl': 'SF != OF', 'jge': 'SF == OF', 'jg': '!ZF && SF == OF',
                'jle': 'ZF || SF != OF', 'jb': 'CF', 'jae': '!CF', 'jns': '!SF', 'js': 'SF',
                'ja': '!CF && !ZF', 'jbe': 'CF || ZF'}[m]

    def strop(self, a, i):
        m = i.mnemonic
        rep = m.split()[0] if ' ' in m else ''
        base = m.split()[-1]
        seg_src = 'DS_'
        for op in i.operands:
            if op.type == X86_OP_MEM and op.mem.base and i.reg_name(op.mem.base) == 'si' and op.mem.segment:
                seg_src = R16[i.reg_name(op.mem.segment)]
        one = {
            'movsb': 'MOVSB(%s);' % seg_src,
            'movsw': 'MOVSW(%s);' % seg_src,
            'stosb': 'STOSB();',
            'stosw': 'STOSW();',
            'lodsb': 'LODSB(%s);' % seg_src,
            'lodsw': 'LODSW(%s);' % seg_src,
        }
        if base in one:
            if rep and base == 'movsb':
                self.emit('REP_MOVSB(%s);' % seg_src)
            elif rep:
                self.emit('while (CX) { %s CX--; }' % one[base])
            else:
                self.emit(one[base])
            return
        if base in ('scasb', 'cmpsb', 'cmpsw'):
            w = 2 if base == 'cmpsw' else 1
            ct = cast(w)
            if base == 'scasb':
                load = 'uint8_t a_ = AL, b_ = RB(ES_, DI); DI += DF ? -1 : 1;'
            else:
                load = '%s a_ = %s(%s, SI), b_ = %s(ES_, DI); SI += DF ? -%d : %d; DI += DF ? -%d : %d;' % (
                    ct, 'RB' if w == 1 else 'RW', seg_src, 'RB' if w == 1 else 'RW', w, w, w, w)
            flags = 'unsigned r_ = (unsigned)a_ - b_; ZF = ((%s)r_ == 0); CF = (a_ < b_); SF = (r_ >> %d) & 1; ' \
                    'OF = (((a_ ^ b_) & (a_ ^ r_)) >> %d) & 1;' % (ct, signbit(w), signbit(w))
            if rep:
                cond = 'ZF' if rep == 'repe' else '!ZF'
                self.emit('while (CX) { %s %s CX--; if (!(%s)) break; }' % (load, flags, cond))
            else:
                self.emit('{ %s %s }' % (load, flags))
            return
        raise Exception('strop %s' % m)

    def dispatch_to(self, key_expr):
        self.emit('jkey = %s; goto dispatch;' % key_expr)

    def ins(self, a, i):
        m = i.mnemonic
        ops = i.operands
        seg = iseg[a]
        nxt = a + i.size
        nxt_off = nxt - seg * 16
        base = seg * 16
        if m == 'mov':
            self.emit(wr(i, ops[0], rd(i, ops[1], ops[0].size)))
        elif m == 'lea':
            s, off = mem_addr(i, ops[1])
            self.emit('%s = %s;' % (R16[i.reg_name(ops[0].reg)], off))
        elif m in ('lds', 'les'):
            s, off = mem_addr(i, ops[1])
            self.emit('{ uint16_t o_ = RW(%s, %s), s_ = RW(%s, (uint16_t)(%s + 2)); %s = o_; %s = s_; }' % (
                s, off, s, off, R16[i.reg_name(ops[0].reg)], 'DS_' if m == 'lds' else 'ES_'))
        elif m == 'xchg':
            A0, B0 = rd(i, ops[0]), rd(i, ops[1])
            ct = cast(ops[0].size)
            self.emit('{ %s t_ = %s; %s %s }' % (ct, A0, wr(i, ops[0], B0), wr(i, ops[1], 't_')))
        elif m == 'push':
            if ops[0].type == X86_OP_REG and i.reg_name(ops[0].reg) == 'sp':
                self.emit('PUSH((uint16_t)(SP - 2));')
            else:
                self.emit('PUSH(%s);' % rd(i, ops[0]))
        elif m == 'pop':
            if ops[0].type == X86_OP_REG:
                self.emit('%s = POP();' % R16[i.reg_name(ops[0].reg)])
            else:
                self.emit('{ uint16_t t_ = POP(); %s }' % wr(i, ops[0], 't_'))
        elif m in ('add', 'sub', 'adc', 'sbb', 'and', 'or', 'xor', 'cmp', 'test', 'inc', 'dec', 'neg', 'not'):
            self.alu(a, i)
        elif m in ('rol', 'ror'):
            self.rot(a, i)
        elif m in ('shl', 'shr', 'sar', 'rcl', 'rcr'):
            self.shift(a, i)
        elif m == 'mul':
            s = rd(i, ops[0])
            if ops[0].size == 1:
                self.emit('AX = (uint16_t)(AL * %s);' % s)
                if self.lo[a] & frozenset('CO'):
                    self.emit('CF = OF = (AH != 0);')
            else:
                self.emit('{ uint32_t p_ = (uint32_t)AX * %s; AX = (uint16_t)p_; DX = (uint16_t)(p_ >> 16); }' % s)
                if self.lo[a] & frozenset('CO'):
                    self.emit('CF = OF = (DX != 0);')
        elif m == 'imul':
            s = rd(i, ops[0])
            assert len(ops) == 1
            if ops[0].size == 1:
                self.emit('AX = (uint16_t)(int16_t)((int8_t)AL * (int8_t)%s);' % s)
                if self.lo[a] & frozenset('CO'):
                    self.emit('CF = OF = ((int16_t)AX != (int8_t)AL);')
                return
            self.emit('{ int32_t p_ = (int32_t)(int16_t)AX * (int16_t)%s; AX = (uint16_t)p_; DX = (uint16_t)((uint32_t)p_ >> 16); }' % s)
            if self.lo[a] & frozenset('CO'):
                self.emit('CF = OF = ((int32_t)(int16_t)AX != (int32_t)(((uint32_t)DX << 16) | AX));')
        elif m == 'div':
            s = rd(i, ops[0])
            if ops[0].size == 1:
                self.emit('{ uint8_t d_ = %s; uint16_t n_ = AX; if (!d_ || n_ / d_ > 0xff) or_fault(0x%05x, 1);'
                          ' AL = (uint8_t)(n_ / d_); AH = (uint8_t)(n_ %% d_); }' % (s, a))
            else:
                self.emit('{ uint16_t d_ = %s; uint32_t n_ = ((uint32_t)DX << 16) | AX;'
                          ' if (!d_ || n_ / d_ > 0xffff) or_fault(0x%05x, 1);'
                          ' AX = (uint16_t)(n_ / d_); DX = (uint16_t)(n_ %% d_); }' % (s, a))
        elif m == 'idiv':
            s = rd(i, ops[0])
            if ops[0].size == 1:
                self.emit('{ int8_t d_ = (int8_t)%s; int16_t n_ = (int16_t)AX; int q_; if (!d_) or_fault(0x%05x, 1);'
                          ' q_ = n_ / d_; if (q_ > 127 || q_ < -128) or_fault(0x%05x, 1);'
                          ' AL = (uint8_t)q_; AH = (uint8_t)(n_ %% d_); }' % (s, a, a))
            else:
                self.emit('{ int16_t d_ = (int16_t)%s; int32_t n_ = (int32_t)(((uint32_t)DX << 16) | AX); int32_t q_;'
                          ' if (!d_) or_fault(0x%05x, 1); q_ = n_ / d_; if (q_ > 32767 || q_ < -32768) or_fault(0x%05x, 1);'
                          ' AX = (uint16_t)q_; DX = (uint16_t)(n_ %% d_); }' % (s, a, a))
        elif m == 'lahf':
            # AF/PF 는 따지지 않는다 (에뮬레이터도 lahf 뒤 AH 에 같은 가면)
            self.emit('AH = (uint8_t)(0x02 | CF | (ZF << 6) | (SF << 7));')
        elif m == 'sahf':
            self.emit('CF = AH & 1; ZF = (AH >> 6) & 1; SF = (AH >> 7) & 1;')
        elif m == 'daa':
            # 앞이 and al,0f (AF=0) 인 곳뿐
            self.emit('{ uint8_t o_ = AL; int c_ = CF; if ((AL & 0xf) > 9) AL += 6; if (o_ > 0x99 || c_) { AL += 0x60; CF = 1; } else CF = 0;'
                      ' ZF = (AL == 0); SF = AL >> 7; }')
        elif m == 'aaa':
            # 앞이 inc al 인 곳뿐: AF = 낮은 네 비트가 넘침 (결과 낮은 네 비트 0)
            pv = code.get(a - 2)
            assert pv is not None and pv.mnemonic == 'inc' and pv.op_str == 'al', '%05x' % a
            self.emit('if ((AL & 0xf) > 9 || (AL & 0xf) == 0) { AL += 6; AH++; CF = 1; } else CF = 0; AL &= 0xf;')
        elif m == 'cwde' or m == 'cbw':
            self.emit('AX = (uint16_t)(int16_t)(int8_t)AL;')
        elif m == 'cdq' or m == 'cwd':
            self.emit('DX = (AX & 0x8000) ? 0xffff : 0;')
        elif m == 'cli':
            self.emit('IF_ = 0;')
        elif m == 'sti':
            self.emit('IF_ = 1;')
        elif m == 'nop':
            pass
        elif m == 'hlt':
            self.emit('or_fault(0x%05x, 2);' % a)
        elif m == 'pushf':
            self.emit('PUSH(GETFLAGS());')
        elif m == 'popf':
            self.emit('SETFLAGS(POP());')
        elif m == 'cld':
            self.emit('DF = 0;')
        elif m == 'std':
            self.emit('DF = 1;')
        elif m == 'stc':
            self.emit('CF = 1;')
        elif m == 'clc':
            self.emit('CF = 0;')
        elif m == 'cmc':
            self.emit('CF = !CF;')
        elif m == 'xlatb':
            seg_src = 'DS_'
            for op in ops:
                if op.type == X86_OP_MEM and op.mem.segment:
                    seg_src = R16[i.reg_name(op.mem.segment)]
            self.emit('AL = RB(%s, (uint16_t)(BX + AL));' % seg_src)
        elif m.startswith('rep') or m in ('lodsb', 'lodsw', 'stosb', 'stosw', 'movsb', 'movsw', 'scasb', 'cmpsb', 'cmpsw'):
            self.strop(a, i)
        elif m == 'int':
            n = ops[0].imm
            if n == 0x20:
                self.emit('return;')
            elif n == 0x19:
                self.emit('or_fault(0x%05x, 4);' % a)
            elif n == 0x16:
                self.emit('while (or_int16_wait()) or_poll(); do_int(0x16);')
            else:
                self.emit('do_int(0x%02x);' % n)
        elif m == 'in':
            self.emit('%s = io_in(%s);' % (rd(i, ops[0]), rd(i, ops[1])))
        elif m == 'out':
            if ops[1].size == 2:
                self.emit('io_outw(%s, %s);' % (rd(i, ops[0]), rd(i, ops[1])))
            else:
                self.emit('io_out(%s, %s);' % (rd(i, ops[0]), rd(i, ops[1])))
        # ---- 흐름 ----
        elif m == 'call':
            r_off = nxt_off              # 인라인 인자가 있으면 불린 쪽이 건너뛴다
            if ops[0].type == X86_OP_IMM:
                t = tgt(i)
                self.emit('PUSH(0x%04x); goto %s;%s' % (r_off, lab(t), (' /* %s */' % names[t]) if t in names else ''))
            else:
                self.emit('{ uint16_t o_ = %s; PUSH(0x%04x); jkey = 0x%05x + o_; goto dispatch; }' % (rd(i, ops[0]), r_off, base))
        elif m == 'lcall':
            r_off = nxt_off
            if ops[0].type == X86_OP_IMM:
                s, o = scan.w16(a + 3), scan.w16(a + 1)
                t = s * 16 + o
                self.emit('PUSH(CS_); PUSH(0x%04x); CS_ = SEG(0x%x); goto %s;%s' % (
                    r_off, s, lab(t), (' /* %s */' % names[t]) if t in names else ''))
            else:
                s, off = mem_addr(i, ops[0])
                self.emit('{ uint16_t o_ = RW(%s, %s), s_ = RW(%s, (uint16_t)(%s + 2));' % (s, off, s, off))
                self.emit('  PUSH(CS_); PUSH(0x%04x); CS_ = s_; jkey = KEY(s_, o_); goto dispatch; }' % r_off)
        elif m == 'ret':
            n = ops[0].imm if ops else 0
            self.emit('{ uint16_t o_ = POP(); %sjkey = 0x%05x + o_; goto dispatch; }' % (
                ('SP += %d; ' % n) if n else '', base))
        elif m == 'retf':
            n = ops[0].imm if ops else 0
            self.emit('{ uint16_t o_ = POP(); CS_ = POP(); %sjkey = KEY(CS_, o_); goto dispatch; }' % (
                ('SP += %d; ' % n) if n else ''))
        elif m == 'iret':
            self.emit('{ uint16_t o_ = POP(); CS_ = POP(); SETFLAGS(POP()); irq_leave(); jkey = KEY(CS_, o_); goto dispatch; }')
        elif m == 'jmp':
            if ops[0].type == X86_OP_IMM:
                if a in POLL:
                    head = POLL[a]
                    self.emit('POLL_POINT(0x%04x); goto %s;' % (head - base, lab(head)))
                else:
                    self.emit('goto %s;' % lab(tgt(i)))
            else:
                self.emit('jkey = 0x%05x + %s; goto dispatch;' % (base, rd(i, ops[0])))
        elif m == 'ljmp':
            if ops[0].type == X86_OP_IMM and (a + 3) not in RELOC:
                # 재배치 없는 절대 주소 (BALL 의 Ctrl+Alt+Del -> FFFF:0000): or_unknown 이 받는다
                s, o = scan.w16(a + 3), scan.w16(a + 1)
                self.emit('CS_ = 0x%x; jkey = KEY(CS_, 0x%x); goto dispatch;' % (s, o))
            elif ops[0].type == X86_OP_IMM:
                s, o = scan.w16(a + 3), scan.w16(a + 1)
                self.emit('CS_ = SEG(0x%x); goto %s;' % (s, lab(s * 16 + o)))
            else:
                s, off = mem_addr(i, ops[0])
                self.emit('{ uint16_t o_ = RW(%s, %s), s_ = RW(%s, (uint16_t)(%s + 2)); CS_ = s_; jkey = KEY(s_, o_); goto dispatch; }' % (
                    s, off, s, off))
        elif m in JCC:
            t = tgt(i)
            if a in POLL:
                head = POLL[a]
                self.emit('if (%s) { POLL_POINT(0x%04x); goto %s; }' % (self.jcc_cond(a, m), head - base, lab(head)))
            else:
                self.emit('if (%s) goto %s;' % (self.jcc_cond(a, m), lab(t)))
        elif m == 'loop' and a in SPINS:
            self.emit('SPIN();')
        elif m == 'loop':
            self.emit('if (--CX) goto %s;' % lab(tgt(i)))
        elif m == 'loopne':
            self.emit('if (--CX && !ZF) goto %s;' % lab(tgt(i)))
        elif m == 'loope':
            self.emit('if (--CX && ZF) goto %s;' % lab(tgt(i)))
        elif m == 'jcxz':
            self.emit('if (CX == 0) goto %s;' % lab(tgt(i)))
        else:
            raise Exception('%05x %s %s' % (a, m, i.op_str))


ENDS = ('jmp', 'ret', 'retf', 'ljmp', 'iret', 'hlt')


def main():
    lin, lout, it = liveness()
    addrs = sorted(code)
    labels = set(DISPATCH)
    for a in addrs:
        i = code[a]
        m = i.mnemonic
        if (m in ('jmp', 'call', 'ljmp', 'lcall') or m in JCC or m.startswith('loop') or m == 'jcxz') and \
                i.operands[0].type == X86_OP_IMM and not (m in ('ljmp', 'lcall') and (a + 3) not in RELOC):
            labels.add(far_tgt(a) if m in ('ljmp', 'lcall') else tgt(i))
    # 앞 명령에서 흘러 들어오지 않는 곳도 레이블 (앞이 자료거나 다른 흐름)
    prev_end = None
    NEXT = {}
    for k, a in enumerate(addrs):
        if prev_end != a:
            labels.add(a)
        prev_end = a + code[a].size
        NEXT[a] = addrs[k + 1] if k + 1 < len(addrs) else None
        # 겹친 명령 (다른 흐름이 한 바이트 어긋나 읽은 것): 흘러가는 곳이 바로 다음 줄이 아니면 goto
        if prev_end in code and NEXT[a] != prev_end:
            labels.add(prev_end)
    g = Gen(lin, lout, labels)
    # 블록 머리(레이블, 흐름 바뀐 다음)마다 그 블록의 8088 클럭 합
    starts = set(labels)
    for a in addrs:
        i = code[a]
        m = i.mnemonic
        if m in ENDS or m in JCC or m.startswith('loop') or m in ('call', 'lcall', 'jcxz', 'int') or a in POLLAT:
            starts.add(a + i.size)
    starts |= POLLAT
    blockcost = {}
    for a in addrs:
        if a not in starts:
            continue
        t = 0
        b = a
        while b in code:
            t += icost(code[b])
            nb = b + code[b].size
            m = code[b].mnemonic
            if nb in starts or m in ENDS:
                break
            b = nb
        blockcost[a] = t
    out = []
    w = out.append
    w('/* or_code.c - Off-Road (%s) 를 tools/asm2c.py 로 옮긴 것.  손대지 말 것. */' % image.EXE)
    w('#include "cpu.h"')
    w('')
    w('void or_run_code(void)')
    w('{')
    w('    uint32_t jkey;')
    w('    CS_ = SEG(0x%x);' % image.GSEG_SYS)
    w('    goto %s;' % lab(image.GSEG_SYS * 16 + image.GH[10]))
    prev_end = None
    prev_m = None
    nl = 0
    for a in addrs:
        i = code[a]
        seg = iseg[a]
        if a in labels:
            if a in funcs or a in names:
                w('')
                w('/* ---- %s */' % names.get(a, 'f_%04x_%04x' % (seg, a - seg * 16)))
            w('%s:' % lab(a))
        g.out = []
        g.emit("TR(0x%05x);" % a)
        if a in blockcost:
            g.emit('CYC(%d);' % blockcost[a])
        if a in POLLAT:
            g.emit('or_poll();')
        if a in DELAYS:
            g.emit('or_delay(%d);' % DELAYS[a])
        if a in VHOOKS:
            g.emit('VH(0x%05x);' % a)
        if a in FAST:
            g.emit('{ uint32_t k_ = %s(0x%05x); if (k_) { jkey = k_; goto dispatch; } }' % FAST[a])
        g.ins(a, i)
        txt = '/* %04x:%04x %s %s */' % (seg, a - seg * 16, i.mnemonic, i.op_str)
        body = ' '.join(g.out)
        w('    %s %s' % (body, txt) if body else '    %s' % txt)
        nl += 1
        prev_end = a + i.size
        prev_m = i.mnemonic
        if a in scan.swtabs:
            pass
        elif (prev_m not in ENDS and not (prev_m == 'int' and i.operands[0].imm in (0x19, 0x20))) and prev_end not in code:
            w('    or_fault(0x%05x, 3);' % prev_end)
        elif prev_m not in ENDS and NEXT[a] != prev_end and not (prev_m == 'int' and i.operands[0].imm in (0x19, 0x20)):
            w('    goto %s;' % lab(prev_end))
    w('')
    w('dispatch:')
    w('    switch (jkey) {')
    for a in sorted(DISPATCH):
        w('    case 0x%05x: goto %s;' % (a, lab(a)))
    w('    }')
    w('    if (jkey == KEY(PSPSEG, 0)) return;          /* retf 로 PSP:0000 (int 20h) */')
    w('    jkey = or_unknown(jkey);')
    w('    goto dispatch;')
    w('}')
    fn = os.path.join(ROOT, 'or_code.c')
    open(fn, 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
    print('%s: %d instructions, %d labels, %d dispatch, %d polls, %d fast, liveness iters %d' % (
        os.path.basename(fn), nl, len(labels), len(DISPATCH), len(POLL), len(FAST), it))


if __name__ == '__main__':
    main()
