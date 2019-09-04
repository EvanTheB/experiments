import numpy as np
import random

np.core.arrayprint.set_printoptions(linewidth=200)

d = np.zeros((7, 8))

for x in range(2,7):
    for i in range(1, 8):
        d[x,i] = sum(sum(random.choices(list(range(1,7)), k=i)) // x for _ in range(10000)) / 10000

print("Expected number")
print(d)

d = np.zeros((7, 7))

for x in range(2,7):
    for i in range(1, 7):
        d[x,i] = sum(x / i * (sum(random.choices(list(range(1,7)), k=i)) // x) for _ in range(10000)) / 10000

print()
print("Expected value")
print(d)
