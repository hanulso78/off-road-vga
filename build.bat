@echo off
rem Build ORC.EXE / ORVGA.EXE with djgpp (arguments go to make)
call "%~dp0..\..\djgpp\setenv.bat"
cd /d "%~dp0"
make -f or.mak %*
