#include "sandpiles.h"

/**
 * print_matrix - prints a matrix
 * @grid: the matrix to print
 */
void print_matrix(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i += 1)
	{
		for (j = 0; j < 3; j += 1)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - calculates the sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_sandpiles(grid1, grid2);
	while (verify_if_stable(grid1))
	{
		print_matrix(grid1);
		collapse_sandpile(grid1, grid2);
	}
}

/**
 * add_sandpiles - adds two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 */
void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i += 1)
		for (j = 0; j < 3; j += 1)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}

}

/**
 * verify_if_stable - checks if all the values in a sandpile
 * are between 0 and 3
 * @grid: a 3x3 sandpile
 * Return: true if all tiles are stable else false
 */
int verify_if_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i += 1)
		for (j = 0; j < 3; j += 1)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	return (0);
}

/**
 * collapse_sandpile - collapses a sandpile
 * @grid1: the sandpile to collapse
 * @grid2: the buffer
 */
void collapse_sandpile(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i += 1)
		for (j = 0; j < 3; j += 1)
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j] += 1;
				if (i + 1 <= 2)
					grid2[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid2[i][j - 1] += 1;
				if (j + 1 <= 2)
					grid2[i][j + 1] += 1;
			}
	add_sandpiles(grid1, grid2);
}
