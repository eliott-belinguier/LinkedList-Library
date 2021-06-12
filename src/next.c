/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Get current element to list and move next.
*/

#include "list.h"

void *llistlib_list_next(list_t *list)
{
    void *element;

    if (!list)
        return 0;
    element = list_get(*list);
    list_rotate_next(list);
    return element;
}

void *list_next(list_t *list)
__attribute__ ((weak, alias ("llistlib_list_next")));