#!/usr/bin/python3
"""
A sript that reads stdin l by l and computes metrics
"""
import sys


status = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
    }
total = 0
try:
    for t, l in enumerate(sys.stdin, 1):
        token = l.split()
        if len(token) > 2:
            code = token[len(token) - 2]
            total += int(token[len(token) - 1])
            if code in status:
                status[str(code)] += 1
        if t % 10 == 0:
            print("File size: {}".format(total))
            for s in sorted(status):
                if status[s] > 0:
                    print("{}: {}".format(s, status[s]))
except Exception:
    pass
finally:
    print("File size: {}".format(total))
    for s in sorted(status):
        if status[s] > 0:
            print("{}: {}".format(s, status[s]))
