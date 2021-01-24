#include "lists.h"

/**
 * find_listint_loop - find the loop in list
 *
 * @head: input of head of linked list
 *
 * Return: return the list
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *h, *holder;
	int count = 0, n = 0;

	if (head == NULL)
		return (0);
	holder = head;
	while (holder)
	{
		holder = holder->next;
		++count;
		h = head;
		n = 0;
		while (n < count)
		{
			if (h == holder)
			{
				return (holder);
			}
			else
			{
				h = h->next;
				++n;
			}
		}
	}
	return (NULL);
}
