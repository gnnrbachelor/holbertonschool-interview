#!/usr/bin/python3
"""Log this parse"""


import sys


def printer(stat, size):
    """Print function"""
    print("File size: {}".format(size[0]))
    for status in sorted(stat.keys()):
        if stat[status]:
            print("{}: {}".format(status, stat[status]))


def log_parse(stat, args, size, count):
    """Progam to parse log"""
    try:
        size[0] += int(args[-1])
        if args[-2] in stat and args[-2].isdigit():
            stat[args[-2]] += 1
        if count[0] == 9:
            printer(stat, size)
            count[0] = -1
        else:
            count[0] += 1
    except Exception:
        pass


if __name__ == '__main__':
    """Entry point"""
    stat = {
       "200": 0,
       "301": 0,
       "400": 0,
       "401": 0,
       "403": 0,
       "404": 0,
       "405": 0,
       "500": 0
    }

    size = [0]
    count = [0]

    while True:
        try:
            args = input().split()
            log_parse(stat, args, size, count)
        except (KeyboardInterrupt, EOFError):
            printer(stat, size)
            exit()
