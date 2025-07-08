/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add.c
*/

#include "organized.h"

/**
 * @brief Récupère le type d'un élément à partir d'une chaîne.
 *
 * @param arg Chaîne représentant le type ("ACTUATOR", "DEVICE", etc.)
 * @return type_t Type correspondant, ou 5 si non trouvé.
 */
static type_t get_type(char *arg)
{
    char *comp[] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};

    for (int i = 0; i < 5; i++)
        if (!my_strcmp(arg, comp[i]))
            return i;
    return 5;
}

/**
 * @brief Affiche un message indiquant qu'un élément a été ajouté.
 *
 * @param data Pointeur vers la structure data_t de l'élément ajouté
 * @return 0 Toujours 0
 */
static int display_element_added(data_t *data)
{
    print_type(data);
    my_putstr(" n°");
    my_put_nbr(((data_t *)data)->id);
    my_putstr(" - \"");
    my_putstr(((data_t *)data)->name);
    my_putstr("\" added.\n");
    return 0;
}

/**
 * @brief Ajoute des éléments à la liste organisée à partir d'un tableau d'arguments.
 *
 * @param organized Pointeur vers la structure organized_t
 * @param args Tableau de chaînes (type, nom, ...)
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
static int adding(organized_t *organized, char **args)
{
    data_t *data = NULL;

    for (; *args; args += 2) {
        data = (data_t *)malloc(sizeof(data_t));
        if (!data)
            return 84;
        data->type = get_type(args[0]);
        if (data->type == NONE)
            return 84;
        data->name = my_strdup(args[1]);
        if (!data->name)
            return 84;
        data->id = organized->last_id;
        organized->last_id++;
        organized->linked_list = adding_begin(organized->linked_list, data);
        display_element_added(organized->linked_list->data);
    }
    return 0;
}

/**
 * @brief Fonction principale d'ajout, vérifie les arguments et appelle l'ajout.
 *
 * @param data Pointeur vers la structure organized_t
 * @param args Tableau de chaînes (type, nom, ...)
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int add(void *data, char **args)
{
    int len = 0;

    for (; args[len]; len++);
    if (len < 2 || len % 2 == 1) {
        return 84;
    }
    for (int i = 0; args[i]; i += 2)
        if (my_strcmp(args[i], "ACTUATOR") && my_strcmp(args[i], "DEVICE") &&
            my_strcmp(args[i], "PROCESSOR") && my_strcmp(args[i], "SENSOR") &&
            my_strcmp(args[i], "WIRE"))
            return 84;
    if (adding(data, args))
        return 84;
    return 0;
}
