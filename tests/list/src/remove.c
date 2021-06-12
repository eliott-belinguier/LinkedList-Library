/*
** EPITECH PROJECT, 2018
** Unit Test
** File description:
** Test remove to list function.
*/

#include <criterion/criterion.h>
#include "list.h"

Test(list_remove, normal_test)
{
    list_t list = 0;
    list_t current;
    char *str1 = "Test1";
    char *str2 = "Test2";
    char *str3 = "Test3";
    char *str4 = "Test4";
    char *str5 = "Test5";

    cr_assert_eq(list_add(&list, str1), 0);
    cr_assert_eq(list_add(&list, str2), 0);
    cr_assert_eq(list_add(&list, str3), 0);
    cr_assert_eq(list_add(&list, str4), 0);
    cr_assert_eq(list_remove(&list, str3), 0);
    cr_assert_eq(list_remove(&list, str1), 0);
    cr_assert_eq(list_remove(&list, str5), -1);
    current = list;
    cr_assert_eq(list_next(&current), str2);
    cr_assert_eq(list_next(&current), str4);
    cr_assert_eq(list_next(&current), str2);
    cr_assert_eq(list_remove(&list, str2), 0);
    cr_assert_eq(list_remove(&list, str4), 0);
}

Test(list_remove, bad_parameter)
{
    char *str1 = "Test1";

    cr_assert_eq(list_remove(0, str1), -1);
}

Test(list_remove, bad_parameter_2)
{
    list_t list = 0;
    char *str1 = "Test1";

    cr_assert_eq(list_remove(&list, str1), -1);
}

Test(list_remove, bad_parameter_3)
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
    cr_assert_eq(list_remove(&list, 0), -1);
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