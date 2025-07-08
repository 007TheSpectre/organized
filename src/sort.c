/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort.c
*/

#include "organized.h"

/**
 * @brief Compare deux entiers pour le tri.
 *
 * @param int1 Premier entier
 * @param int2 Deuxième entier
 * @return -1 si int1 < int2, 1 si int1 > int2, 0 sinon
 */
static int my_intcmp(int int1, int int2)
{
    if (int1 < int2)
        return -1;
    if (int1 > int2)
        return 1;
    return 0;
}

/**
 * @brief Compare le type de deux data_t selon l'ordre de tri.
 *
 * @param data1 Premier élément
 * @param data2 Deuxième élément
 * @param sort_order Ordre de tri
 * @param i Indice de critère
 * @return Résultat de la comparaison
 */
static int type_case(data_t *data1, data_t *data2,
    type_sort_t *sort_order, int i)
{
    int cmp_val = my_intcmp(data1->type, data2->type);

    if (!cmp_val)
        return cmp_val;
    if (sort_order[i] == TYPE)
        return cmp_val;
    return - cmp_val;
}

/**
 * @brief Compare le nom de deux data_t selon l'ordre de tri.
 *
 * @param data1 Premier élément
 * @param data2 Deuxième élément
 * @param sort_order Ordre de tri
 * @param i Indice de critère
 * @return Résultat de la comparaison
 */
static int name_case(data_t *data1, data_t *data2,
    type_sort_t *sort_order, int i)
{
    int cmp_val = my_strcmp(data1->name, data2->name);

    if (!cmp_val)
        return cmp_val;
    if (sort_order[i] == NAME)
        return cmp_val;
    return - cmp_val;
}

/**
 * @brief Compare l'id de deux data_t selon l'ordre de tri.
 *
 * @param data1 Premier élément
 * @param data2 Deuxième élément
 * @param sort_order Ordre de tri
 * @param i Indice de critère
 * @return Résultat de la comparaison
 */
static int id_case(data_t *data1, data_t *data2,
    type_sort_t *sort_order, int i)
{
    int cmp_val = my_intcmp(data1->id, data2->id);

    if (!cmp_val)
        return cmp_val;
    if (sort_order[i] == ID)
        return cmp_val;
    return - cmp_val;
}

/**
 * @brief Applique le bon critère de comparaison selon l'ordre de tri.
 *
 * @param data1 Premier élément
 * @param data2 Deuxième élément
 * @param sort_order Ordre de tri
 * @param i Indice de critère
 * @return Résultat de la comparaison
 */
static int switch_case(data_t *data1, data_t *data2,
    type_sort_t *sort_order, int i)
{
    switch (sort_order[i]) {
        case TYPE:
        case TYPE_R:
            return type_case(data1, data2, sort_order, i);
        case NAME:
        case NAME_R:
            return name_case(data1, data2, sort_order, i);
        case ID:
        case ID_R:
            return id_case(data1, data2, sort_order, i);
        default:
            return 0;
    }
    return 0;
}

/**
 * @brief Compare deux éléments data_t selon l'ordre de tri.
 *
 * @param data1 Premier élément
 * @param data2 Deuxième élément
 * @param sort_order Ordre de tri
 * @return Résultat de la comparaison
 */
int element_cmp(data_t *data1, data_t *data2, type_sort_t *sort_order)
{
    int cmp_value;

    for (int i = 0; i < 3; i++) {
        cmp_value = switch_case(data1, data2, sort_order, i);
        if (cmp_value)
            return cmp_value;
    }
    return 0;
}

/**
 * @brief Met à jour le pointeur min si l'élément courant est plus petit.
 *
 * @param min Pointeur vers le minimum courant
 * @param tmp_2 Élément à comparer
 * @param sort_order Ordre de tri
 */
static void sort_f_aux
(linked_list_t **min, linked_list_t *tmp_2, type_sort_t *sort_order)
{
    if (element_cmp((*min)->data, tmp_2->data, sort_order) > 0) {
        *min = tmp_2;
    }
}

/**
 * @brief Trie la liste chaînée selon l'ordre de tri donné.
 *
 * @param begin Pointeur vers la tête de la liste
 * @param sort_order Ordre de tri
 */
void sort_f(linked_list_t **begin, type_sort_t *sort_order)
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
            sort_f_aux(&min, tmp_2, sort_order);
        }
        temp = min->data;
        min->data = tmp_1->data;
        tmp_1->data = temp;
    }
}

/**
 * @brief Fonction principale de tri, applique le tri sur la liste organisée.
 *
 * @param data Pointeur vers la structure organized_t
 * @param args Arguments de tri
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int sort(void *data, char **args)
{
    type_sort_t *sort_order = get_order(args);

    if (!sort_order || sort_order[0] == NOT) {
        free(sort_order);
        return 84;
    }
    sort_f(&((organized_t *)data)->linked_list, sort_order);
    free(sort_order);
    return 0;
}
