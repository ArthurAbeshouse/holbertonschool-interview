#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """Returns a 2D list of ints representing Pascal's Triangle"""
    List = [[1]]
    for i in range(1, n):
        List.append([0] * (len(List[i - 1]) + 1))
        List[i][0] = 1
        List[i][-1] = 1
        for j in range(1, len(List[i]) - 1):
            List[i][j] = List[i - 1][j - 1] + List[i - 1][j]
    return List
