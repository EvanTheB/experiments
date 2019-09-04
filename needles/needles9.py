import sys
import collections
from bisect import bisect_left, bisect_right
from itertools import zip_longest
import functools

try:
    import line_profiler

    prof = line_profiler.LineProfiler()
except:

    def prof(func):
        prof.__dict__["print_stats"] = lambda: None
        return func


@prof
def main():
    sys.stdin.readline()
    ps = sys.stdin.readline().split()
    vs = list(map(int, sys.stdin.readline().split()))
    sys.stdin.readline()

    def thing():
        return [[None] * 26, [], [0]]

    g = thing()

    q = collections.deque()
    for i, p in enumerate(ps):
        cur = g
        for l in map(lambda x: ord(x) - ord("a"), p):
            if cur[0][l] is None:
                cur[0][l] = thing()
                q.append(cur[0][l])
            cur = cur[0][l]
        cur[1].append(i)

    while len(q):
        t = q.pop()
        for i, e in enumerate(cur[1]):
            cur[2].append(vs[e] + cur[2][-1])

    # print(g)

    @prof
    def walk(g, hay, l, h):
        tot = 0
        cur = [g]
        for c in map(lambda x: ord(x) - ord("a"), hay):
            nex = [g]
            for state in cur:
                if state[0][c] is not None:
                    nex.append(state[0][c])
                    if len(state[0][c][1]):
                        tot += (
                            state[0][c][2][bisect_right(state[0][c][1], h)]
                            - state[0][c][2][bisect_left(state[0][c][1], l)]
                        )
            cur = nex
        return tot

    mmin = float("inf")
    mmax = 0
    for l, h, hay in map(str.split, sys.stdin):
        l, h = map(int, (l, h))
        s = walk(g, hay, l, h)
        mmin = min(mmin, s)
        mmax = max(mmax, s)

    print(mmin, mmax)

    prof.print_stats()

    # 15806635 20688978289
    # 0 7353994
    # 40124729287 61265329670


main()
