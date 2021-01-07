#!/usr/bin/python3


def minOperations(n):
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
