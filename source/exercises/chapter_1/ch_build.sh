#!/bin/sh bash
set -xe
read -p "Enter the FileName: " FileName

clang -Wall -Wextra -o $FileName $FileName.c