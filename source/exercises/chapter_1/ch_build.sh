#!/bin/sh
set -xe
read FileName

clang -Wall -Wextra -o $FileName $FileName.c