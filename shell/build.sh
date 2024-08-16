#!/bin/sh bash
# set -xe (commented for normal operations, for verbose uncomment)
echo "Compiling FileName: $1"
filename=$1
echo $filename
clang -Wall -Wextra -o ${filename%.*} ${filename%.*}.c
