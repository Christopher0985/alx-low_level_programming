#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a specified position
 * in a doubly linked list.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index of the new node.
 * @n: Value of the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current_node;
	unsigned int position;

	new_node = NULL;
	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		current_node = *h;
		position = 1;
		if (current_node != NULL)
			while (current_node->prev != NULL)
				current_node = current_node->prev;
		while (current_node != NULL)
		{
			if (position == idx)
			{
				if (current_node->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
					new_node->n = n;
					new_node->next = current_node->next;
					new_node->prev = current_node;
					current_node->next->prev = new_node;
					current_node->next = new_node;
					}
				}
				break;
			}
			current_node = current_node->next;
			position++;
		}
	}
	return (new_node);
}
