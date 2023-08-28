#include "lists.h"

/**
 * get_nodeint_at_index - Retrieves the node at a spec. index in a linked list
 * @list_head: Pointer to the first node in the linked list
 * @position: Index of the desired node to retrieve
 *
 * Return: Pointer to the requested node, or NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *list_head, unsigned int position)
{
	unsigned int current_index = 0;
	listint_t *current_node = list_head;

	while (current_node && current_index < position)
	{
		current_node = current_node->next;
		current_index++;
	}

	return (current_node ? current_node : NULL);
}

