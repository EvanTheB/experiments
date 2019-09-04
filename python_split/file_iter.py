with open("noterm") as f:
    for l in f:
        print(repr(l))

print()

with open("term") as f:
    for l in f:
        print(repr(l))

print()

with open("extra_term") as f:
    for l in f:
        print(repr(l))
