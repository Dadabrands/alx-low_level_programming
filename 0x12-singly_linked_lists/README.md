# Singly Linked Lists

## Tests
* Tests: This directory contains test files for validation.

## Header File (lists.h)
* lists.h: Header file containing definitions and prototypes for all types and functions used in this project.

Type/File             | Definition/Prototype
----------------------|----------------------
`struct custom_node_s`| • `char *str`
                      | • `unsigned int len`
                      | • `struct custom_node_s *next`
`typedef custom_list_t`| `struct custom_node_s`

**Task Files**
* 0-print_list.c: Prints elements of a `custom_list_t` list.
* 1-list_len.c: Returns the number of elements in a `custom_list_t` list.
* 2-add_node.c: Adds a new node at the beginning of a `custom_list_t` list.
* 3-add_node_end.c: Adds a new node at the end of a `custom_list_t` list.
* 4-free_list.c: Frees a `custom_list_t` list.
* 100-first.c: Prints a message before `main` is executed.
* 101-hello_holberton.asm: Assembly program that prints "Hello, Holberton" using `printf`.
