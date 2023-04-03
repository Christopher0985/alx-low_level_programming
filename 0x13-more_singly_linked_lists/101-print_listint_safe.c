#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list,
 * avoiding infinite loops.
 * @head: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *turtle = head, *hare = head;
	size_t count = 0;

	while (hare && hare->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;

		if (turtle == hare)
		{
			printf("-> [%p] %d\n", (void *)turtle, turtle->n);
			count++;
			break;
		}

		printf("[%p] %d\n", (void *)turtle, turtle->n);
		count++;
	}

	if (!hare || !hare->next)
	{
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}
	}

	return (count);
}
