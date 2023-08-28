#include "lists.h"

/**
 * sum_listint - Computes the sum of all the data in a listint_t list
 * @list_head: First node in the linked list
 *
 * Return: The resulting sum
 */
int sum_listint(listint_t *list_head)
{
	int result_sum = 0;
	listint_t *current_node = list_head;

	while (current_node)
	{
		result_sum += current_node->n;
		current_node = current_node->next;
	}

	return (result_sum);
}

