#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list
 * @head: Linked list of type listint_t to be printed
 *
 * Return: The number of nodes in the list
 */
size_t print_listint(const listint_t *head)
{
	size_t num_nodes = 0;

	while (head)
	{
		printf("%d\n", head->n);
		num_nodes++;
		head = head->next;
	}

	return (num_nodes);
}
