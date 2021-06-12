#ifndef _BELINGUIER_UTIL_H_
#define _BELINGUIER_UTIL_H_

#include <stddef.h>

#ifndef LIST_FOREACH
#define LIST_FOREACH(list, var_name)                        \
    for (void *list ## _index = (void *) 0,                 \
    *list ## _total = (void *) list_count(list),            \
    *var_name = list_next(&list);                           \
    list ## _index < list ## _total && var_name;            \
    var_name = list_next(&list), list ## _index++)
#endif

typedef void *list_t;

typedef struct list_tnode_s {
    struct list_tnode_s *next;
    struct list_tnode_s *prev;
    void *element;
} list_node_t;

int list_add(list_t *list_ptr, void *element);
int list_remove(list_t *list_ptr, void *element);
list_t list_node_next(list_t list);
list_t list_node_prev(list_t list);
int list_rotate_next(list_t *list_ptr);
int list_rotate_prev(list_t *list_ptr);
void *list_get(list_t list);
void *list_next(list_t *list_ptr);
size_t list_count(list_t list);
int list_sort(list_t *list_ptr, int (*cmp)(void *, void *));

#endif
