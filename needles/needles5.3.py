import sys
import collections
from bisect import bisect_left, bisect_right
from itertools import zip_longest


try:
    import line_profiler
    prof = line_profiler.LineProfiler()
except:
    def prof(func):
        prof.__dict__['print_stats'] = lambda : None
        return func


class RangeTree(object):
    """docstring for RangeTree"""

    @prof
    def __init__(self, items, items2=None):
        if len(items) > 1:
            self.leaf = False
            self.l = RangeTree(items[: len(items) // 2])
            self.r = RangeTree(items[len(items) // 2 :])
            self.maxl = items[len(items) // 2 - 1][0]
            self.leastr = items[len(items) // 2][0]
            self.val = self.l.val + self.r.val
            # self.val2 = self.l.val2 + self.r.val2
        else:
            self.leaf = True
            self.maxl = items[0][0]
            self.leastr = items[0][0]
            self.val = items[0][1]

    @prof
    def q(self, low, high):
        splitv = self
        while not splitv.leaf:
            if splitv.leastr > high:
                splitv = splitv.l
            elif splitv.maxl < low:
                splitv = splitv.r
            else:
                break

        if splitv.leaf and not (low <= splitv.maxl <= high):
            return 0

        total = splitv.val
        # print(splitv)
        # print("t", total)

        # find low, subtract branches to left
        left = splitv
        while not left.leaf:
            if left.maxl >= low:
                left = left.l
            else:
                # print("-", left.l.val)
                total -= left.l.val
                left = left.r
        assert left.leaf
        assert left.maxl >= low
        # print(left)

        # find high, subtract branches to right
        right = splitv
        while not right.leaf:
            if right.leastr <= high:
                right = right.r
            else:
                # print("-", right.r.val)
                total -= right.r.val
                right = right.l
        assert right.leaf
        assert right.leastr <= high
        # print(right)

        return total


    def print(self, prefix, istail):
        if self.leaf:
            return (
                prefix
                + ("└── " if istail else "├── ")
                + str(self.maxl)
                + " ("
                + str(self.val)
                + ")\n"
            )
        return (
            prefix
            + ("└── " if istail else "├── ")
            + f"{self.maxl}({self.val})\n"
            + self.l.print(prefix + ("    " if istail else "│   "), False)
            + self.r.print(prefix + ("    " if istail else "│   "), True)
        )

    def __str__(self):
        return self.print("", False)

    def __repr__(self):
        if self.leaf:
            return "RangeTree([[{},{}]])".format(self.maxl, self.val)
        return "RangeTree({},{})".format(repr(self.l), repr(self.r))

@prof
def main():
    sys.stdin.readline()
    ps = sys.stdin.readline().split()
    vs = list(map(int, sys.stdin.readline().split()))
    sys.stdin.readline()


    def thing():
        return [[None] * 26, []]


    g = thing()

    for i, p in enumerate(ps):
        cur = g
        for l in map(lambda x: ord(x) - ord('a'), p):
            if cur[0][l] is None:
                cur[0][l] = thing()
            cur = cur[0][l]
        cur[1].append(i)

    q = collections.deque()
    q.append(g)
    while len(q):
        t = q.pop()
        for x in t[0]:
            if x is not None:
                q.append(x)
        # q.extend(x for x in t[0] if x is not None)
        t[1] = RangeTree(sorted([[e,vs[e]] for e in t[1]])) if len(t[1]) else None

    # print(g)



    @prof
    def walk(g, hay, l, h):
        tot = 0
        cur = [g]
        for c in map(lambda x: ord(x) - ord('a'), hay):
            nex = [g]
            for state in cur:
                if state[0][c] is not None:
                    nex.append(state[0][c])
                    if state[0][c][1]:
                        tot += state[0][c][1].q(l,h)
            cur = nex
        return tot


    mmin = float('inf')
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
