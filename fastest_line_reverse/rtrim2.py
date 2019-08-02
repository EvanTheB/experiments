import sys
c = slice(0, -1 * (int(sys.argv[1]) + 1))
for l in sys.stdin:
    print(l[c])
