#!/usr/bin/python3
"""Log this parse"""


import sys


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


def printer(size):
    """Print function"""
    print("File size: {}".format(size))
    for status in sorted(stat.keys()):
        if stat[status]:
            print("{}: {}".format(status, stat[status]))


def log_parse():
    """Progam to parse log"""
    count = 0
    size = 0
    for line in sys.stdin:
        try:
            info_list = line.split()
            size += int(info_list[-1])
            if info_list[-2] in stat:
                stat[info_list[-2]] += 1
        except:
            pass
        if count == 9:
            printer(size)
            count = -1
        count += 1


if __name__ == '__main__':
    """Entry point"""
    try:
        log_parse()
    except KeyboardInterrupt:
        log_parse()
        raise
    log_parse()

