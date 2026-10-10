# Off-Road (Montsoft 1988, IBM CGA) 원판을 unicorn 실모드로 돌리는 기준 에뮬레이터
#   - CGA 화면은 B800 평면 메모리 그대로 (모드 4, 320x200 4색 / 글자 모드 3 은 80x25 글자+속성)
#   - 시계 (옮긴 C 의 orrt.c 와 같은 규칙, 결정적):
#       폴 자리 (tools/polls.py POLLAT: 프레임 끝) 마다 틱 하나, 그 틱까지 온 스캔 코드를
#       BIOS int 9 흉내로 자판 버퍼(0040:001E-003D)에 넣는다.  int 16h AH=0 이 빈 버퍼를 읽으려
#       하면 키가 올 때까지 폴한다.  원판은 인터럽트를 걸지 않는다.
import struct, sys, os
from unicorn import *
from unicorn.x86_const import *

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import image
from image import LOADSEG, PSP, ROOT

BIOSSEG = 0xF000
MEMTOP = 0x9FFF


class Exit(Exception):
    pass


ASCII = {}
for _row, _sc in (('1234567890-=', 2), ('qwertyuiop[]', 0x10), ("asdfghjkl;'`", 0x1E), ('\\zxcvbnm,./', 0x2B)):
    for _k, _c in enumerate(_row):
        ASCII[_sc + _k] = ord(_c)
ASCII.update({0x01: 27, 0x0E: 8, 0x0F: 9, 0x1C: 13, 0x39: 32})

BASE16 = [(0, 0, 0), (0, 0, 170), (0, 170, 0), (0, 170, 170), (170, 0, 0), (170, 0, 170), (170, 85, 0), (170, 170, 170),
          (85, 85, 85), (85, 85, 255), (85, 255, 85), (85, 255, 255), (255, 85, 85), (255, 85, 255), (255, 255, 85), (255, 255, 255)]


def cga_rgb(vmode, color_reg):
    bg = color_reg & 15
    pal = (color_reg >> 5) & 1
    inten = 8 if color_reg & 0x10 else 0
    if vmode == 5:
        c = [3, 4, 7]
    else:
        c = [3, 5, 7] if pal else [2, 4, 6]
    return [BASE16[bg]] + [BASE16[x + inten] for x in c]


