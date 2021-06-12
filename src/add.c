/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Add element to list.
*/

#include <stdlib.h>
#include "list.h"

static void list_add_node(list_t *list_ptr, list_node_t *node)
{
    list_node_t *prev;
    list_node_t *current = *list_ptr;

    if (current) {
        prev = current->prev;
        prev->next = node;
        node->prev = prev;
        current->prev = node;
        node->next = current;
    } else {
        node->next = node;
        node->prev = node;
        *list_ptr = node;
    }
}

int llistlib_list_add(list_t *list_ptr, void *element)
{
    list_node_t *node;

    if (!list_ptr || !element)
        return -1;
    node = malloc(sizeof(list_node_t));
    if (!node)
        return -2;
    node->element = element;
    list_add_node(list_ptr, node);
    return 0;
}

int list_add(list_t *list_ptr, void *element)
__attribute__ ((weak, alias ("llistlib_list_add")));