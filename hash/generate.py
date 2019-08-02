import sys
import random
for i in range(int(sys.argv[1])):
    print(f"{random.randint(0, 2**64 - 1):016x}")
