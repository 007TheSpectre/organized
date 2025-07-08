/*
** EPITECH PROJECT, 2024
** my_add_in_sorted_list.c
** File description:
** my_add_in_sorted_list.c
*/

#include "linked_list.h"

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    *begin = adding_begin(*begin, data);
    my_sort_list(begin, cmp);
}
