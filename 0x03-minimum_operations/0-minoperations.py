#!/usr/bin/python3

""" Minimum Operations """


def minOperations(n):
    """
     min_opations
    """
    if n <= 1:
        return 0
    possible_op = 2
    min_op = 0
    quotient = n
    while quotient > 1:
        if (quotient % possible_op) == 0:
            quotient = quotient // possible_op
            min_op += possible_op
        else:
            possible_op += 1

    return min_op
