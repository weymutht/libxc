#!/bin/bash

set -e

gcc -c -std=c99 -I./inst/include -o main.o main.c
#gcc -g -O2 -o main main.o ./inst/lib/libxc.a -lm
gcc -g -o main main.o ./inst/lib/libxc.a -lm
