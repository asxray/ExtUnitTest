#!/bin/bash -ux
SRCDIR=$(pwd)
BDIR="/tmp/eut"
autoconf
set -e
autoreconf -is
mkdir -p $BDIR/built
mkdir -p $BDIR/inst
cd $BDIR/built
$SRCDIR/configure CXXFLAGS='-O0 -ggdb' --enable-shared --srcdir=$SRCDIR --prefix=$SRCDIR/../usr --includedir=$SRCDIR/../usr/include/eut
make -j check
