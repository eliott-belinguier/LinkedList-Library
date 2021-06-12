/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Get previous node to list.
*/

#include "list.h"

list_t llistlib_list_node_prev(list_t list)
{
    if (!list)
        return 0;
    return ((list_node_t *) list)->prev;
}

list_t list_node_prev(list_t list)
__attribute__ ((weak, alias ("llistlib_list_node_prev")));