@echo off

set MINGW_PATH=C:\mingw32

set Path=C:\Program Files\CMake\bin;%MINGW_PATH%\bin

if not exist "build" md build
cd build

@REM echo %Path%

@REM cmake.exe -G "MinGW Makefiles" -DDYNRPG_SHARED=OFF -DCMAKE_BUILD_TYPE=Release -DDYNRPG_BUILD_DOCS=OFF ..
cmake.exe -G "MinGW Makefiles" -DDYNRPG_SHARED=OFF -DCMAKE_BUILD_TYPE=Release ..
cmake.exe --version
mingw32-make.exe -j8

cd ..