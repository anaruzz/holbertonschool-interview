#!/usr/bin/python3
"""
Function  that returns the p of the island described in grid
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island
    """
    p = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if j == 0:
                    p += 1
                elif grid[i][j-1] == 0 and j > 0:
                    p += 1

                if i == 0:
                    p += 1
                elif grid[i-1][j] == 0 and i > 0:
                    p += 1

                if (i+1) < len(grid) and grid[i+1][j] == 0:
                    p += 1
                if i == len(grid) - 1:
                    p += 1

                if (j+1) < len(grid[0]) and grid[i][j+1] == 0:
                    p += 1
                if j == (len(grid[0]) - 1):
                    p += 1
    return p
