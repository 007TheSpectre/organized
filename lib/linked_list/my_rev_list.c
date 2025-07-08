/*
** EPITECH PROJECT, 2024
** my_rev_list.c
** File description:
** my_rev_list.c
*/

#include "linked_list.h"

linked_list_t *rev_linked_list(linked_list_t **dest, linked_list_t *src)
{
    if (src->next) {
        *dest = rev_linked_list(dest, src->next);
    }
    *dest = adding_end(*dest, src->data);
    return *dest;
}

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *new = NULL;

    new = rev_linked_list(&new, *begin);
    free(*begin);
    *begin = new;
}
