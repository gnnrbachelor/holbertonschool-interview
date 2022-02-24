#include "slide_line.h"


/**
 * merge_left - Merges
 * @line: Line
 * @size: Size
 * Return: Void
 */

void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] = line[i] + line[i + 1];
			line[i + 1] = 0;
		}
	}
}


/**
 * merge_right - Merges
 * @line: Line
 * @size: Size
 * Return: Void
 */

void merge_right(int *line, size_t size)
{
	size_t i;

	for (i = size - 1; (int) i >= 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] = line[i] + line[i - 1];
			line[i - 1] = 0;
		}
	}

}
