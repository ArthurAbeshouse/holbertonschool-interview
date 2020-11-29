#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void heap_sort(int *array, size_t size);
void swap(int *array, size_t size, int a, int b);
void heapify(int *array, size_t size, int index, size_t full_size);
void print_array(const int *array, size_t size);

#endif
