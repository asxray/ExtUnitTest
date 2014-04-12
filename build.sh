#!/bin/bash -x
autoconf
autoreconf -is && \
./configure CXXFLAGS='-O0 -ggdb' && \
make
