#include "lists.h"

/**
 * insert_nodeint_at_index - put a new node at a given place in a linked list
 * @list_head: Pointer to the first node in the list
 * @index: Index where the new node is added
 * @data: Data to insert in the new node
 *
 * Return: Pointer to the new node, or NULL if insertion fails
 */
listint_t *insert_nodeint_at_index(
		listint_t **list_head, unsigned int index, int data)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *temp = *list_head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !list_head)
		return (NULL);

	new_node->n = data;
	new_node->next = NULL;

	if (index == 0)
	{
		new_node->next = *list_head;
		*list_head = new_node;
		return (new_node);
	}

	for (i = 0; temp && i < index; i++)
	{
		if (i == index - 1)
		{
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}
		else
		{
			temp = temp->next;
		}
	}

	return (NULL);
}
