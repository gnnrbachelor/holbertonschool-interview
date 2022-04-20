#ifndef SORT_H
#define SORT_H

#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *array, int size, int index, size_t length);


#endif /* SORT_H */
