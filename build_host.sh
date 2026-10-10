#!/bin/sh
# 호스트(윈도우, MSYS2 mingw gcc) 시험판: hosttest.exe (원판 그대로), hostvga.exe (256색)
#   sh build_host.sh [vga]
set -e
cd "$(dirname "$0")"
export PATH=/c/MSYS2/mingw64/bin:$PATH
CC="gcc -O1 -w"
mkdir -p obj_host
for f in or_code orimg orfont orrt orvgatab; do
    if [ ! -f obj_host/$f.o ] || [ $f.c -nt obj_host/$f.o ] || [ cpu.h -nt obj_host/$f.o ] || [ plat.h -nt obj_host/$f.o ]; then
        echo cc $f.c
        $CC -c $f.c -o obj_host/$f.o
    fi
done
$CC -o hosttest.exe tools/hosttest.c obj_host/or_code.o obj_host/orimg.o obj_host/orfont.o obj_host/orrt.o
echo built hosttest.exe
[ "$1" = vga ] || exit 0
CV="gcc -O1 -w -DORVGA"
for f in or_code orrt orvga; do
    if [ ! -f obj_host/$f.vo ] || [ $f.c -nt obj_host/$f.vo ] || [ cpu.h -nt obj_host/$f.vo ] || [ orvga.h -nt obj_host/$f.vo ]; then
        echo cc -DORVGA $f.c
        $CV -c $f.c -o obj_host/$f.vo
    fi
done
$CV -o hostvga.exe tools/hosttest.c obj_host/or_code.vo obj_host/orimg.o obj_host/orfont.o obj_host/orrt.vo obj_host/orvga.vo obj_host/orvgatab.o
echo built hostvga.exe
