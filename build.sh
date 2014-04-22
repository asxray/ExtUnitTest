#!/bin/bash -x
PDIR=$(pwd)
autoconf
set -e
autoreconf -is
mkdir -p /tmp/ext/built
mkdir -p /tmp/ext/inst
cd /tmp/ext/built
$PDIR/configure CXXFLAGS='-O0 -ggdb' --enable-shared --srcdir=$PDIR  --prefix=/tmp/ext/inst
make -j check install
