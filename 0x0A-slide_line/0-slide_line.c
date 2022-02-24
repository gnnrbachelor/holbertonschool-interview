#include "slide_line.h"

/**
 * swap - Swaps
 * @a: Int 1
 * @b: Int 2
 * Return: Void
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * merge - Merges
 * @line: Line
 * @size: Size
 * Return: Void
 */

void merge(int *line, size_t size, int l_or_r)
{
	size_t i;

	if (l_or_r)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}

	}
	else
	{
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
	}
}






/**
 * left - Lefts
 * @line: Line
 * @size: Size
 * Return: Void
 */

void left(int *line, size_t size)
{
	size_t i;
	size_t j = 0;

	for (i = 0; i < size && j < size; i++)
	{
		while (line[j] == 0 && j < size && j + 1 < size)
			j++;
		if (!line[i])
			swap(&line[j], &line[i]);
		j++;
	}
}

/**
 * right - Rights
 * @line: Line
 * @size: Size
 * Return: Void
 */

void right(int *line, size_t size)
{
	size_t i;
	size_t j = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) j >= 0; i--)
	{
		while (line[j] == 0 && (int) j > 0)
			j--;
		if (!line[i])
			swap(&line[j], &line[i]);
		j--;
	}
}


/**
 * slide_line - 2048 Game implementation
 * @line: Line
 * @size: Size
 * @direction: Direction
 * Return: 1 or 0
 */


int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		left(line, size);
		merge(line, size, 1);
		left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		right(line, size);
		merge(line, size, 0);
		right(line, size);
		return (1);
	}
	return (0);
}


