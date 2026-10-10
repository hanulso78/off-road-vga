# ============================================================================
#  OFF-ROAD (Montsoft 1988, IBM CGA) - djgpp 빌드
# ----------------------------------------------------------------------------
#      make -f or.mak            ORC.EXE   (원판을 옮긴 것 그대로, CGA 4색)
#      make -f or.mak vga        ORVGA.EXE (256색 리마스터)
#      make -f or.mak clean
# ============================================================================

CC      = gcc
CFLAGS  = -O2 -march=i386 -mtune=i486 -Wall -Wno-unused-label -Wno-unused-variable -Wno-unused-but-set-variable -fno-strict-aliasing
# 옮긴 코드는 함수 하나가 커서 -O1 (hhmack: -O2 가 오히려 느렸다)
CODEFLAGS = -O1 -march=i386 -mtune=i486 -w -fno-strict-aliasing

ORIG    = or_code.o orimg.o orfont.o orrt.o orfast.o sys_dos.o
VGA     = or_code.vo orimg.o orfont.o orrt.vo orfast.vo sys_dos.vo orvga.vo orvgatab.o

.PHONY: all vga clean

all: orc.exe

vga: orvga.exe

orc.exe: $(ORIG)
	$(CC) $(CFLAGS) -o orc.exe $(ORIG)
	strip orc.exe

orvga.exe: $(VGA)
	$(CC) $(CFLAGS) -o orvga.exe $(VGA)
	strip orvga.exe

or_code.o: or_code.c cpu.h
	$(CC) $(CODEFLAGS) -c $< -o $@
or_code.vo: or_code.c cpu.h orvga.h
	$(CC) $(CODEFLAGS) -DORVGA -c $< -o $@

orimg.o: orimg.c
	$(CC) -O0 -c $< -o $@
orfont.o: orfont.c
	$(CC) -O0 -c $< -o $@
orvgatab.o: orvgatab.c
	$(CC) -O0 -c $< -o $@

%.o: %.c cpu.h plat.h
	$(CC) $(CFLAGS) -c $< -o $@

%.vo: %.c cpu.h plat.h orvga.h
	$(CC) $(CFLAGS) -DORVGA -c $< -o $@

clean:
	-del *.o
	-del *.vo
	-del orc.exe
	-del orvga.exe
