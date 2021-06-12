/*
** EPITECH PROJECT, 2018
** Unit Test
** File description:
** Test get previous node to list function.
*/

#include <criterion/criterion.h>
#include "list.h"

Test(list_node_prev, normal_test)
{
    list_t list = 0;
    char *str1 = "Test1";
    char *str2 = "Test2";
    char *str3 = "Test3";
    char *str4 = "Test4";

    list_add(&list, str1);
    list_add(&list, str2);
    list_add(&list, str3);
    list_add(&list, str4);
    cr_assert_eq(list_get(list_node_prev(list)), str4);
    list_remove(&list, str1);
    list_remove(&list, str2);
    list_remove(&list, str3);
    list_remove(&list, str4);
}

Test(list_node_prev, bad_parameter)
{
    cr_assert_eq(list_node_prev(0), 0);
}