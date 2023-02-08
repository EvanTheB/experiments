from itertools import *

import pprint
pp = pprint.PrettyPrinter(indent=4)
pp = pp.pprint

def emit():
    primes = [2,3,5,7,11]
    # surely a smarter way here
    for counts in product(*[list(range(4)) for _ in range(len(primes))]):
        ac = 1
        for p, c in zip(primes, counts):
            ac *= p ** c if c else 1
        yield ac, primes, counts

s = sorted(emit())
pp(s)
