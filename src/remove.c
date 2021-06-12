/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Remove element to list.
*/

#include <stdlib.h>
#include "list.h"

static void list_remove_node(list_t *list_ptr, list_node_t *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (*list_ptr == node)
        *list_ptr = (node->next != node) ? node->next : 0;
    free(node);
}

int llistlib_list_remove(list_t *list_ptr, void *element)
{
    list_t prev = 0;
    list_t current;

    if (!list_ptr || !element)
        return -1;
    for (current = *list_ptr; current && (!prev || current != *list_ptr);
    prev = current, current = list_node_next(current)) {
        if (list_get(current) == element) {
            list_remove_node(list_ptr, current);
            return 0;
        }
    }
    return -1;
}

int list_remove(list_t *list_ptr, void *element)
__attribute__ ((weak, alias ("llistlib_list_remove")));