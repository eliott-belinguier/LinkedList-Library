/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Rotate list to next element.
*/

#include "list.h"

int llistlib_list_rotate_next(list_t *list)
{
    if (!list || !*list)
        return -1;
    *list = list_node_next(*list);
    return 0;
}

int list_rotate_next(list_t *list)
__attribute__ ((weak, alias ("llistlib_list_rotate_next")));