#!/usr/bin/python3
"""
Function that determines the fewest number of coins
needed to meet a given amount total
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total
    """

    coin_total = 0

    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while total >= coin:
            total -= coin
            coin_total += 1
    if total > 0:
        return -1
    return coin_total
