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

	if (!list)
		return (NULL);

	prev = list;
	now = list->express;

	while (now)
	{
		printf("Value checked at index [%lu] and [%d]\n", now->index,
		       now->n);
		if (now->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, now->index);
			break;
		}
		else if (!now->express)
		{
			list = now;
			while (list->next)
			{
				list = list->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			       now->index, list->index);
		}
		prev = now;
		now = now->express;
	}
	for (; prev != NULL; prev = prev->next)
	{
		printf("Value checked at index [%lu] and [%d]\n", prev->index,
		       prev->n);
		if (value == prev->n)
			return (prev);
	}
	return (NULL);
}
