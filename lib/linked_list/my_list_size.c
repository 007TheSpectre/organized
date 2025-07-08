/*
** EPITECH PROJECT, 2024
** my_list_size.c
** File description:
** my_list_size.c
*/

#include "linked_list.h"

int my_list_size(linked_list_t const *begin)
{
    int count = 0;

    for (; begin; begin = begin->next)
        count++;
    return count;
}
