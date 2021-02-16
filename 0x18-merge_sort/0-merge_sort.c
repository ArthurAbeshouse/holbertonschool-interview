#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: the number of elements inside the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;
	size_t a = 0;

	if (!array || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	while (a < size)
	{
		buffer[a] = array[a];
		a += 1;
	}

	split(array, buffer, 0, size);
	free(buffer);
}

/**
 * split - splits the array
 * @i: int array
 * @j: int array
 * @start: starting index
 * @end: end index
 */

void split(int *i, int *j, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = (start + end) / 2;

	split(i, j, start, mid);
	split(i, j, mid, end);
	merge(j, i, start, mid, end);
}

/**
 * merge - merges the two int arrays in sorted order
 * @i: int array
 * @j: int array
 * @start: starting index
 * @mid: middle index
 * @end: end index
 */
void merge(int *i, int *j, size_t start, size_t mid, size_t end)
{
	size_t l = start, m = mid, a = start;

	while (a < end)
	{
		i[a] = j[a];
		a += 1;
	}

	printf("Merging...\n[left]: ");
	print_array(&i[start], mid - start);
	printf("[right]: ");
	print_array(&i[mid], end - mid);

	a = start;
	while (a < end)
	{
		if (l < mid && (m >= end || i[l] <= i[m]))
			j[a] = i[l++];
		else
			j[a] = i[m++];

		a += 1;
	}
	printf("[Done]: ");
	print_array(&j[start], end - start);
}
