#include "sort.h"

/**
 * heap_sort - Sorts the list in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (size < 2)
		return;

	for (index = size / 2 - 1; index >= 0; index -= 1)
		heapify(array, size, index, size);

	for (index = size - 1; index >= 0; index -= 1)
	{
		if (array[0] != array[index])
			swap(array, size, 0, index);

		heapify(array, index, 0, size);
	}
}

/**
 * heapify - create a heap
 * @array: The array to be sorted
 * @size: The size of the array
 * @index: The index
 * @full_size: The full size of the array
 */
void heapify(int *array, size_t size, int index, size_t full_size)
{
	int largest = index;

	int left = 2 * index + 1, right = 2 * index + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{

		swap(array, full_size, index, largest);
		heapify(array, size, largest, full_size);
	}
}

/**
 * swap - swaps two elements in the array
 * @array: The array to be sorted
 * @size: The size of the array
 * @a: The index of the first element
 * @b: The index of the second element
 */
void swap(int *array, size_t size, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}
