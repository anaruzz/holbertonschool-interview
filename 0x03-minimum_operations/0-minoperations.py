#!/usr/bin/python3
"""
a method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    minimum operations
    """
    if n <= 1 or type(n) is not int:
        return 0
    c = 0
    i = 2
    while (i <= n):
        if n % i == 0:
            c += i
            n = n / i
        else:
            i += 1
    return c
