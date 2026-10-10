# 무작위 키 대본 만들기: python tools/monkey.py 씨앗 틱수 > 대본.txt
#   기계 고르기(1-5) -> 안내 두 장 -> 제목 -> 게임 (오른쪽=가속, 왼쪽=감속, 위=점프, 스페이스=쏘기,
#   가끔 P 멈춤, Ctrl+R 다시 시작, 제목에서 아무 키)
#   원판은 프레임마다 BIOS 버퍼에서 키 하나를 꺼내므로 '누르고 있기' 는 같은 키를 여러 번 넣는 것.
import random, sys

seed, n = int(sys.argv[1]), int(sys.argv[2])
R = random.Random(seed)
out = ['3 +%s' % R.choice('12345'), '8 +%s' % R.choice(['space', 'enter', 'x']), '13 +space', '%d +space' % R.randint(20, 60)]
t = 70
while t < n:
    r = R.random()
    if r < 0.30:
        out.append('%d +up' % t)
    elif r < 0.55:
        out.append('%d +space' % t)
    elif r < 0.75:
        k = R.choice(['right', 'right', 'left'])
        for j in range(R.randint(1, 8)):
            out.append('%d +%s' % (t, k))
            t += R.randint(1, 3)
    elif r < 0.95:
        out.append('%d +%s' % (t, R.choice(['enter', 'a', 'down'])))
    elif r < 0.97:
        out.append('%d +p' % t)
        t += R.randint(5, 40)
        out.append('%d +p' % t)
    elif r < 0.975:
        out.append('%d +ctrl 6' % t)
        out.append('%d +r' % (t + 2))
        t += 4
    else:
        t += R.randint(30, 200)       # 손 놓기
    t += R.randint(1, 12)
print('\n'.join(out))
