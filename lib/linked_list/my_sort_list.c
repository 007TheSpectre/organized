/*
** EPITECH PROJECT, 2024
** my_sort_list.c
** File description:
** my_sort_list.c
*/

#include "linked_list.h"

static void aux_my_sort_list(linked_list_t **min, linked_list_t *tmp_2,
    int (*cmp)())
{
    if (cmp((*min)->data, tmp_2->data) > 0) {
        (*min) = tmp_2;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *tmp_1;
    linked_list_t *tmp_2;
    linked_list_t *min;
    void *temp;

    if (!*begin)
        return;
    for (tmp_1 = *begin; tmp_1->next; tmp_1 = tmp_1->next) {
        min = tmp_1;
        for (tmp_2 = tmp_1->next; tmp_2; tmp_2 = tmp_2->next) {
            aux_my_sort_list(&min, tmp_2, cmp);
        }
        temp = min->data;
        min->data = tmp_1->data;
        tmp_1->data = temp;
    }
}
