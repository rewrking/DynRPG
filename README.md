# DynRPG

## Prerequisites for building:

* [GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
* [Git Bash (for Windows) ](https://git-scm.com/downloads)

* [Visual Studio Code](https://code.visualstudio.com/download)
* Extensions (install from Extensions panel):
  * [Official C/C++ Extension (0.21.0+)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  * [x86 and x86_64 Assembly (Optional Syntax Highlighting)](https://marketplace.visualstudio.com/items?itemName=13xforever.language-x86-64-assembly)

---

## Installation

1. Download & Extract MinGW to **C:/mingw32/** where the bin/lib/include folders are contained within
2. Download & Install Visual Studio Code if you don't already have it.
3. Install the official **C/C++** Extension, reload the window & wait for the dependencies to install.
4. If on Windows, install **Git Bash**, and ensure the **"terminal.integrated.shell.windows"** property in the project's **settings.json** is set to **bash.exe**'s correct location (default: C:/Program Files/Git/bin/bash.exe). We'll be using this for the terminal in our workspace so that the Makefile can run in both Windows, Mac & Linux
5. In **settings.json** Ensure **Path** in the **terminal.integrated.env.windows** object is set to the correct location of the compiler's executable (example: C:\\mingw32\\bin). Keep in mind Paths should be separated by a semi-colon with no spaces between.

**Note:** You can manage the "Path" environment variable from Windows if you'd like, but I've found sandboxing it in VS Code is better for tracking things like .dll dependencies.

---

## Configuration

At this point, everything you need is installed

1. Open the root DynRPG folder in VS Code. 
2. At this point, you can run a build task (**Ctrl+Shift+B** > **Build & Run**), but it'll be nicer to add keybindings for these tasks so you can build with 1 keypress.
3. Open the .vscode folder and click on the **\_keybindings.json** file. This is not an officially recognized file, but just contains the keybindings you can copy into the actual keybindings.json file.
4. Go into **File** > **Preferences** > **Keyboard Shortcuts** & click on the keybindings.json link at the top.
5. Copy the keybindings into this file. Feel free to change them if you don't like them later.
6. Hit the **F9** key to run the **Build & Run: Release** task. It should run the Makefile, and build the DynRPG library. The build script isn't perfect yet, so it'll succeed even though it says it can't launch the built target.

---

