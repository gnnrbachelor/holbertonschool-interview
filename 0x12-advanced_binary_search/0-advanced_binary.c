#include "search_algos.h"

/**
 * recursive_binary - Recursive binary search
 * @array: Array
 * @l: Left
 * @r: Right
 * @value: Value
 * Return: -1 or index
 */

int recursive_binary(int *array, size_t l, size_t r, int value)
{
	size_t m;
	size_t i;

	if (!array)
		return (-1);

	m = (l + r) / 2;
	printf("Searching in array: ");
	for (i = l; i <= r; i++)
	{
		printf("%d", array[i]);
		if (i == r)
			printf("\n");
		else
			printf(", ");
	}

	if (array[l] == value)
		return (l);

	if (array[l] != array[r])
	{
		if (array[m] < value)
			return (recursive_binary(array, m + 1, r, value));
		if (array[m] >= value)
			return (recursive_binary(array, l, m, value));
	}
	return (-1);
}

/**
 * advanced_binary - Advanced Binary Search
 * @array: Array
 * @size: Size
 * @value: Value
 * Return: -1 or index
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t l = 0;
	size_t r = size - 1;

	if (!array)
		return (-1);

	return (recursive_binary(array, l, r, value));

}
