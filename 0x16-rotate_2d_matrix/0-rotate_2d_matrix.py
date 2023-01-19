#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix,
    rotate it 90 degrees clockwise """
    n = len(matrix)
    temp1, temp2 = 0, 0

    for j in range(0, len(matrix) // 2 + 1):
        for i in range(j, n - 1):
            temp1 = matrix[i][n - 1]
            matrix[i][n - 1] = matrix[j][i]

            temp2 = matrix[n - 1][n - 1 - i + j]
            matrix[n - 1][n - 1 - i + j] = temp1

            temp1 = matrix[n - 1 - i + j][j]
            matrix[n - 1 - i + j][j] = temp2

            matrix[j][i] = temp1
        n -= 1
