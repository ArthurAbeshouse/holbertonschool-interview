#include "lists.h"

/**
 * check_cycle - checks for a cycle in the linked list
 * @list: pointer to the head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	if (list == NULL || list->next == NULL)
		return (0);

	listint_t *fast, *slow;

	fast = slow = list;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}