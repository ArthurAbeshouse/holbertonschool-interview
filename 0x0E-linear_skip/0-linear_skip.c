#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: The skip list
 * @value: The value to search for
 * Return: node with value, else null
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *now;
	char *msg1, *msg2;

	if (!list)
		return (NULL);

	prev = list;
	now = list->express;
	msg1 = "Value checked at index";
	msg2 = "Value found between indexes";

	while (now)
	{
		printf("%s [%lu] = [%d]\n", msg1, now->index, now->n);
		if (now->n >= value)
		{
			printf("%s [%lu] and [%lu]\n", msg2, prev->index,
			       now->index);
			break;
		}
		else if (!now->express)
		{
			list = now;
			while (list->next)
			{
				list = list->next;
			}
			printf("%s [%lu] and [%lu]\n", msg2, now->index,
			       list->index);
		}
		prev = now;
		now = now->express;
	}
	for (; prev != NULL; prev = prev->next)
	{
		printf("%s [%lu] = [%d]\n", msg1, prev->index, prev->n);
		if (value == prev->n)
			return (prev);
	}
	return (NULL);
}
