#!/usr/bin/python3
"""
Rotate 2D Matrix
"""

def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix,
    rotate it 90 degrees clockwise """
    for i in range (0,4):
    for j in range(0,4):
        X[i][j] = Y[j][i]
    list.reverse(X[i])