class Machine:
    def __init__(self, keys=None):
        mu = self.mu = Uc(UC_ARCH_X86, UC_MODE_16)
        mu.mem_map(0, 0x110000)
        img = bytearray(image.GIMG)
        for r in image.RELOC:
            v = struct.unpack('<H', img[r:r + 2])[0]
            img[r:r + 2] = struct.pack('<H', (v + LOADSEG) & 0xFFFF)
        mu.mem_write(LOADSEG * 16, bytes(img))
        h = image.GH
        mu.mem_write(PSP * 16, b'\xcd\x20')
        mu.mem_write(PSP * 16 + 2, struct.pack('<H', MEMTOP + 1))
        mu.mem_write(PSP * 16 + 0x2C, struct.pack('<H', 0x0F00))
        mu.mem_write(0xF000, b'PATH=C:\\\0COMSPEC=C:\\COMMAND.COM\0\0\x01\0C:\\OFFROAD.EXE\0')
        mu.mem_write(PSP * 16 + 0x80, b'\x00\r')
        for n in range(256):
            mu.mem_write(n * 4, struct.pack('<HH', n * 4, BIOSSEG))
            mu.mem_write(BIOSSEG * 16 + n * 4, bytes([0xCD, n, 0xCF, 0x90]))
        mu.mem_write(0x410, struct.pack('<H', 0x0021))
        mu.mem_write(0x41A, struct.pack('<HH', 0x1E, 0x1E))
        mu.mem_write(0x413, struct.pack('<H', 640))
        mu.mem_write(0x449, bytes([3]))
        mu.mem_write(0x44A, struct.pack('<H', 80))
        mu.mem_write(0x463, struct.pack('<H', 0x3D4))
        mu.mem_write(0x480, struct.pack('<HH', 0x1E, 0x3E))
        mu.mem_write(0xFFFFE, bytes([0xFC]))
        self.font = open(os.path.join(ROOT, 'ROMFONT.BIN'), 'rb').read()
        mu.mem_write(0xFFA6E, self.font)
        mu.mem_write(0xB8000, b'\x20\x07' * 0x2000)
        mu.reg_write(UC_X86_REG_EFLAGS, 0x0202)
        mu.reg_write(UC_X86_REG_CS, LOADSEG + h[11])
        mu.reg_write(UC_X86_REG_IP, h[10])
        mu.reg_write(UC_X86_REG_SS, LOADSEG + h[7])
        mu.reg_write(UC_X86_REG_SP, h[8])
        mu.reg_write(UC_X86_REG_DS, PSP)
        mu.reg_write(UC_X86_REG_ES, PSP)
        mu.hook_add(UC_HOOK_INTR, self.on_int)
        mu.hook_add(UC_HOOK_INSN, self.on_in, None, 1, 0, UC_X86_INS_IN)
        mu.hook_add(UC_HOOK_INSN, self.on_out, None, 1, 0, UC_X86_INS_OUT)
        self.keys = sorted(keys or [], key=lambda e: e[0])     # (틱, 스캔코드; 뗌은 |0x80)
        self.ticks = 0
        self.log = []
        self.vmode = 3
        self.port60 = 0
        self.cga_color = 0x30
        self.npoll = 0
        self.trace = None
        self.every = 1
        self.shotlist = {}
        self.stopped = False
        self.maxticks = 1 << 30
        self.kctrl = self.kshift = self.kalt = 0

    # ---- 포트 ----
    def on_out(self, mu, port, size, value, ud):
        if port == 0x3D9:
            self.cga_color = value & 0xFF

    def on_in(self, mu, port, size, ud):
        if port == 0x60:
            return self.port60
        if port == 0x40:
            return 0x5A
        if port == 0x21:
            return 0xB8
        return 0xFF

    def setzf(self, on):
        f = self.mu.reg_read(UC_X86_REG_EFLAGS)
        self.mu.reg_write(UC_X86_REG_EFLAGS, (f | 0x40) if on else (f & ~0x40))

    def r16(self, a):
        return struct.unpack('<H', self.mu.mem_read(a, 2))[0]

    def w16(self, a, v):
        self.mu.mem_write(a, struct.pack('<H', v & 0xFFFF))

    def bios_key(self, sc):
        k = sc & 0x7F
        up = sc & 0x80
        if k == 0x1D:
            self.kctrl = 0 if up else 1
            return
        if k in (0x2A, 0x36):
            self.kshift = 0 if up else 1
            return
        if k == 0x38:
            self.kalt = 0 if up else 1
            return
        if up or k in (0x3A, 0x45, 0x46):
            return
        a = ASCII.get(k, 0)
        if self.kalt:
            a = 0
        elif self.kctrl:
            a = a - 0x60 if ord('a') <= a <= ord('z') else 10 if a == 13 else 0
        elif self.kshift and ord('a') <= a <= ord('z'):
            a -= 0x20
        tail = self.r16(0x41C)
        nt = 0x1E if tail + 2 >= 0x3E else tail + 2
        if nt == self.r16(0x41A):
            return
        self.w16(0x400 + tail, (k << 8) | a)
        self.w16(0x41C, nt)

    def buf_empty(self):
        return self.r16(0x41A) == self.r16(0x41C)

    # ---- 시계 / 폴 (orrt.c or_poll 과 같은 규칙) ----
    def do_poll(self):
        self.npoll += 1
        self.ticks += 1
        if self.ticks in self.shotlist:
            self.screen(self.shotlist[self.ticks])
        if self.ticks >= self.maxticks:
            self.stopped = True
            self.mu.emu_stop()
            return
        while self.keys and self.keys[0][0] <= self.ticks:
            k = self.keys.pop(0)[1]
            self.port60 = k
            self.bios_key(k)
        self.cheat()
        if self.trace and self.npoll % self.every == 0:
            self.trace.write(self.state_line(0) + '\n')

    # 시험용 치트 (hosttest.c cheat 와 같게): INF=1 목숨, WARP=n 레벨 건너뛰기
    CHEAT_INF = int(os.environ.get('INF', '0'))
    CHEAT_WARP = int(os.environ.get('WARP', '0'))

    def cheat(self):
        D = (LOADSEG + 0x20) * 16
        mu = self.mu
        if self.CHEAT_INF:
            v = mu.mem_read(D + 0x4178, 2)
            if v[0] < 3 and v[1] == 0:
                mu.mem_write(D + 0x4178, b'\x05')
        if self.CHEAT_WARP:
            v = mu.mem_read(D + 0x5368, 2)
            if 1 <= v[0] < self.CHEAT_WARP and v[1] == 0:
                mu.mem_write(D + 0x417A, b'\x6c\x0c')

    # ---- 글자 모드 ----
    def is_text(self):
        return self.vmode <= 3 or self.vmode == 7

    def text_put(self, col, row, ch, attr):
        a = 0xB8000 + (row * 80 + col) * 2
        self.mu.mem_write(a, bytes([ch]))
        if attr is not None:
            self.mu.mem_write(a + 1, bytes([attr]))

    def text_tty(self, ch):
        mu = self.mu
        col, row = mu.mem_read(0x450, 2)
        if ch == 13:
            col = 0
        elif ch == 10:
            row += 1
        elif ch == 7:
            pass
        elif ch == 8:
            col = max(col - 1, 0)
        else:
            self.text_put(col, row, ch, None)
            col += 1
            if col >= 80:
                col = 0
                row += 1
        if row > 24:
            v = bytes(mu.mem_read(0xB8000 + 160, 24 * 160))
            mu.mem_write(0xB8000, v + b'\x20\x07' * 80)
            row = 24
        mu.mem_write(0x450, bytes([col, row]))

    def on_int(self, mu, n, ud):
        r = mu.reg_read
        w = mu.reg_write
        ax = r(UC_X86_REG_AX)
        ah, al = ax >> 8, ax & 0xFF
        bx = r(UC_X86_REG_BX)
        if n == 0x10:
            if ah == 0:
                self.vmode = al & 0x7F
                mu.mem_write(0x449, bytes([self.vmode]))
                mu.mem_write(0x450, b'\0\0')
                mu.mem_write(0xB8000, b'\x20\x07' * 0x2000 if self.is_text() else bytes(0x4000))
                self.cga_color = 0x30
                self.log.append('mode %02X' % al)
            elif ah == 0x05:
                mu.mem_write(0x462, bytes([al]))
            elif ah == 0x0B:
                if bx >> 8 == 0:
                    self.cga_color = (self.cga_color & 0xE0) | (bx & 0x1F)
                else:
                    self.cga_color = (self.cga_color & 0xDF) | ((bx & 1) << 5)
            elif ah == 0x0F:
                cols = 0x28 if self.vmode in (0, 1, 4, 5) else 0x50
                w(UC_X86_REG_AX, (cols << 8) | self.vmode)
                w(UC_X86_REG_BX, bx & 0xFF)
            elif ah == 0x02:
                self.w16(0x450, r(UC_X86_REG_DX))
            elif ah == 0x03:
                w(UC_X86_REG_DX, self.r16(0x450))
                w(UC_X86_REG_CX, 0x0607)
            elif ah in (0x09, 0x0A):
                cx = r(UC_X86_REG_CX)
                if self.is_text():
                    col, row = mu.mem_read(0x450, 2)
                    for k in range(cx):
                        p = row * 80 + col + k
                        if p >= 2000:
                            break
                        self.text_put(p % 80, p // 80, al, (bx & 0xFF) if ah == 9 else None)
                else:
                    self.gchar(al, bx & 0xFF, cx, False)
            elif ah == 0x0E:
                if self.is_text():
                    self.text_tty(al)
                else:
                    self.gchar(al, bx & 0xFF, 1, True)
            else:
                self.log.append('int10 ah=%02X al=%02X' % (ah, al))
        elif n == 0x11:
            w(UC_X86_REG_AX, 0x0021)
        elif n == 0x16:
            if ah in (0, 0x10):
                h = self.r16(0x41A)
                if h == self.r16(0x41C):
                    raise Exit('int16/0 without key')
                w(UC_X86_REG_AX, self.r16(0x400 + h))
                self.w16(0x41A, 0x1E if h + 2 >= 0x3E else h + 2)
            elif ah in (1, 0x11):
                h = self.r16(0x41A)
                if h != self.r16(0x41C):
                    w(UC_X86_REG_AX, self.r16(0x400 + h))
                    self.setzf(False)
                else:
                    self.setzf(True)
            elif ah == 2:
                w(UC_X86_REG_AX, (ax & 0xFF00) | (4 if self.kctrl else 0) | (8 if self.kalt else 0) | (2 if self.kshift else 0))
        elif n == 0x21:
            if ah == 0x09:
                ds = r(UC_X86_REG_DS)
                o = r(UC_X86_REG_DX)
                while True:
                    c = mu.mem_read(ds * 16 + o, 1)[0]
                    if c == 0x24:
                        break
                    if self.is_text():
                        self.text_tty(c)
                    else:
                        self.gchar(c, 7, 1, True)
                    o = (o + 1) & 0xFFFF
                w(UC_X86_REG_AX, (ax & 0xFF00) | 0x24)
            elif ah == 0x4C:
                raise Exit(al)
            else:
                self.log.append('int21 ah=%02X' % ah)
        elif n == 0x20:
            raise Exit(0)
        elif n == 0x19:
            raise Exit('int 19h')
        else:
            self.log.append('int %02X ax=%04X at %04X:%04X' % (n, ax, r(UC_X86_REG_CS), r(UC_X86_REG_IP)))

    def gchar(self, ch, attr, count, tty):
        mu = self.mu
        col, row = mu.mem_read(0x450, 2)
        if tty:
            if ch == 13:
                col = 0
            elif ch == 10:
                row = min(row + 1, 24)
            elif ch == 7:
                pass
            elif ch == 8:
                col = max(col - 1, 0)
            else:
                self.gchar(ch, attr, 1, False)
                col += 1
                if col >= 40:
                    col = 0
                    row = min(row + 1, 24)
            mu.mem_write(0x450, bytes([col, row]))
            return
        if self.vmode not in (4, 5):
            return
        glyph = bytes(mu.mem_read(0xFFA6E + (ch & 0x7F) * 8, 8))
        c = attr & 3
        for k in range(count):
            x = col + k
            if x >= 40:
                break
            for y in range(8):
                g = glyph[y]
                v = 0
                for b in range(8):
                    if g >> (7 - b) & 1:
                        v |= c << (14 - 2 * b)
                py = row * 8 + y
                a = 0xB8000 + (py & 1) * 0x2000 + (py >> 1) * 80 + x * 2
                if attr & 0x80:
                    old = mu.mem_read(a, 2)
                    v ^= old[0] << 8 | old[1]
                mu.mem_write(a, bytes([v >> 8, v & 0xFF]))

    # ---- 돌리기 ----
    def run(self, maxticks, trace=None, shots=None, every=1, blocks=None):
        from unicorn import UC_HOOK_CODE, UC_HOOK_BLOCK
        mu = self.mu
        L = LOADSEG * 16
        self.maxticks = maxticks
        self.trace = open(trace, 'w') if trace else None
        self.every = every
        self.shotlist = dict(shots or {})
        import scan, polls
        for a in polls.POLLAT:
            mu.hook_add(UC_HOOK_CODE, self.on_poll, None, L + a, L + a)
        for a in polls.INT16:
            mu.hook_add(UC_HOOK_CODE, self.on_int16, None, L + a, L + a)
        for a, i in scan.code.items():
            if i.mnemonic == 'pushf':
                mu.hook_add(UC_HOOK_CODE, self.on_after_pushf, None, L + a + 1, L + a + 1)
        if blocks is not None:
            def hb(mu, addr, size, ud):
                cs = mu.reg_read(UC_X86_REG_CS)
                blocks.add((cs - LOADSEG, addr - cs * 16))
            mu.hook_add(UC_HOOK_BLOCK, hb)
        res = 'stopped'
        idle = 0
        while True:
            cs = mu.reg_read(UC_X86_REG_CS)
            ip = mu.reg_read(UC_X86_REG_IP)
            n0 = self.npoll
            try:
                mu.emu_start(cs * 16 + ip, 0xFFFFF, 0, 5000000)
            except Exit as e:
                res = 'exit %s' % e
                break
            except UcError as e:
                cs = mu.reg_read(UC_X86_REG_CS)
                ip = mu.reg_read(UC_X86_REG_IP)
                res = 'ucerror %s at %04X:%04X' % (e, cs - LOADSEG, ip)
                break
            if self.stopped:
                break
            idle = idle + 1 if self.npoll == n0 else 0
            if idle >= 10:
                cs = mu.reg_read(UC_X86_REG_CS)
                ip = mu.reg_read(UC_X86_REG_IP)
                res = 'HANG (no poll in 50M insns) at %04X:%04X' % (cs - LOADSEG, ip)
                break
        if self.trace:
            self.trace.close()
        return res + ' ticks %d polls %d' % (self.ticks, self.npoll)

    def on_after_pushf(self, mu, addr, size, ud):
        a = mu.reg_read(UC_X86_REG_SS) * 16 + mu.reg_read(UC_X86_REG_SP)
        v = struct.unpack('<H', mu.mem_read(a, 2))[0]
        mu.mem_write(a, struct.pack('<H', (v & 0x0EC1) | 0x0002))

    def on_int16(self, mu, addr, size, ud):
        ah = mu.reg_read(UC_X86_REG_AX) >> 8
        if ah not in (0, 0x10):
            return
        while self.buf_empty() and not self.stopped:
            self.do_poll()

    def on_poll(self, mu, addr, size, ud):
        self.do_poll()

    def state_line(self, irq):
        import zlib
        mu = self.mu
        r = mu.reg_read
        c1 = zlib.crc32(bytes(mu.mem_read(0, 0xA0000)))
        c2 = zlib.crc32(bytes(mu.mem_read(0xB8000, 0x4000)))
        regs = [r(x) for x in (UC_X86_REG_AX, UC_X86_REG_BX, UC_X86_REG_CX, UC_X86_REG_DX, UC_X86_REG_SI,
                               UC_X86_REG_DI, UC_X86_REG_BP, UC_X86_REG_SP, UC_X86_REG_CS, UC_X86_REG_DS,
                               UC_X86_REG_ES, UC_X86_REG_SS)]
        return '%d %d %d %s %08X %08X' % (self.npoll, self.ticks, irq, ' '.join('%04X' % v for v in regs), c1, c2)

    def pixels(self):
        v = bytes(self.mu.mem_read(0xB8000, 0x4000))
        out = bytearray(320 * 200)
        for y in range(200):
            row = v[(y & 1) * 0x2000 + (y >> 1) * 80:][:80]
            for xb in range(80):
                b = row[xb]
                o = y * 320 + xb * 4
                out[o] = b >> 6
                out[o + 1] = b >> 4 & 3
                out[o + 2] = b >> 2 & 3
                out[o + 3] = b & 3
        return out

    def screen(self, fn):
        from PIL import Image
        if self.is_text():
            v = bytes(self.mu.mem_read(0xB8000, 4000))
            out = bytearray(640 * 200)
            for r in range(25):
                for c in range(80):
                    ch, at = v[(r * 80 + c) * 2], v[(r * 80 + c) * 2 + 1]
                    for y in range(8):
                        g = self.font[(ch & 0x7F) * 8 + y]
                        for b in range(8):
                            out[(r * 8 + y) * 640 + c * 8 + b] = (at & 15) if g >> (7 - b) & 1 else (at >> 4) & 7
            im = Image.frombytes('P', (640, 200), bytes(out))
            pal = []
            for c in BASE16:
                pal += list(c)
            im.putpalette(pal + [0] * (768 - len(pal)))
            im.convert('RGB').resize((640, 400), Image.NEAREST).save(fn)
            return
        im = Image.frombytes('P', (320, 200), bytes(self.pixels()))
        pal = []
        for c in cga_rgb(self.vmode, self.cga_color):
            pal += list(c)
        im.putpalette(pal + [0] * (768 - len(pal)))
        im.convert('RGB').resize((640, 400), Image.NEAREST).save(fn)


KEYNAMES = {'enter': 0x1C, 'up': 0x48, 'down': 0x50, 'left': 0x4B, 'right': 0x4D, 'space': 0x39, 'esc': 0x01,
            'tab': 0x0F, 'home': 0x47, 'end': 0x4F, 'pgup': 0x49, 'pgdn': 0x51, 'ins': 0x52, 'del': 0x53,
            'ctrl': 0x1D, 'alt': 0x38, 'lshift': 0x2A, 'rshift': 0x36, 'scroll': 0x46, 'bksp': 0x0E}
for _r, _b in (('1234567890', 2), ('qwertyuiop', 0x10), ('asdfghjkl', 0x1E), ('zxcvbnm', 0x2C)):
    for _k, _c in enumerate(_r):
        KEYNAMES[_c] = _b + _k
for _k in range(1, 10):
    KEYNAMES['f%d' % _k] = 0x3A + _k


def parse_keys(fn):
    """대본 (hosttest.c 와 같은 꼴): '틱 스캔16진' 또는 '틱 +키 [누름틱수]' (누름 뒤 뗌), '#' 주석"""
    keys = []
    for ln in open(fn, encoding='utf-8'):
        p = ln.split('#')[0].split()
        if len(p) < 2 or p[1] in ('shot', 'quit'):
            continue
        t = int(p[0])
        if p[1].startswith('+'):
            sc = KEYNAMES[p[1][1:]]
            hold = int(p[2]) if len(p) > 2 else 2
            keys.append((t, sc))
            keys.append((t + hold, sc | 0x80))
        else:
            keys.append((t, int(p[1], 16)))
    keys.sort(key=lambda e: e[0])
    return keys


if __name__ == '__main__':
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 3000
    every = int(sys.argv[2]) if len(sys.argv) > 2 else 1000
    keys = parse_keys(sys.argv[3]) if len(sys.argv) > 3 else []
    m = Machine(keys=keys)
    shots = {t: os.path.join(ROOT, '_e_%05d.png' % t) for t in range(every, n + 1, every)}
    print(m.run(n, shots=shots))
    print('\n'.join(m.log[:100]))
