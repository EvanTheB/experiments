import sys
import collections

sys.stdin.readline()
ps = sys.stdin.readline().split()
vs = list(map(int, sys.stdin.readline().split()))
sys.stdin.readline()

def thing():
    return ([None]*26, [])


g = thing()

for i, p in enumerate(ps):
    cur = g
    for l in map(lambda x: ord(x) - ord('a'), p):
        if cur[0][l] is None:
            cur[0][l] = thing()
        cur = cur[0][l]
    cur[1].append(i)

# print(g)

def walk(g, hay):
    cur = [g]
    for c in map(lambda x: ord(x) - ord('a'), hay):
        nex = [g]
        for state in cur:
            if state[0][c] is not None:
                nex.append(state[0][c])
        for state in nex:
            for e in state[1]:
                yield vs[e]
        cur = nex

scores = []
for l, h, hay in map(str.split, sys.stdin):
    l, h = map(int, (l,h))
    scores.append(sum(vs[e] for e in walk(g, hay) if l <= e <= h))

print(min(scores), max(scores))

# 15806635 20688978289
# 0 7353994
