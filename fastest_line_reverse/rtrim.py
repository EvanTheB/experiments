import sys
import collections
collections.deque(map(lambda l: print(l[:(-1 * (int(sys.argv[1]) + 1))]), sys.stdin), maxlen=0)
