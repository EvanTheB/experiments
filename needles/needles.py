import sys
import collections

# import line_profiler
# prof = line_profiler.LineProfiler()
# @prof
def go(g, vs):
    # @prof
    def walk(g, hay):
        cur = [g]
        for c in hay:
            nex = [g]
            for state in cur:
                if c in state.t:
                    nex.append(state.t[c])
            for state in nex:
                for e in state.e:
                    yield e
            cur = nex

    scores = []
    for l, h, hay in map(str.split, sys.stdin):
        l, h = map(int, (l,h))
        scores.append(sum(vs[e] for e in walk(g, hay) if l <= e <= h))

    print(min(scores), max(scores))

def main():

    sys.stdin.readline()
    ps = sys.stdin.readline().split()
    vs = list(map(int, sys.stdin.readline().split()))
    sys.stdin.readline()

    t = collections.namedtuple('thingo', 't e')
    def thing():
        return t(collections.defaultdict(thing), [])

    g = thing()

    for i, p in enumerate(ps):
        cur = g
        for l in p:
            cur = cur.t[l]
        cur.e.append(i)

    go(g, vs)
    # prof.print_stats()

if __name__ == '__main__':
    main()
