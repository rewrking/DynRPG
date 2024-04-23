# DynRPG

(Now with source code, thanks to Cherry)

## Instructions

1. Install [CMake](https://cmake.org/download/) (Windows win64-x64 Installer, v3.10 or higher)
2. Install [Doxygen](https://www.doxygen.nl/download.html) (Windows x64 Installer, latest)
3. Get a version of GCC: 
	- [7.3.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download) (safe/easiest to install)
	- [10.2.0+ via MSYS2](https://www.msys2.org/) (install `mingw-w64-i686-toolchain` package)
4. Check Compiler paths:
	- `7.3.0`: Extract to C:\mingw32 (should see bin/lib/etc) 
	- `10.2.0+`: Should have C:\msys64\mingw32 once installed & the package has been added
5. Open `build_mingw.bat` and change MINGW_PATH if necessary
6. Run `build_mingw.bat`. It should complete with `lib/libDynRPG.a`
7. Create plugins as usual. Link against `lib/libDynRPG.a` in each plugin, and make sure the same compiler is used each time.

## CMake Variables

- `DYNRPG_SHARED`: Set to `ON` to build as a shared library, `OFF` to build as a static library
- `DYNRPG_BUILD_DOCS`: Set to `ON` to build the documentation (requires Doxygen), `OFF` to not build it

## VS Code

1. Follow steps 1-4 above
2. Open the folder in VS Code
3. Run the build task (this just calls the batch file anyway)