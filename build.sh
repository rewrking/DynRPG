#!/bin/bash

CMD=$1
BUILD=$2
VSCODE=$3
OPTIONS=$4

cwd=${PWD##*/}

export GCC_COLORS="error=01;31:warning=01;33:note=01;36:locus=00;34"

if [[ $CMD == '' ]]; then
	CMD=buildprod
fi
if [[ $BUILD == '' ]]; then
	BUILD=Release
fi

if [[ $OSTYPE == 'msys' || $OSTYPE == 'win32' ]]; then
	export PLATFORM=windows
	if [[ $NAME == '' ]]; then
		export NAME=$cwd.dll
	fi
fi


if [[ $VSCODE != 'vscode' ]]; then
	export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
	if [[ $PLATFORM == 'windows' ]]; then
		export PATH="/c/SFML-2.5.1/bin:/c/mingw32/bin:$PATH"
	fi
	echo
	echo build.sh PATH=$PATH
	echo
fi

export MAKE_EXEC=make
if [[ $PLATFORM == 'windows' ]]; then
	if [ $(type -P "mingw32-make.exe") ]; then
		export MAKE_EXEC=mingw32-make.exe
	elif [ $(type -P "make.exe") ]; then
		export MAKE_EXEC=make.exe
	fi
fi

if [[ $BUILD != "Release" && $BUILD != 'Debug' ]]; then
	BUILD=Release
fi

dec=\=\=\=\=\=\=

display_styled() {
	tput setaf $1
	tput bold
	echo $dec $2 $dec
	tput sgr0
}

build_success() {
	display_styled 2 "Build Succeeded"
}

build_success_launch() {
	display_styled 2 "Build Succeeded: Launching bin/$BUILD/$NAME"
	echo
}

build_fail() {
	display_styled 1 "Build Failed: Review the compile errors above"
	tput sgr0
	exit 1
}

build_prod_error() {
	display_styled 1 "Error: buildprod must be run on Release build."
	tput sgr0
	exit 1
}

launch() {
	display_styled 2 "Launching bin/$BUILD/$NAME"
	echo
}

launch_prod() {
	display_styled 2 "Launching Production Build: $NAME"
	echo
}

tput setaf 4
if [[ $CMD == 'buildrun' ]]; then
	if $MAKE_EXEC BUILD=$BUILD; then
		build_success_launch
		bin/$BUILD/$NAME $OPTIONS
	else
		build_fail
	fi

elif [[ $CMD == 'build' ]]; then
	if $MAKE_EXEC BUILD=$BUILD; then
		build_success
	else
		build_fail
	fi

elif [[ $CMD == 'rebuild' ]]; then
	if $MAKE_EXEC BUILD=$BUILD rebuild; then
		build_success
	else
		build_fail
	fi

elif [[ $CMD == 'run' ]]; then
	launch
	bin/$BUILD/$NAME $OPTIONS

elif [[ $CMD == 'buildprod' ]]; then
	if [[ $BUILD == 'Release' ]]; then
		if $MAKE_EXEC BUILD=$BUILD buildprod; then
			build_success
		else
			build_fail
		fi
	else
		build_prod_error
	fi

else
	tput setaf 1
	tput bold
	echo $dec Error: Command \"$CMD\" not recognized. $dec
	tput sgr0
	exit 1
fi

tput sgr0
exit 0