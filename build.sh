#!/bin/bash -x
autoconf
autoreconf -is && \
./configure && \
make
