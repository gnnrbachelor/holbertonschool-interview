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
size = 0

if __name__ == '__main__':
    """Progam to parse log"""
    count = 0
    for line in sys.stdin:
        try:
            info_list = line.split()
            size += int(info_list[-1])
            if info_list[-2] in stat:
                stat[info_list[-2]] += 1
        except:
            pass
        if count == 9:
            print("File size: {}".format(size))
            for status in sorted(stat.keys()):
                if stat[status]:
                    print("{}: {}".format(status, stat[status]))
            count = -1
        count += 1
