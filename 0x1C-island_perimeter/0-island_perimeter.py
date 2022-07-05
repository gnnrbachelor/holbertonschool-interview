#!/usr/bin/python3

"""
Island Perimeter

"""


def count_neighbors(grid, i, j):
    """
    count neighbors
    """

    row = len(grid)
    column = len(grid[0])
    count = 0
    if i > 0 and grid[i - 1][j]:
        count += 1
    if j > 0 and grid[i][j - 1]:
        count += 1
    if i < row - 1 and grid[i + 1][j]:
        count += 1
    if j < column - 1 and grid[i][j + 1]:
        count += 1

    return (count)


def island_perimeter(grid):
    """
    Calculates perimeter
    """

    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != 0:
                perimeter += (4 - count_neighbors(grid, i, j))
    return (perimeter)
