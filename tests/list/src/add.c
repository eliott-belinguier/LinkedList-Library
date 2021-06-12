/*
** EPITECH PROJECT, 2018
** Unit Test
** File description:
** Test add to list function.
*/

#include <criterion/criterion.h>
#include "list.h"
#include "malloc.h"

Test(list_add, normal_test)
{
    list_t list = 0;
    list_t current;
    char *str1 = "Test1";
    char *str2 = "Test2";
    char *str3 = "Test3";
    char *str4 = "Test4";

    cr_assert_eq(list_add(&list, str1), 0);
    cr_assert_eq(list_add(&list, str2), 0);
    cr_assert_eq(list_add(&list, str3), 0);
    cr_assert_eq(list_add(&list, str4), 0);
    current = list;
    cr_assert_eq(list_next(&current), str1);
    cr_assert_eq(list_next(&current), str2);
    cr_assert_eq(list_next(&current), str3);
    cr_assert_eq(list_next(&current), str4);
    cr_assert_eq(list_next(&current), str1);
    list_remove(&list, str1);
    list_remove(&list, str2);
    list_remove(&list, str3);
    list_remove(&list, str4);
}

Test(list_add, bad_parameter)
{
    char *str1 = "Test1";

    cr_assert_eq(list_add(0, str1), -1);
}

Test(list_add, bad_parameter_2)
{
    list_t list = 0;

    cr_assert_eq(list_add(&list, 0), -1);
    cr_assert_eq(list, 0);
}

Test(list_add, malloc_error)
{
    list_t list = 0;
    char *str1 = "Test1";

    malloc_error_test = 1;
    cr_assert_eq(list_add(&list, str1), -2);
    malloc_error_test = 0;
    cr_assert_eq(list, 0);
    list_remove(&list, str1);
}