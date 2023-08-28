#include "lists.h"

/**
 * listint_len - Calculates the number of elements in a linked list
 * @head: Linked list of type listint_t to be traversed
 *
 * Return: The count of nodes in the list
 */
size_t listint_len(const listint_t *head)
i{
	size_t node_count = 0;

	while (head)
	{
		node_count++;
		head = head->next;
	}

	return (node_count);
}

