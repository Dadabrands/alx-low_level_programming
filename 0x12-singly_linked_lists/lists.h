#ifndef CUSTOM_LISTS_H
#define CUSTOM_LISTS_H

/**
 * struct custom_node_s - singly linked list node
 * @str: dynamically allocated string
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct custom_node_s
{
    char *str;
    unsigned int len;
    struct custom_node_s *next;
} custom_list_t;

size_t custom_print_list(const custom_list_t *h);
size_t custom_list_length(const custom_list_t *h);
custom_list_t *custom_add_node(custom_list_t **head, const char *str);
custom_list_t *custom_add_node_end(custom_list_t **head, const char *str);
void custom_free_list(custom_list_t *head);

#endif
