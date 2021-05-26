#!/usr/bin/python3
"""
Script that, given an n*n matrix, rotate it
90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a 2d matrix in place
    """
    lenn = len(matrix) - 1
    for y in range(len(matrix) // 2):
        for x in range(y, lenn - y):
            aux = matrix[y][x]
            matrix[y][x] = matrix[lenn - x][y]
            matrix[lenn - x][y] = matrix[lenn - y][lenn - x]
            matrix[lenn - y][lenn - x] = matrix[x][lenn - y]
            matrix[x][lenn - y] = aux
