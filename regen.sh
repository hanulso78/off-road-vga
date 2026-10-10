#!/bin/sh
# 번역 다시 만들기 + 호스트 시험판 빌드:  sh regen.sh [vga]
#   tools/asm2c.py -> or_code.c, tools/mkimage.py -> orimg.c, tools/mkvga.py -> orvgatab.c
set -e
cd "$(dirname "$0")"
P=/c/python-3.12.10-embed-amd64/python.exe
export PYTHONIOENCODING=utf-8
$P tools/asm2c.py
$P tools/mkimage.py
[ "$1" = vga ] && $P tools/mkvga.py
sh build_host.sh $1 | tail -1
