/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Rotate list to previous element.
*/

#include "list.h"

int llistlib_list_rotate_prev(list_t *list_ptr)
{
    if (!list_ptr || !*list_ptr)
        return -1;
    *list_ptr = list_node_prev(*list_ptr);
    return 0;
}

int list_rotate_prev(list_t *list_ptr)
__attribute__ ((weak, alias ("llistlib_list_rotate_prev")));