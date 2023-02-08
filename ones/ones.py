#!/usr/bin/env python3

import sys


def longest_ones_1(binary):
    maxNumOnes = -1
    count = 0
    maxIndex = -1
    currentStartInd = -1
    for i, bit in enumerate(binary):
        if bit == 1:
            if currentStartInd == -1:
                currentStartInd = i
            count += 1
            if maxNumOnes < count:
                maxNumOnes = count
                maxIndex = currentStartInd
        elif bit == 0:
            count = 0
            currentStartInd = -1
    return maxIndex


def longest_ones_2(inp):
    count = 0
    bestLength = -1
    bestIndex = None
    startIndex = None
    for index, i in enumerate(inp):
        if i:
            count += 1
            if startIndex is None:
                startIndex = index
            if count > bestLength:
                bestLength = count
                bestIndex = startIndex
        else:
            count = 0
            startIndex = None
    return bestIndex


def longest_ones_skip(inp):
    end_index = 0
    bestLength = 0
    bestIndex = None
    while end_index < len(inp):
        count = 0
        for index in range(end_index, -1, -1):
            i = inp[index]
            if i:
                count += 1
                if count > bestLength:
                    bestLength = count
                    bestIndex = index
            else:
                break
        end_index = max(index + bestLength, end_index + 1)
    return bestIndex


def longest_ones_bit(inp):
    packed = []
    for chunk in range(0, len(inp), 64):
        nexti = 0
        for bit_pos, index in enumerate(range(chunk * 64, min((chunk + 1) * 64, len(inp)))):
            nexti += inp[index] << bit_pos
        packed.append(nexti)

    for i in packed:

def main():
    funcs = [longest_ones_1, longest_ones_2, longest_ones_skip, longest_ones_bit]

    def t(b):
        return [f(b) for f in funcs]

    print(*t([]))
    print(*t([0]))
    print(*t([1]))
    print(*t([1, 1, 0, 0, 1, 1, 1, 0]))
    print(*t([1, 1, 1, 0, 1, 1, 1, 0]))
    print(*t([0, 1, 1, 1, 0, 1, 1, 1, 1]))
    print(*t([0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0]))

    # import random
    # for i in range(1000):
    #     case = random.choices([0, 1], k=1000)
    #     test = t(case)
    #     if any(c != test[0] for c in test):
    #         print(test, case)


if __name__ == "__main__":
    sys.exit(main())
