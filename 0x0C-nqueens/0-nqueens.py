#!/usr/bin/python3
"""
Script that solves the nqueens problem
"""


import sys

if len(sys.argv) > 2 or len(sys.argv) < 2:
    print("Usage: nqueens N")
    exit(1)

if not sys.argv[1].isdigit():
    print("N must be a number")
    exit(1)

if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)

n = int(sys.argv[1])
board = [[0 for x in range(n)] for y in range(n)]
k = 1


def printSolution(board, n):
    """
    Prints solution according to requierements
    """
    global k
    k += 1
    m = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                m.append([i, j])
    print(m)


def isSafe(board, row, col, n):
    """
    Returns True if queen can be placed in board[row][col]
    otherwise false
    """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, n, 1),
                    range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solveNQUtil(board, col, n):
    """
    Returns True if solution exist, false otherwise
    """
    if col == n:
        printSolution(board, n)
        return True
    res = False
    for i in range(n):
        if isSafe(board, i, col, n):
            board[i][col] = 1
            res = solveNQUtil(board, col + 1, n) or res
            board[i][col] = 0
    return res


def solveNQ(n):
    """
    nqueen solve
    """
    board = [[0 for x in range(n)] for y in range(n)]
    if solveNQUtil(board, 0, n) is False:
        print("Solution does not exist")
        return
    return


solveNQ(n)
