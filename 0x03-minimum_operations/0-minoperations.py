#!/usr/bin/python3
"""calculates the fewest number of
operations needed for the end result"""


def minOperations(n):
    counter = 0
    if n <= 1:
        return counter
    for i in range(2, n + 1):
        while n % i == 0:
            ++counter
            j = int(n / i)
            return minOperations(j) + i
