#!/usr/bin/python3

""" Rain Solution """


def rain(walls):
    """ Rain solution """
    if not walls or len(walls) < 3:
        return 0

    water = 0

    for i in range(0, len(walls)):
        max_l = walls[i]
        for j in range(i):
            max_l = max(max_l, walls[j])

        max_r = walls[i]

        for j in range(i + 1, len(walls)):
            max_r = max(max_r, walls[j])

        water = water + (min(max_l, max_r) - walls[i])

    return water
