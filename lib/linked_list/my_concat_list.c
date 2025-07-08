/*
** EPITECH PROJECT, 2024
** my_concat_list.c
** File description:
** my_concat_list.c
*/

#include "linked_list.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *current = *begin1;

    if (!current) {
        *begin1 = begin2;
        return;
    }
    for (; current->next; current = current->next);
    current->next = begin2;
}
