import sys
import collections

sys.stdin.readline()
ps = sys.stdin.readline().split()
vs = list(map(int, sys.stdin.readline().split()))
sys.stdin.readline()

def thing():
    return [[None]*26, ()]


g = thing()

for i, p in enumerate(ps):
    cur = g
    for l in map(lambda x: ord(x) - ord('a'), p):
        if cur[0][l] is None:
            cur[0][l] = thing()
        cur = cur[0][l]
    cur[1] = tuple(sorted(cur[1] + (i,)))

# print(g)

# import line_profiler
# prof = line_profiler.LineProfiler()
# @prof
def walk(g, hay, l, h):
    # @prof
    def score_cache(d, c={}):
        if d not in c:
            c[d] = sum(vs[e] for e in d if l <= e <= h)
        return c[d]

    tot = 0
    cur = [g]
    for c in map(lambda x: ord(x) - ord('a'), hay):
        nex = [g]
        for state in cur:
            if state[0][c] is not None:
                nex.append(state[0][c])
                tot += score_cache(state[0][c][1])
        cur = nex
    return tot

mmin = float('inf')
mmax = 0
for l, h, hay in map(str.split, sys.stdin):
    l, h = map(int, (l,h))
    s = walk(g, hay, l, h)
    mmin = min(mmin, s)
    mmax = max(mmax, s)

print(mmin, mmax)

# prof.print_stats()

# 15806635 20688978289
# 0 7353994
# 40124729287 61265329670
