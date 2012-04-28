#!/bin/bash

cd `dirname $0`
GRIDDIR=`pwd`
PGRIDDIR=${GRIDDIR}/..
BUILDDIR=custom-build

CC=/usr/bin/gcc
CXX=/usr/bin/g++

export CC CXX

if which qmake; then
	QMAKE=qmake
else
	QMAKE=/usr/local/qt4/bin/qmake
fi

cd $PGRIDDIR

pwd # diagnostic

if [[ -e $BUILDDIR ]]; then
	rm -rf $BUILDDIR
fi

mkdir $BUILDDIR

ls $BUILDDIR # diagnostic

cd $BUILDDIR
$QMAKE $GRIDDIR/gridrover.pro
cp $GRIDDIR/Rover-Control-Program .
chmod +x Rover-Control-Program
cp -Rf $GRIDDIR/Model .
cd Model
make -f nbproject/Makefile-Debug-Linux.mk dist/Debug/GNU-Linux-x86/libmodel.a
cd ..

if make; then
	echo
	echo GridRover now exists as `pwd`/gridrover
else
	echo
	echo There was a problem building. Contact developers.
fi
