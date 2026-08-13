#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to pointer to the head of the list
 * @index: Index of the node to delete, starting at 0
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;

	/* Case 1: Deleting index 0 (the head) */
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved_head);
		return (1);
	}

	/* Case 2: Deleting index > 0 */
	tmp = *head;
	for (i = 0; tmp != NULL && i < index; i++)
	{
		tmp = tmp->next;
	}

	/* If index is out of range */
	if (tmp == NULL)
		return (-1);

	/* Re-link previous node to next node */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	/* Re-link next node to previous node */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
