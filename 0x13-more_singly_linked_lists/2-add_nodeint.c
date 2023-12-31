#include "lists.h"

/**
 * add_nodeint - Inserts a new node at the beginning of a linked list
 * @list_head: Pointer to the first node in the list
 * @data: Data to be inserted in the new node
 *
 * Return: Pointer to the new node, or NULL if insertion fails
 */
listint_t *add_nodeint(listint_t **list_head, const int data)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = data;
	new_node->next = *list_head;
	*list_head = new_node;

	return (new_node);
}

