#include <stdlib.h>
#include "lists.h"

/**
 * custom_list_length - returns the number of elements in a custom_list_t list
 * @h: pointer to the custom_list_t list
 *
 * Return: number of elements in h
 */
size_t list_len(const list_t *x)
{
    size_t j = 0;

    while (x)
    {
        j++;
        x = x->next;
    }
    return (j);
}
