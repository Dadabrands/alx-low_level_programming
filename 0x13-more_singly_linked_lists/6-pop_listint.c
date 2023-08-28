#include "lists.h"

/**
 * pop_listint - Removes the head node of a linked list
 * @list_head: Pointer to the first element in the linked list
 *
 * Return: The data inside the deleted element,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **list_head)
{
	listint_t *temp;
	int data;

	if (!list_head || !*list_head)
		return (0);

	data = (*list_head)->n;
	temp = (*list_head)->next;
	free(*list_head);
	*list_head = temp;

	return (data);
}
