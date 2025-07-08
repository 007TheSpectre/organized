/*
** EPITECH PROJECT, 2024
** my_delete_nodes.c
** File description:
** my_delete_nodes.c
*/

#include "linked_list.h"

int if_cmp_is_zero(linked_list_t **begin,
    linked_list_t **current, linked_list_t *prev)
{
    linked_list_t *temp = NULL;

    temp = *current;
    if (!prev)
        *begin = (*current)->next;
    if (prev)
        prev->next = (*current)->next;
    *current = (*current)->next;
    free(temp);
    return 0;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;

    while (current) {
        if (!cmp(current->data, data_ref)) {
            if_cmp_is_zero(begin, &current, prev);
            continue;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}
