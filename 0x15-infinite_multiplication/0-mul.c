#include "holberton.h"

/**
 * main - the entry point
 * @argc: argument count
 * @argv: string of pointers
 * Return: the status code
 */
int main(int argc, char **argv)
{
	char *top, *bottom, *res = NULL;
	unsigned int len, len1, len2, count = 0;

	if (argc != 3)
		error_msg();
	len1 = _strlen(argv[1]), len2 = _strlen(argv[2]), len = len1 + len2;
	top = argv[1];
	bottom = argv[2];
	res = malloc(len * sizeof(char));
	if (!res)
		error_msg();
	while (count < len * sizeof(char))
	{
		res[count] = 0;
		count += 1;
	}

	multi(len, len1, len2, top, bottom, res);

	_putchar('\n');
	free(res);
	return (0);
}

/**
 * multi - multiplies two numbers
 * @len: the sum of len1 and len2
 * @len1: the front of the string
 * @len2: the end of the string
 * @top: the number at the front of the string
 * @bottom: the number at the end of the string
 * @res: the results
 * Return: the product
 */
char *multi(int len, int len1, int len2, char *top, char *bottom, char *res)
{
	int i, j, k = 0, carry = 0, num1 = 0, num2 = 0, sum = 0;

	for (i = (len1 > len2 ? len2 : len1) - 1; i >= 0; i -= 1)
	{
		if (!_isdigit(top[i]))
		{
			free(res);
			error_msg();
		}
		num1 = top[i] - '0';
		for (j = (len1 > len2 ? len1 : len2) - 1; j >= 0; j -= 1)
		{
			if (!_isdigit(bottom[j]))
			{
				free(res);
				error_msg();
			}
			num2 = bottom[j] - '0';
			sum = num1 * num2;
			res[i + j + 1] += sum % 10;
			if (res[i + j + 1] > 9)
			{
				res[i + j] += res[i + j + 1] / 10;
				res[i + j + 1] = res[i + j + 1] % 10;
			}
			res[i + j] += carry = sum / 10;
		}
	}
	while (res[k] == 0 && k < len)
		k += 1;

	if (k == len)
		_putchar(res[len - 1] + '0');
	else
	{
		for (i = k; i < len; i += 1)
			_putchar(res[i] + '0');
	}
	return (res);
}

/**
 * _strlen - returns the length of a string
 * @s: char type
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{

	}
	return (a);
}

/**
 * _isdigit - Checks for digits (0 through 9)
 * @c: int type param
 * Return: 1 if uppercase, else 0
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);

	return (0);
}

/**
 * error_msg - prints the error message
 * Return: void
 */
void error_msg(void)
{
	int e = 0;
	char error_message[] = "Error";

	while (e < 5)
	{
		_putchar(error_message[e]);
		e += 1;
	}

	_putchar('\n');
	exit(98);
}
