/*
** EPITECH PROJECT, 2024
** my_apply_on_nodes.c
** File description:
** my_apply_on_nodes.c
*/

#include "linked_list.h"

void my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *current = begin;

    for (; current; current = current->next)
        f(current->data);
}
