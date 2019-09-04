#!/bin/env python3
import sys

good = set("ACGTNacgtn")
cur_pos = 0
cur_chr = "NONONO!"
for l in sys.stdin:#.buffer:
    l = l.strip()
    if l[0] == '>':
        cur_chr = l[1:]
        cur_pos = 0
        continue
    if any(c not in good for c in l):
        for i,c in enumerate(l):
            if c not in good:
                print cur_chr, cur_pos+i
    cur_pos += len(l)
