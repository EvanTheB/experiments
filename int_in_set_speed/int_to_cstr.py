import sys
for l in sys.stdin:
    print('"' + "".join('\\x' + l[i:i+2] for i in range(0, 16, 2)) + '"')
