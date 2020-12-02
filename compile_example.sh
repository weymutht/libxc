#!/bin/bash

set -e

gcc -c -I ./inst/include -o main.o main.c
gcc -g -O2 -o main main.o ./inst/lib/libxc.a -lm
