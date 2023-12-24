#!/bin/sh

set -xe
read SourcePath
read Chapter
read FileName

clang -Wall -Wextra -o ../source/$SourcePath/$Chapter/$FileName ../source/$SourcePath/$Chapter/$FileName.c