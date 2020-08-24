#include "lists.h"

/**
 * is_palindrome - determines if the linkedlist is a palindrome
 * @head: the head of the linkedlist
 * Return: 1 if the palindrome is true, 0 if otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *deref;

	if (head)
	{
		deref = *head;
		return (is_palin(&deref, deref));
	}
	return (0);
}

/**
 * is_palin - checks if the linked list is a palindrome
 * @left: pointer that keeps track of the left side of the linked list
 * @right: pointer that keeps track of the right side of the linked list
 * Return: 1 if the palindrome is true, 0 if otherwise
 */
int is_palin(listint_t **left, listint_t *right)
{
	if (right == NULL)
		return (1);
	if (is_palin(left, right->next) && (*left)->n == right->n)
	{
		*left = (*left)->next;
		return (1);
	}
	return (0);
}
