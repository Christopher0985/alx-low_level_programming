#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index `index` of a
 * listint_t linked list.
 * @head: A pointer to a pointer to the first node of the linked list.
 * @index: The index of the node to delete. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		return (1);
	}

	prev = NULL;
	current = *head;

	for (i = 0; current != NULL && i < index; i++)
	{
	prev = current;
	current = current->next;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;
	free(current);

	return (1);
}
