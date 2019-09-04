import numpy as np
import random

import itertools as it

dice = range(1, 7)

np.core.arrayprint.set_printoptions(linewidth=200)

d = np.zeros((7, 8))

for x in range(2, 7):
    for i in range(1, 8):
        d[x, i] = sum(sum(roll) // x for roll in it.product(dice, repeat=i)) / (len(dice) ** i)

print("Expected number")
print(d)


for x in range(2, 7):
    for i in range(1, 8):
        d[x, i] *= x/i

print()
print("Expected value / worker")
print(d)
