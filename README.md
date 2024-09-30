# DynRPG

This is an expanded version of [DynRPG](https://github.com/CherryDT/DynRPG), created by David “[Cherry](https://github.com/CherryDT)” Trapp, that was forked sometime back in 2014-2015 after some additional reverse engineering was done by "bugmenot", in the RPG Maker 2003 community. The additional headers and documentation were added and currently maintained by [rewrking](https://github.com/rewrking) (aka PepsiOtaku in the RMN days). This repository exists as a means to keep the project alive for those interested.

## About this repository

Originally, the source code to the library archive (`libDynRPG.a`) was not released, so the additional headers were kind of hacky, and any new functions had to be declared `inline`. Cherry has since released the source code, and it's been retroactively added here (see the `src` folder). Some effort has been put into moving some of those class methods and functions to the library archive, where it belongs. Some additional configuration headers have been added as well.

Support to build the library with CMake has also been added, so the project can be easily rebuilt when new changes are introduced. The library can also be built as a shared library instead of just a static library, although it's not recommended.

The generated documentation represents the version of the documentation currently deployed [here](https://www.rewking.com/dynrpg).

Additionally, there's an `experimental` branch that was used as a sandbox to modernize some of the DynRPG api to C++17. It was technically used to build all of the plugins in the 2021 release of [Everlasting Journey](https://gamejolt.com/games/everlasting-journey/44037), although it has since gone out of sync with the additions added to the `main` branch. Any new changes right now are the result of various Discord discussions.

To build DynRPG, an x86 (i686) version of MinGW on Windows is required. No other architecture can be used, since the RPG Maker 2003 runtime is itself an x86 application.

## Build Instructions

1. Install [CMake](https://cmake.org/download/) (Windows win64-x64 Installer, v3.10 or higher)
2. Install [Doxygen](https://www.doxygen.nl/download.html) (Windows x64 Installer, latest)
3. Get a version of GCC: 
	- [4.8.1](https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%20Installer/Previous/1.1309.0/tdm64-gcc-4.8.1-3.exe/download) - historical default compiler for DynRPG, supports up to C++11
	- [7.3.0](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download) - supports up to C++17
	- [14.2.0+ via MSYS2](https://www.msys2.org/) - Supports up to C++23 (install [mingw-w64-i686-gcc](https://packages.msys2.org/packages/mingw-w64-i686-gcc) package)
4. Check Compiler paths: 
	- `4.8.1`: Should install to `C:\TDM-GCC-32`
	- `7.3.0`: Extract to `C:\mingw32` (should see bin/lib/etc)
	- `14.2.0+`: Should have `C:\msys64\mingw32` once installed & the gcc package has been added
5. Open `build_mingw.bat` and change MINGW_PATH (on line 3) to the path of your compiler in step 4
6. Run `build_mingw.bat`. It should complete with `lib/libDynRPG.a`
7. Create plugins as usual. Link against `lib/libDynRPG.a` in each plugin, and make sure the same compiler is used each time.

## CMake Variables

If you would like to build the library differently, the following CMake variables can be set. In `build_mingw.bat`, add to the CMake configure command on line 12. Make sure each one has the `-D` prefix. Add them before the `..` at the end.

example:
```sh
cmake.exe -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=11 -DCMAKE_BUILD_TYPE=Release -DDYNRPG_SHARED=OFF -DDYNRPG_BUILD_DOCS=ON ..
```

- `CMAKE_CXX_STANDARD`: This is the C++ version you want to compile the library with. It defaults to `98` for compatibility (aka [1998 C++ standard with 2003 bugfixes](https://gcc.gnu.org/projects/cxx-status.html), at the bottom).  `11` or higher is recommended, but you must also set the `-std=c++(year)` flag when compiling your plugins.
- `DYNRPG_SHARED`: Set to `ON` to build as a shared library, `OFF` to build as a static library (default)
- `DYNRPG_BUILD_DOCS`: Set to `ON` to build the documentation (default, requires Doxygen), `OFF` to not build it
- `DYNRPG_LIB_DIR`: Set to `.` to use the build folder instead of `${CMAKE_SOURCE_DIR}\lib`

## Build inside of Visual Studio Code

1. Follow steps 1-4 above
2. Open this folder in VS Code
3. Run the build task with `Ctrl+Shift+B` (this just calls the batch file anyway)

## Plugin development

At this point, you can follow the usual [Getting Started](https://www.rewking.com/dynrpg/getting_started.html) guide in the documentation. For the editor, you can technically use whatever you'd like, as long as the plugin is built using the same compiler the library was built with. [Code::Blocks 13.12](https://sourceforge.net/projects/codeblocks/files/Binaries/13.12/Windows/codeblocks-13.12mingw-setup-TDM-GCC-481.exe/download) is the historical version used for DynRPG plugins.

