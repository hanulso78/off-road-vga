# 실행 안 된 코드 구간 (tools/_blocks.txt 블록 시작 기준)
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan, image
B = image.CSEG * 16
ENDM = ('jmp', 'ret', 'retf', 'iret', 'call', 'ljmp', 'lcall', 'int', 'loop', 'jcxz') + tuple(
    'je jne jl jg jge jle jb jae jns js ja jbe loope loopne'.split())
cov = set()
for ln in open(os.path.join(scan.HERE, '_blocks.txt')).read().split():
    s, o = [int(x, 16) for x in ln.split(':')]
    a = s * 16 + o
    while a in scan.code:
        cov.add(a)
        i = scan.code[a]
        if i.mnemonic in ENDM:
            break
        a += i.size
un = sorted(a for a in scan.code if a not in cov)
print('covered %d / %d' % (len(cov), len(scan.code)))
runs = []
for a in un:
    if runs and a - runs[-1][1] < 12:
        runs[-1][1] = a
    else:
        runs.append([a, a])
for s, e in runs:
    print('%04x-%04x' % (s - B, e - B))
