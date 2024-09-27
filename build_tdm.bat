@echo off

set MINGW_PATH=C:\TDM-GCC-32

set Path=C:\Program Files\CMake\bin;%MINGW_PATH%\bin

if not exist "build" md build
cd build

@REM echo %Path%

cmake.exe -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DDYNRPG_SHARED=OFF -DDYNRPG_BUILD_DOCS=ON ..
cmake.exe --version
mingw32-make.exe -j8

cd ..