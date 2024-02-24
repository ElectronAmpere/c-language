#!/bin/sh bash
# set -xe (commented for normal operations, for verbose uncomment)
read -p "Enter the FileName: " FileName

clang -Wall -Wextra -o $FileName $FileName.c