#include "sort.h"

/**
 * radix_sort - sorts an array using the radix method
 * @array: the array to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	
	size_t a[10][10], b[10];
	size_t i, j, k, r, NOP = 0, div = 1, pass;
	size_t large = get_the_max(array, size);

	while (large > 0)
	{
		++NOP;
		large /= 10;
	}
	for (pass = 0; pass < NOP; pass += 1)
	{
		for (i = 0; i < 10; i += 1)
			b[i] = 0;
		for (i = 0; i < size; i += 1)
		{
			r = (array[i] / div) % 10;
			a[r][b[r]] = array[i];
			b[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k += 1)
		{
			for (j = 0; j < b[k]; j += 1)
			{
				array[i] = a[k][j];
				i += 1;
			}
		}
		div *= 10;
		print_array(array, size);
	}

}

/**
 * get_the_max - determines which digits are the largest elements in the array
 * @array: the array to sort
 * @size: the size of the array
 * Return: the max digits
 */
int get_the_max(int *array, size_t size)
{
	size_t i;
	int maximum = array[0];

	for (i = 1; i < size; i += 1)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}
	return (maximum);
}
