/*
** EPITECH PROJECT, 2024
** organized
** File description:
** disp.c
*/

#include "organized.h"

/**
 * @brief Affiche le type d'un élément data_t sous forme de chaîne.
 *
 * @param data Pointeur vers la structure data_t à afficher
 */
void print_type(data_t *data)
{
    switch (data->type) {
    case ACTUATOR:
        my_putstr("ACTUATOR");
        break;
    case DEVICE:
        my_putstr("DEVICE");
        break;
    case PROCESSOR:
        my_putstr("PROCESSOR");
        break;
    case SENSOR:
        my_putstr("SENSOR");
        break;
    case WIRE:
        my_putstr("WIRE");
        break;
    default:
        break;
    }
}

/**
 * @brief Affiche tous les éléments de la liste organisée.
 *
 * @param data Pointeur vers la structure organized_t
 * @param args Arguments inutilisés
 * @return 0 Toujours 0
 */
int disp(void *data, char **args)
{
    organized_t *organized = (organized_t *)data;

    args = args;
    for (linked_list_t *current = organized->linked_list;
    current; current = current->next) {
        print_type(current->data);
        my_putstr(" n°");
        my_put_nbr(((data_t *)current->data)->id);
        my_putstr(" - \"");
        my_putstr(((data_t *)current->data)->name);
        my_putstr("\"\n");
    }
    return 0;
}
