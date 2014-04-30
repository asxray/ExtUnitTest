#!/bin/bash -eux
test -n $1
clang-format-3.4 -i --style=Google $(find $@ -type f \( -name "*.cpp" -or -name "*.h" -or -name "*.hpp" \))
