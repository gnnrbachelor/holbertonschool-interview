#!/usr/bin/python3

"""
Island Perimeter

"""

def island_perimeter(grid):
    """
    Calculates perimeter
    """
    count = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != 0:
                if grid[i - 1][j] == 0:
                    count += 1
                if grid[i][j - 1] == 0:
                    count += 1
                if grid[i + 1][j] == 0:
                    count += 1
                if grid[i][j + 1] == 0:
                    count += 1

    return (count)



