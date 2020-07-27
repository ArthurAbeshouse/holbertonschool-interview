#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: The head of the list
 * @number: The number to insert
 * Return: new node or NULL
 **/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;

	temp = *head;

	if (!*head || number < (*head)->n)
	{
		new_node->next = temp;
		*head = new_node;
		return (new_node);
	}
	while (temp->next && number > temp->next->n)
		temp = temp->next;

	new_node->next = temp->next;
	temp->next = new_node;
	return (new_node);
}
