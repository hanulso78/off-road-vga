
#   python tools/dosshot.py 대본.txt 결과.png [exe] [인자]
#   대본 줄: "틱 +키 [누름]" / "틱 스캔16진" / "틱 shot 이름" / "틱 quit"
#   환경: CYCLES (기본 max), ORDIR (다른 폴더, 예: release), KEEP=1 (BMP 남김), REAL=1 (시간 맞춤 켬)
import os, sys, subprocess, glob, tempfile
from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.environ.get('ORDIR') or os.path.abspath(os.path.join(HERE, '..'))
DOSBOX = os.path.abspath(os.path.join(HERE, '..', '..', '..', 'dosbox', 'dosbox.exe'))

script, out = sys.argv[1], sys.argv[2]
exe = sys.argv[3] if len(sys.argv) > 3 else 'orc.exe'
arg = sys.argv[4] if len(sys.argv) > 4 else ''
open(os.path.join(ROOT, 'ORTEST.TXT'), 'w').write(open(script, encoding='utf-8').read().encode('ascii', 'ignore').decode())
_shots = [ln.split()[2] for ln in open(script, encoding='utf-8') if len(ln.split()) >= 3 and ln.split()[1] == 'shot']
for f in [os.path.join(ROOT, n.upper() + '.BMP') for n in _shots] + [os.path.join(ROOT, 'ORLOG.TXT')]:
    if os.path.exists(f):
        os.remove(f)
conf = os.path.join(tempfile.gettempdir(), 'scrun.conf')
open(conf, 'w').write('''[dosbox]
machine=svga_s3
memsize=32
[speaker]
pcspeaker=false
tandy=off
[sblaster]
sbtype=%s
[gus]
gus=false
[mixer]
nosound=true
[cpu]
core=auto
cycles=%s
[autoexec]
mount C "%s"
C:
set ORTEST=ORTEST.TXT
%s
%s
%s %s > OROUT.TXT
exit
''' % ('sb16' if os.environ.get('ADLIB') else 'none', os.environ.get('CYCLES', 'max'), ROOT,
       ('set ORREAL=1' if os.environ.get('REAL') else ''), os.environ.get('EXTRA', '').replace(';', chr(10)), exe, arg))
# 화면 밖에서 (창을 띄우지 않음): SDL 1.2 dummy 비디오
subprocess.run([DOSBOX, '-conf', conf, '-noconsole'], cwd=os.path.dirname(DOSBOX), timeout=900,
               env=dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy'))
names = [ln.split()[2] for ln in open(script, encoding='utf-8') if len(ln.split()) >= 3 and ln.split()[1] == 'shot']
imgs = []
for n in names:
    fn = os.path.join(ROOT, n.upper() + '.BMP')
    if os.path.exists(fn):
        imgs.append(Image.open(fn).convert('RGB'))
        if not os.environ.get('KEEP'):
            os.remove(fn)
cols = 3
W = Image.new('RGB', (cols * 322, max(1, (len(imgs) + cols - 1) // cols) * 202), (60, 60, 60))
for i, im in enumerate(imgs):
    W.paste(im, ((i % cols) * 322, (i // cols) * 202))
W = W.resize((W.width * 2, W.height * 2), Image.NEAREST)
W.save(out)
print('%d shots' % len(imgs))
log = os.path.join(ROOT, 'ORLOG.TXT')
if os.path.exists(log):
    print(open(log).read().strip())
out2 = os.path.join(ROOT, 'OROUT.TXT')
if os.path.exists(out2) and open(out2, 'rb').read().strip():
    print('stdout:', open(out2, 'rb').read().decode('latin1').strip()[-2000:])
