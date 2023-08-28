#include "lists.h"

/**
 * delete_nodeint_at_index - minus a node from a linked list at a spec. index
 * @list_head: Pointer to the first element in the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 (Success), or -1 (Failure)
 */
int delete_nodeint_at_index(listint_t **list_head, unsigned int index)
{
	listint_t *temp = *list_head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*list_head == NULL)
		return (-1);

	if (index == 0)
	{
		*list_head = (*list_head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
