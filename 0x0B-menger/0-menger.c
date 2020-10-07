#include "menger.h"

/**
 * menger - draws a Menger Sponge
 * @level: prints the Menger level
 */
void menger(int level)
{
	int row1, col1, row2, col2;
	int size = pow(3, level);
	char _char;

	if (level < 0)
		return;

	for (col1 = 0; col1 < size; col1 += 1)
	{
		for (row1 = 0; row1 < size; row1 += 1)
		{
			_char = '#';
			row2 = row1;
			col2 = col1;

			while (row2 || col2)
			{
				if (row2 % 3 == 1 && col2 % 3 == 1)
					_char = ' ';
				row2 /= 3;
				col2 /= 3;
			}
			putchar(_char);
		}
		putchar('\n');
	}
}
