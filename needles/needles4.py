import sys
import collections

sys.stdin.buffer.readline()
ps = sys.stdin.buffer.readline().split()
vs = list(map(int, sys.stdin.buffer.readline().split()))
sys.stdin.buffer.readline()

g = ([None]*26, [])

for i, p in enumerate(ps):
    cur = g
    for l in p:
        l -= b'a'[0]
        if cur[0][l] is None:
            cur[0][l] = ([None]*26, [])
        cur = cur[0][l]
    cur[1].append(i)

# print(g)

def walk(g, hay, l, h):
    cur = [g]
    for c in hay:
        c -= b'a'[0]
        nex = [g]
        for state in cur:
            if state[0][c] is not None:
                nex.append(state[0][c])
        for state in nex:
            # print(state[1])
            for e in state[1]:
                if l <= e <= h:
                    yield vs[e]
        cur = nex

scores = []
for l, h, hay in map(bytes.split, sys.stdin.buffer):
    l, h = map(int, (l,h))
    scores.append(sum(walk(g, hay, l, h)))

print(min(scores), max(scores))

# 15806635 20688978289
# 0 7353994
# 40124729287 61265329670
