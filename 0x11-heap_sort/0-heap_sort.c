#include "sort.h"

/**
 * heap_sort - Heap Sort
 * @array: Array
 * @size: Size
 * Return: Void
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!size || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}

}

/**
 * swap - Swaps
 * @a: a
 * @b: b
 * Return: Void
 *
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Makes heap
 * @array: Array
 * @size: Heap Size
 * @index: index
 * @length: array length
 */

void heapify(int *array, int size, int index, size_t length)
{
	int max = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;

	if (l < size && array[l] > array[max])
		max = l;

	if (r < size && array[r] > array[max])
		max = r;

	if (max != index)
	{
		swap(&array[index], &array[max]);
		print_array(array, length);
		heapify(array, size, max, length);
	}
}

