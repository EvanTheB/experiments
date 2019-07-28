#!/bin/bash
set -euo pipefail

# for i in $(seq 0 7); do 
# 	dd if=/dev/urandom of=./"$i" bs=1M count=2048
# done

cc test.c -o test -Wall -Werror -lpthread -ggdb3

# echo 1 | sudo tee /proc/sys/vm/drop_caches

# https://unix.stackexchange.com/questions/36907/

# Advise to drop cache for whole file
# dd if=./1 iflag=nocache count=0

# Ensure drop cache for the whole file
# dd of=./1 oflag=nocache conv=notrunc,fdatasync count=0

# python3 fadvise.py 1

./test "${1:-4}"