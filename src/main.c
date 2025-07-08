/*
** EPITECH PROJECT, 2024
** organized
** File description:
** main.c
*/

#include "organized.h"

/**
 * @brief Alloue et initialise une structure organized_t.
 *
 * @return Pointeur vers la structure organisée nouvellement créée
 */
static organized_t *set_organized(void)
{
    organized_t *organized = (organized_t *)malloc(sizeof(organized_t));

    organized->linked_list = NULL;
    organized->last_id = 0;
    return organized;
}

/**
 * @brief Libère toute la mémoire de la liste chaînée.
 *
 * @param linked_list Pointeur vers la tête de la liste chaînée
 */
void free_linked_list(linked_list_t *linked_list)
{
    if (!linked_list)
        return;
    if (linked_list->next)
        free_linked_list(linked_list->next);
    free(((data_t *)linked_list->data)->name);
    free(linked_list->data);
    free(linked_list);
}

/**
 * @brief Point d'entrée principal du programme.
 *
 * @return Code de retour du shell d'atelier
 */
int main(void)
{
    organized_t *organized = set_organized();
    void *data = organized;
    int return_value = workshop_shell(data);

    free_linked_list(((organized_t *)data)->linked_list);
    free(data);
    return return_value;
}
