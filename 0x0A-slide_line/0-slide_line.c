#include "slide_line.h"

/**
 * to_the_left - slides array to the left
 * @line: array of ints to slide
 * @size: size of the array
 * Return: 1 upon success, or 0 upon failure
 */
int to_the_left(int *line, size_t size)
{
	size_t index, zeros;

	for (index = 0; index < size; index += 1)
	{
		zeros = index + 1;
		while (zeros < size)
		{
			if (line[index] == 0 && line[zeros] != 0)
			{
				line[index] = line[zeros];
				line[zeros] = 0;
				index -= 1;
				break;
			}
			if (line[index] == line[zeros] && line[index] != 0)
			{
				line[index] *= 2;
				line[zeros] = 0;
				break;
			}
			else if (line[zeros] != 0 && line[index + 1] == 0)
			{
				line[index + 1] = line[zeros];
				line[zeros] = 0;
				break;
			}
			zeros += 1;
		}
	}
	return (1);
}

/**
 * to_the_right - slides array to the right
 * @line: array of ints to slide
 * @size: size of the array
 * Return: 1 upon success, or 0 upon failure
 */
int to_the_right(int *line, size_t size)
{
	size_t index, zeros;

	for (index = 1; index <= size; index += 1)
	{
		zeros = index + 1;
		while (zeros <= size)
		{
			if (line[size - index] == 0 && line[size - zeros] != 0)
			{
				line[size - index] = line[size - zeros];
				line[size - zeros] = 0;
				index -= 1;
				break;
			}
			if (line[size - index] == line[size - zeros] && line[
				    size - index] != 0)
			{
				line[size - index] *= 2;
				line[size - zeros] = 0;
				break;
			}
			else if (line[size - zeros] != 0 && line[size - (
						 index + 1)] == 0)
			{
				line[size - (index + 1)] = line[size - zeros];
				line[size - zeros] = 0;
				break;
			}
			zeros += 1;
		}
	}
	return (1);
}

/**
 * slide_line - slides array of ints to the left or right
 * @line: array of ints to slide
 * @size: size of the array
 * @direction: the direction to slide
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);
	if (direction == SLIDE_LEFT)
		to_the_left(line, size);
	else if (direction == SLIDE_RIGHT)
		to_the_right(line, size);
	else
		return (0);
	return (1);
}
