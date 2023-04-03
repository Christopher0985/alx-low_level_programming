#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Pointer to pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *temp, *prev;

	if (h == NULL || *h == NULL)
		return (0);

	temp = *h;
	prev = NULL;

	while (temp != NULL)
	{
		size++;

		if (temp < temp->next && temp < prev)
			break;

		prev = temp;
		temp = temp->next;

		free(prev);
	}

	*h = NULL;

	return (size);
}
