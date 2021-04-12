#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string to analyze
 * @pattern: the regex pattern
 * Return: 1 if they match, 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str && !*pattern)
		return (1);
	if (*str == *pattern || (*pattern == '.' && *(pattern + 1) != '*'))
		return (regex_match(str + 1, pattern + 1));
	if (*pattern == '.' && *(pattern + 1) == '*')
		return ((regex_match(str, pattern + 2)) ||
			(regex_match(str + 1, pattern)));
	if (*pattern == '*')
		return (regex_match(str, pattern + 1) ||
			(regex_match(str + 1, pattern)));
	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 2));
	return (0);
}
