/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Get current element to list.
*/

#include "list.h"

void *llistlib_list_get(list_t list)
{
    if (!list)
        return 0;
    return ((list_node_t *) list)->element;
}

void *list_get(list_t list)
__attribute__ ((weak, alias ("llistlib_list_get")));