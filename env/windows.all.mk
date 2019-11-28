
MAX_PARALLEL_JOBS := 8
CLEAN_OUTPUT := true
DUMP_ASSEMBLY := false
BUILD_STATIC := true

CC := g++.exe

_CFLAGS_STD := -std=c++17
_CFLAGS_WARNINGS := -Wall -Wno-unused-function -Wno-unused-variable
_CFLAGS_OTHER := -fdiagnostics-color=always
CFLAGS := -O2 $(_CFLAGS_STD) $(_CFLAGS_WARNINGS) $(_CFLAGS_OTHER)

LIB_DIRS :=
LINK_LIBRARIES :=
INCLUDE_DIRS := include

PRODUCTION_FOLDER := build

PRODUCTION_EXCLUDE := \
	*.psd \
	*.rar \
	*.7z \
	Thumbs.db \
	.DS_Store

PRODUCTION_DEPENDENCIES := \
	bin/Release/libDynRPG.a \
	bin/Release/libDynRPG.def

