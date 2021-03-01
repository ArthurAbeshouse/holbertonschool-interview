#include "list.h"

/**
 * add_node_end - adds a new node to the end of a double circular linked list
 * @list: double pointer to the list head
 * @str: the string to copy into the new node
 * Return: pointer to new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new = NULL;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);

	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list)
		new->next = *list;
	else
		new->next = new;

	if (*list)
		new->prev = (*list)->prev;
	else
		new->prev = new;

	if (*list)
	{
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	else
		*list = new;
	return (new);
}

/**
 * add_node_begin - adds a new node to the beginning of the list
 * @list: double pointer to the list head
 * @str: the string to copy into the new node
 * Return: pointer to new node, or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new = NULL;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list)
		new->next = *list;
	else
		new->next = new;

	if (*list)
		new->prev = (*list)->prev;
	else
		new->prev = new;

	if (*list)
	{
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	*list = new;
	return (new);
}
