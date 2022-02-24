#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void swap(int *a, int *b);
void left(int *line, size_t size);
void right(int *line, size_t size);
void merge(int *line, size_t size, int l_or_r);


#endif
