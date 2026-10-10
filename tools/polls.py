# 폴 지점 (틱 하나가 흐르는 곳)
#   Off-Road 는 타이머/자판 인터럽트를 걸지 않는다.  주 되돌이가 한 프레임 일을 하고
#   "mov cx,[004C] / loop $" 로 CPU 속도만큼 쉰 뒤 BIOS 자판 버퍼를 들여다본다.
#   그래서 프레임 끝의 빈 되돌이 앞이 폴 지점 (= 틱): 거기서 자판 스캔 코드를 BIOS 버퍼에 넣는다.
#     0633 주 되돌이 (게임), 078B 제목 되돌이
#   int 16h AH=0 (키 기다림) 자리는 키가 올 때까지 폴한다.
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import scan, image

B = image.CSEG * 16
POLLAT = [B + 0x06AF, B + 0x0794]
# 제자리 빈 되돌이 (loop $): 옮긴 C 는 CX = 0 으로 끝낸다 (시간은 sys_dos 가 틱으로 맞춤)
SPINS = sorted(a for a, i in scan.code.items()
               if i.mnemonic == 'loop' and (i.operands[0].imm & 0xFFFFF) == a)
POLLS = []
INT16 = sorted(a for a, i in scan.code.items() if i.mnemonic == 'int' and i.operands[0].imm == 0x16)
if __name__ == '__main__':
    print('poll at:', ' '.join('%04x' % (a - B) for a in POLLAT))
    print('spins:', ' '.join('%04x' % (a - B) for a in SPINS))
    print('int16:', ' '.join('%04x' % (a - B) for a in INT16))
