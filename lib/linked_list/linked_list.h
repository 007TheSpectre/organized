/*
** EPITECH PROJECT, 2024
** linked_list.h
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *adding_end(linked_list_t *node, void *data);
linked_list_t *adding_begin(linked_list_t *node, void *data);
linked_list_t *my_params_to_list(int ac, char *const *av);
void my_rev_list(linked_list_t **begin);
int my_list_size(linked_list_t const *begin);
int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
void my_sort_list(linked_list_t **begin, int (*cmp)());

#endif
