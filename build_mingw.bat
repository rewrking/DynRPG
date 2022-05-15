@echo off

set MINGW_PATH=C:\mingw32

set Path=C:\Program Files\CMake\bin;%MINGW_PATH%\bin

if not exist "build" md build
cd build

@REM echo %Path%

cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
mingw32-make.exe -j8

cd ..