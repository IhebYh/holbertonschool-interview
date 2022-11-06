#!/usr/bin/python3

import sys

""" NQueens module"""


def printSolution(solution, coordinates):
    """ This function prints the N Queens coordinates in the board"""
    for i in range(len(solution)):
        row = 0
        coord = []
        for j in range(N):
            point = []
            point.append(row)
            point.append(solution[i][j])
            coord.append(point)
            row += 1
        coordinates.append(coord)

    for coord in coordinates:
        print(coord, sep=', ')


def isSafe(board, row, col):
    """ This function checks if the safety of the queen"""
    can_place_count[0] += 1
    for i in range(row):
        if board[i] == col or abs(i - row) == abs(board[i] - col):
            return False
    return True


def nQueensManager(board, row, n):
    """ This function solves the N Queens porblem"""
    nqueens_count[0] += 1
    if row == n:
        return solution.append(board[:])
    for col in range(n):
        if isSafe(board, row, col):
            board[row] = col
            nQueensManager(board, row + 1, n)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N") or exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number") or exit(1)
    if N < 4:
        print("N must be at least 4") or exit(1)

    board = [None] * N
    solution = []
    coordinates = []
    nqueens_count = [0]
    can_place_count = [0]
    nQueensManager(board, 0, N)
    printSolution(solution, coordinates)
