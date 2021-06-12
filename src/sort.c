/*
** EPITECH PROJECT, 2018
** LinkedList Library
** File description:
** Sort list from custom comparison function.
*/

#include "list.h"

static void *list_get_higher_element(list_t *list_ptr,
        int (*cmp)(void *, void *))
{
    list_t current = *list_ptr;
    list_t best = 0;
    void *result;

    for (; current && (!best || current != *list_ptr);
    current = list_node_next(current))
        if (!best || cmp(list_get(current), list_get(best)) == 2)
            best = current;
    result = list_get(best);
    list_remove(list_ptr, result);
    return result;
}

int llistlib_list_sort(list_t *list_ptr, int (*cmp)(void *, void *))
{
    list_t new_list = 0;
    size_t total;
    size_t index;
    void *element;

    if (!list_ptr || !cmp)
        return -1;
    total = list_count(*list_ptr);
    if (!total)
        return 0;
    for (index = 0; (element = list_get_higher_element(list_ptr, cmp));
         index += !list_add(&new_list, element));
    *list_ptr = new_list;
    if (index != total)
        return -1;
    return 0;
}

int list_sort(list_t *list_ptr, int (*cmp)(void *, void *))
__attribute__ ((weak, alias ("llistlib_list_sort")));