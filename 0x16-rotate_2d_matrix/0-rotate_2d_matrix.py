#!/usr/bin/python3
"""Rotates a 2D matrix 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """Method to roate matrix"""
    temp = [i[:] for i in matrix]
    temp_len = range(len(temp))
    temp.reverse()
    for i in temp_len:
        for j in temp_len:
            matrix[i][j] = temp[j][i]
