# CGA(hosttest) 와 256색(hostvga) 을 같은 대본/틱으로 찍어 나란히: python tools/vshots.py 대본 out.png 틱...
import sys, os, subprocess
from PIL import Image
R = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
script, out = sys.argv[1], sys.argv[2]
ticks = [int(t) for t in sys.argv[3:]]
mx = max(ticks) + 1
for exe, p in (('hosttest.exe', 'c'), ('hostvga.exe', 'v')):
    subprocess.run([os.path.join(R, exe), script, str(mx), '-'] + ['%d:_s%s%d.bmp' % (t, p, t) for t in ticks], cwd=R,
                   capture_output=True)
W = Image.new('RGB', (644, 202 * len(ticks)), (60, 60, 60))
for k, t in enumerate(ticks):
    for j, p in enumerate('cv'):
        fn = os.path.join(R, '_s%s%d.bmp' % (p, t))
        if os.path.exists(fn):
            W.paste(Image.open(fn).convert('RGB'), (j * 324, k * 202))
            os.remove(fn)
W.resize((W.width * 2, W.height * 2), Image.NEAREST).save(out)
