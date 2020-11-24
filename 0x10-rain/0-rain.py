#!/usr/bin/python3

"""Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains."""

def rain(walls):
    """Determines how many units of water are contained within the array's walls"""
    water_total = 0
    size = len(walls)

    # Returns 0 if list is empty
    if size <= 0:
        return water_total

    # Traverses the rain list
    for i in (range(1, size - 1)):

        # Finds the maximum element on the left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Finds the maximum element on the right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        water_total += (min(left, right) - walls[i])

    return water_total
