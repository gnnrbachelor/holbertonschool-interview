#!/usr/bin/python3
""" Solution to n-queens problem """

import sys

def nqueens(board, row, n):
    """Solves n queens """
    if row == n:
        print_board(board, n)
    else:
        for j in range(n):
            make_move = True
            for i in range(row):
                if check_attack_zone(board, i, j, row):
                    make_move = False
            if make_move:
                board[row] = j
                nqueens(board, row + 1, n)

def check_attack_zone(board, i, j, r):
    """ Checks attack zone  """
    if (board[i] == j) or (board[i] == j - i + r) or (board[i] == i - r + j):
        return True
    return False

def init_board(size):
    """ Initializes board """
    return [0 * size for i in range(size)]

def print_board(board, n):
    """Prints board"""
    b = []
    for i in range(n):
        for j in range(n):
            if j == board[i]:
                b.append([i, j])
    print(b)

def handle_errors():
    """Handles errors"""
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)
    return (n)


if __name__ == '__main__':
    n = handle_errors()
    board = init_board(int(n))
    row = 0
    nqueens(board, row, int(n))
