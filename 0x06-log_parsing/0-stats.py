#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""
if __name__ == "__main__":
    import sys

    count = 0
    size = 0
    status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def print_stats():
        print("File size: " + str(size))
        for s in sorted(status.keys()):
            if status[s]:
                print(str(s) + ": " + str(status[s]))

    try:
        for line in sys.stdin:
            wrds = line.split()
            if (len(wrds) > 2):
                try:
                    size += int(wrds[8])
                except:
                    pass
                try:
                    status[int(wrds[7])] += 1
                except:
                    pass
            count += 1
            if count == 10:
                print_stats()
                count = 0
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
