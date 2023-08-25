#include <stdio.h>
#include "lists.h"

/**
 * custom_print_list - prints all the elements of a custom_list_t list
 * @h: pointer to the custom_list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *x)
{
    size_t a = 0;

    while (x)
    {
        if (!x->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", x->len, x->str);
        x = x->next;
        a++;
    }

    return (a);
}
