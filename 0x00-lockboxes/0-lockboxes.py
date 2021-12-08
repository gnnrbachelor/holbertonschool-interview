#!/usr/bin/python3
"""Mod for lockbox"""


def canUnlockAll(boxes):
    """ Lockbox problem """
    keychain = [0]
    for key in keychain:
        for j in boxes[key]:
            if j not in keychain:
                 keychain.append(j)
    for i in range(len(boxes)):
        if i not in keychain:
            return False
    return True
