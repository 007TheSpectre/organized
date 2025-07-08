/*
** EPITECH PROJECT, 2024
** organized
** File description:
** organized.h
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H

    #include <stdio.h>
    #include "my.h"
    #include "linked_list.h"
    #include "shell.h"

/**
 * @brief Types de tri disponibles.
 */
typedef enum {
    NOT,      /**< Aucun tri */
    TYPE,     /**< Tri par type */
    TYPE_R,   /**< Tri par type (inverse) */
    NAME,     /**< Tri par nom */
    NAME_R,   /**< Tri par nom (inverse) */
    ID,       /**< Tri par id */
    ID_R,     /**< Tri par id (inverse) */
} type_sort_t;

/**
 * @brief Types d'éléments possibles.
 */
typedef enum {
    ACTUATOR, /**< Actionneur */
    DEVICE,   /**< Appareil */
    PROCESSOR,/**< Processeur */
    SENSOR,   /**< Capteur */
    WIRE,     /**< Fil */
    NONE      /**< Aucun type */
} type_t;

/**
 * @brief Structure représentant un élément de la liste organisée.
 */
typedef struct data_s {
    type_t type; /**< Type de l'élément */
    char *name;  /**< Nom de l'élément */
    int id;      /**< Identifiant unique */
} data_t;

/**
 * @brief Structure principale contenant la liste et l'id courant.
 */
typedef struct organized_s {
    linked_list_t *linked_list; /**< Liste chaînée des éléments */
    int last_id;               /**< Dernier id attribué */
} organized_t;

/**
 * @brief Affiche le type d'un élément data_t.
 */
void print_type(data_t *data);
/**
 * @brief Génère l'ordre de tri à partir des arguments.
 */
type_sort_t *get_order(char **args);

#endif /* ORGANIZED_H */
