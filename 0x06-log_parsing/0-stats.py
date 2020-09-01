#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""
from sys import stdin


count = 0
size = 0
status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def print_stats():
    print("File size: " + str(size))
    for s in sorted(status):
        if status[s]:
            print(str(s) + ": " + str(status[s]))


if __name__ == "__main__":
    try:
        for line in stdin:
            if count == 10:
                print_stats()
                count = 0
            wrds = line.split()
            size += int(wrds[8])
            status[int(wrds[7])] += 1
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
