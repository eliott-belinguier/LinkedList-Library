/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Count elements in list.
*/

#include "list.h"

size_t llistlib_list_count(list_t list)
{
    list_t current = list;
    size_t total;

    for (total = 0; current && (!total || current != list);
    total++, list_rotate_next(&current));
    return total;
}

size_t list_count(list_t list)
__attribute__ ((weak, alias ("llistlib_list_count")));