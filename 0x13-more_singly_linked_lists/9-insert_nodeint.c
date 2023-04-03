#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to a pointer to the first node of the list
 * @idx: index of the list where the new node should be added (starting from 0)
 * @n: value to be stored in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (head == NULL) {
		return NULL;
	}

	if (idx == 0) {
		/* Insert at beginning of list */
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL) {
			return NULL;
		}
		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return new_node;
	}

	current = *head;
	for (i = 0; i < idx - 1; i++) {
		if (current == NULL) {
			return NULL;
		}
		current = current->next;
	}

	/* Check if we reached the end of the list */
	if (current == NULL) {
		return NULL;
	}

	/* Insert after current node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;
	return new_node;
}
