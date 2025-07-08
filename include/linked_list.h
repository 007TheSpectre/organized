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

/**
 * @brief Structure d'un maillon de liste chaînée générique.
 */
typedef struct linked_list {
    void *data;              /**< Pointeur vers les données de l'élément */
    struct linked_list *next;/**< Pointeur vers l'élément suivant */
} linked_list_t;

/**
 * @brief Ajoute un élément à la fin de la liste.
 * @param node Tête de liste
 * @param data Donnée à ajouter
 * @return Nouvelle tête de liste
 */
linked_list_t *adding_end(linked_list_t *node, void *data);
/**
 * @brief Ajoute un élément au début de la liste.
 * @param node Tête de liste
 * @param data Donnée à ajouter
 * @return Nouvelle tête de liste
 */
linked_list_t *adding_begin(linked_list_t *node, void *data);
/**
 * @brief Transforme les paramètres en liste chaînée.
 */
linked_list_t *my_params_to_list(int ac, char *const *av);
/**
 * @brief Inverse la liste chaînée.
 */
void my_rev_list(linked_list_t **begin);
/**
 * @brief Retourne la taille de la liste chaînée.
 */
int my_list_size(linked_list_t const *begin);
/**
 * @brief Supprime les noeuds correspondant à data_ref.
 */
int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
/**
 * @brief Concatène deux listes chaînées.
 */
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
/**
 * @brief Trie la liste chaînée selon la fonction de comparaison.
 */
void my_sort_list(linked_list_t **begin, int (*cmp)());

#endif
