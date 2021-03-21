#!/usr/bin/python3
"""Calculates the perimeter of an island"""


def island_perimeter(grid):
    """Finds the perimeter of the island"""
    perimeter = 0
    for j in range(len(grid)):
        for i in range(len(grid[j])):
            if grid[j][i] == 1:
                perimeter += 4
                if i is not 0 and grid[j][i - 1] is 1:
                    perimeter -= 1
                if j is not 0 and grid[j - 1][i] is 1:
                    perimeter -= 1
                if j + 1 < len(grid) and grid[j + 1][i] is 1:
                    perimeter -= 1
                if i + 1 < len(grid[j]) and grid[j][i + 1] is 1:
                    perimeter -= 1
    return perimeter
