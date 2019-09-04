#!/bin/env python3
"""
This program worked the first time.
Therefore it is probably hopelessly broken
"""
import humanfriendly
import sys

t = humanfriendly.parse_timespan(sys.argv[1])

import datetime

start = datetime.datetime.now()
end = start + datetime.timedelta(seconds=t)


def busy(i):
    # print(i)
    acc = 1.0
    for x in range(int(i)):
        acc += 1.0

i_per_s = 1000.0
while True:
    start_loop = datetime.datetime.now()
    if start_loop > end:
        exit(0)

    target = (end - start_loop).total_seconds() / 10

    busy(target * i_per_s)

    end_loop = datetime.datetime.now()

    busy_t = (end_loop - start_loop).total_seconds()
    i_per_s = (target * i_per_s) / busy_t
