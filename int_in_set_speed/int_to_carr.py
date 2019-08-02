import sys
print("uint64_t int_arr[] = {")
comma = " "
for l in sys.stdin:
    print(f'\t{comma} 0x{l.strip()}ull')
    comma = ','
print(f'\t{comma} 0x0ull')
print('};')
print('#line 0 "judy.head"')

