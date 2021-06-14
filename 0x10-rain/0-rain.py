#!/usr/bin/python3
"""
A function that calculates how much water will be
retained after it rains, given a list of non-negative
integers representing walls of width 1.
"""


def rain(walls):
    """
    return an int indicating the total amount of retained
    raiwater
    """
    if type(walls) is not list or walls is None:
        return 0
    if len(walls) <= 1:
        return 0

    total = 0
    for i in range(1, len(walls) - 1):
        le = max(walls[:i])
        ri = max(walls[i + 1:])
        mini = min(le, ri)
        if walls[i] < mini:
            total += mini - walls[i]
    return total
    # total = 0
    # n = len(walls)
    # for i in range(1, n-1):
    #     # left max
    #     left = walls[i]
    #     for j in range(i):
    #         left = max(left, walls[j])
    #     # right max
    #     right = walls[i]
    #     for j in range(i+1, n):
    #         right = max(right, walls[j])
    #     total += min(left, right) - walls[i]
    # return total
