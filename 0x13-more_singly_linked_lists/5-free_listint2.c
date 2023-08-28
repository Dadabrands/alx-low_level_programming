#include "lists.h"

/**
 * free_listint2 - Deallocates a linked list
 * @list_head: Pointer to the listint_t list to be deallocated
 */
void free_listint2(listint_t **list_head)
{
	listint_t *temp_node;

	if (list_head == NULL)
		return;

	while (*list_head)
	{
		temp_node = (*list_head)->next;
		free(*list_head);
		*list_head = temp_node;
	}

	*list_head = NULL;
}

