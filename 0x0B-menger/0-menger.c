#include "menger.h"

/**
 * menger - Prints menger sponge
 * @level: levels deep
 * Return: Void
 */

void menger(int level)
{
	int row, col, empty, flag;
	int size = pow(3, level);

	if (level == 0)
	{
		putchar('#');
		putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			for (empty = 1; empty < size; empty *= 3)
			{
				if ((row / empty) % 3 == 1 && (col / empty) % 3 == 1)
				{
					flag = 0;
					break;
				}
				else
					flag = 1;

			}
			if (flag == 0)
				putchar(' ');
			else
				putchar('#');

		}
		putchar('\n');
	}
}
