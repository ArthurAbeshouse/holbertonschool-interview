#include "search_algos.h"

/**
 * advanced_binary_search - searches for an array using recursion
 * @array: input array
 * @left: beginning of the array
 * @right: end of the array
 * @value: value to search for
 * Return: index id successful, else -1
 */
int advanced_binary_search(int *array, int left, int right, int value)
{
	int i, half;

	if (left > right)
		return (-1);
	printf("Searching in array:");
	for (i = left; i <= right; i++)
		printf("%s%d", (i != left) ? ", " : " ", array[i]);

	printf("\n");

	if (array[left] == value)
		return (left);
	half = (left + right) / 2;
	if (array[half] < value)
		return (advanced_binary_search(array, half + 1, right,
					       value));
	return (advanced_binary_search(array, left, half, value));
}

/**
 * advanced_binary - searches for an array using the binary search algorithm
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 * Return: index id successful, else -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_search(array, left, right, value));
}
