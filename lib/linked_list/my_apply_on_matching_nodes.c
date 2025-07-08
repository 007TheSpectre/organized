/*
** EPITECH PROJECT, 2024
** my_apply_on_matching_nodes.c
** File description:
** my_apply_on_matching_nodes.c
*/

#include "linked_list.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
    void const *data_ref, int (*cmp)())
{
    linked_list_t *current = begin;

    for (; current; current = current->next)
        if (!cmp(current->data, data_ref))
            f(current->data);
    return 0;
}
