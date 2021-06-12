/*
** EPITECH PROJECT, 2018
** Unit Test
** File description:
** Test sort list function.
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "list.h"
#include "malloc.h"

int cmp_char(void *str1, void *str2)
{
    int result;

    if (!str1 || !str2)
        return -1;
    result = *((char *) str1) - *((char *) str2);
    if (result == 0)
        return 0;
    if (result > 0)
        return 1;
    return 2;
}

Test(list_sort, normal_test)
{
    list_t list = 0;
    char *str = "NREZVCSAWQYKIXBFGPTUOMDJLH";

    for (size_t i = 0; i < 26; i++)
        cr_assert_eq(list_add(&list, str + i), 0);
    cr_assert_eq(list_sort(&list, cmp_char), 0);
    LIST_FOREACH(list, elem) {
        cr_assert_eq(*((char *) elem), (char) ('A' + ((size_t) list_index)));
        list_remove(&list, elem);
    }
}

Test(list_sort, void_list)
{
    list_t list = 0;

    cr_assert_eq(list_sort(&list, cmp_char), 0);
    cr_assert_eq(list_count(list), 0);
}

Test(list_sort, bad_parameter)
{
    list_t list = 0;

    cr_assert_eq(list_sort(0, cmp_char), -1);
}

Test(list_sort, bad_parameter_2)
{
    list_t list = 0;

    cr_assert_eq(list_sort(&list, 0), -1);
    cr_assert_eq(list_count(list), 0);
}

Test(list_sort, malloc_error)
{
    list_t list = 0;
    char *str = "NREZVCSAWQYKIXBFGPTUOMDJLH";

    for (size_t i = 0; i < 26; i++)
        cr_assert_eq(list_add(&list, str + i), 0);
    malloc_error_test = 1;
    cr_assert_eq(list_sort(&list, cmp_char), -1);
    malloc_error_test = 0;
    LIST_FOREACH(list, elem) {
        cr_assert_eq(*((char *) elem), (char) ('A' + ((size_t) list_index)) + 1);
        list_remove(&list, elem);
    }
}