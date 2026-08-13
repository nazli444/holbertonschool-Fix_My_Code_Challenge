#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;
	i = 0;
	while (i < index && *head != NULL)
	{
		*head = (*head)->next;
		i++;
	}

	if (index != i || *head == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved_head);
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		if ((*head)->next != NULL)
			(*head)->next->prev = (*head)->prev;
		free(*head);
		*head = saved_head;
	}

	return (1);
}
