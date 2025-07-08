/*
** EPITECH PROJECT, 2024
** my_params_to_list.c
** File description:
** my_params_to_list.c
*/

#include "linked_list.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *node = NULL;

    for (int i = 0; i < ac; i++) {
        node = adding_begin(node, av[i]);
    }
    return node;
}
