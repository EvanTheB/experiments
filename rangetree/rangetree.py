class RangeTree(object):
    """docstring for RangeTree"""

    def __init__(self, items, items2=None):
        if len(items) > 1:
            self.leaf = False
            self.l = RangeTree(items[: len(items) // 2])
            self.r = RangeTree(items[len(items) // 2 :])
            self.maxl = items[len(items) // 2 - 1][0]
            self.leastr = items[len(items) // 2][0]
            self.val = self.l.val + self.r.val
        else:
            self.leaf = True
            self.maxl = items[0][0]
            self.leastr = items[0][0]
            self.val = items[0][1]

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
        print(splitv)
        print("t", total)

        # find low, subtract branches to left
        left = splitv
        while not left.leaf:
            if left.maxl >= low:
                left = left.l
            else:
                print("-", left.l.val)
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
                print("-", right.r.val)
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

d = [
        [0, 10],
        [1, 11],
        [2, 12],
        [5, 13],
        [9, 14],
        [15, 15],
        [16, 16],
        [17, 17],
        [20, 19],
        [21, 19],
    ]
r = RangeTree(
    d
)
# print(r)
print(r.q(0,2))

for l in range(0,22):
    for h in range(l+1,22):
        real = sum(e[1] for e in d if l <= e[0] <= h)
        print(real, l, h)
        assert r.q(l,h) == real, f"{l},{h}"

