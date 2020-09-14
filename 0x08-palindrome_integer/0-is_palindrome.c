#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 * @n: the integer that's passed through
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long n_clone, remains = 0, reverse = 0;

	for (n_clone = n; n_clone != 0; n_clone /= 10)
	{
		remains = n_clone % 10;
		reverse = reverse * 10 + remains;
	}

	return (n == reverse ? 1 : 0);
}
