#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge(int *i, int *j, size_t start, size_t mid, size_t end);
void split(int *i, int *j, size_t start, size_t end);

#endif
