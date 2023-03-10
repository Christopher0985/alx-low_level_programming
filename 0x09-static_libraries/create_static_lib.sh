#!/bin/bash
gcc -wall -pendantic -werror -wextra -c *.c
ar -rc liball.a *.c
ranlib liball.a
