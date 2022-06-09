#include "sort.h"


void merge(int *array, int *cpy, size_t start, size_t mid, size_t size)
{
	size_t i, l, r;

	printf("Merging...\n[left]: ");
	print_array(cpy + start, mid - start);
	printf("[right]: ");
	print_array(cpy + mid, size - mid);

	for (i = l = start, r = mid; i < size; i++)
	{
		if (l < mid && (r >= size || cpy[l] <= cpy[r]))
			array[i] = cpy[l++];
		else
			array[i] = cpy[r++];
	}
	printf("[Done]: ");
	print_array(array + start, size - start);
}



/**
 * split - Splits
 * @arr: Array
 * @cpy: Copy
 * @start: Start
 * @size: Size
 * Return: Void
 */

void split(int *array, int *cpy, size_t start, size_t size)
{
	size_t mid;

	if (size - start <= 1)
		return;

	mid = (start + size) /  2;
	split(cpy, array, start, mid);
	split(cpy, array, mid, size);
	merge(array, cpy, start, mid, size);
}


/**
 * merge_sort - Merge Sort
 * @array: Array
 * @size: Size
 */

void merge_sort(int *array, size_t size)
{
	int *cpy;


	if (!array || size < 2)
		return;

	cpy = malloc(size * sizeof(*cpy));
	if (!cpy)
		return;

	memcpy(cpy, array, size * sizeof(*cpy));
	split(array, cpy, 0, size);
	free(cpy);
}
