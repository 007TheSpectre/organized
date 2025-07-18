/*
** EPITECH PROJECT, 2024
** my_find_node.c
** File description:
** my_find_node.c
*/

#include "linked_list.h"

linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t const *current = begin;

    for (; current; current = current->next)
        if (!cmp(current->data, data_ref))
            return (linked_list_t *)current;
    return NULL;
}
