/*
** EPITECH PROJECT, 2024
** manage_linked_list.c
** File description:
** manage_linked_list.c
*/

#include "linked_list.h"

linked_list_t *adding_begin(linked_list_t *node, void *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = data;
    new->next = node;
    return new;
}

linked_list_t *adding_end(linked_list_t *node, void *data)
{
    linked_list_t *current = node;

    if (!node) {
        node = malloc(sizeof(linked_list_t));
        node->data = data;
        node->next = NULL;
        return node;
    }
    for (; current->next; current = current->next);
    current->next = malloc(sizeof(linked_list_t));
    current = current->next;
    current->data = data;
    current->next = NULL;
    return node;
}
