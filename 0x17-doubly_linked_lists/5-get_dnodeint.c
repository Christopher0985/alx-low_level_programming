#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to retrieve, starting from 0.
 *
 * Return: Pointer to the nth node, or NULL if not found.
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int position;
	dlistint_t *current_node;

	position = 0;
	if (head == NULL)
		return (NULL);

	current_node = head;
	while (current_node)
	{
		if (position == index)
			return (current_node);
		position++;
		current_node = current_node->next;
	}
	return (NULL);
}
