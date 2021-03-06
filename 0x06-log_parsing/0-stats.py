#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics
"""
import sys

status = {"200": 0,
          "300": 0,
          "400": 0,
          "401": 0,
          "403": 0,
          "404": 0,
          "405": 0,
          "500": 0}
i = 0
total = 0
try:
    for line in sys.stdin:
        i += 1
        total += int(line.split()[8])
        code = line.split()[7]
        if code in status:
            status[code] += 1
        if i % 10 == 0:
            print("File size: {}".format(total))
            for code, stat in sorted(status.items()):
                if stat > 0:
                    print("{}: {}".format(code, stat))
                i = 0
except Exception as E:
    pass

finally:
    print("File size: {}".format(total))
    for code, stat in sorted(status.items()) :
        if stat > 0:
            print("{}: {}".format(code, stat))
    i = 0
