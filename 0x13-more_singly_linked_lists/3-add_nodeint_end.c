#include "lists.h"

/**
 * add_nodeint_end - Appends a node at the end of a linked list
 * @list_head: Pointer to the first element in the list
 * @data: Data to be inserted in the new element
 *
 * Return: Pointer to the new node, or NULL if insertion fails
 */
listint_t *add_nodeint_end(listint_t **list_head, const int data)
{
	listint_t *new_node;
	listint_t *temp = *list_head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = data;
	new_node->next = NULL;

	if (*list_head == NULL)
	{
		*list_head = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}

