#!/bin/sh

rm -f libft.a

find . -name "*.c" -type f -maxdepth 1 -exec cc -Wall -Wextra -Werror -c {} \;

ar -rcs libft.a *.o

find . -name "*.o" -type f -maxdepth 1 -delete
