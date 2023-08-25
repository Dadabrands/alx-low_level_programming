#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * custom_add_node - adds a new node at the beginning of a custom_list_t list
 * @head: double pointer to the custom_list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new;
    unsigned int len = 0;

    while (str[len])
        len++;

    new = malloc(sizeof(ist_t));
    if (!new)
        return (NULL);

    new->str = strdup(str);
    new->len = len;
    new->next = (*head);
    (*head) = new;

    return (*head);
}
