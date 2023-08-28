#include "lists.h"

/**
 * free_listint - Releases memory allocated for a linked list
 * @list_head: listint_t list to be freed
 */
void free_listint(listint_t *list_head)
{
	listint_t *temp_node;

	while (list_head)
	{
		temp_node = list_head->next;
		free(list_head);
		list_head = temp_node;
	}
}
