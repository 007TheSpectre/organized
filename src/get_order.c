/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get_order.c
*/

#include "organized.h"

/**
 * @brief Gère les arguments NAME et ID pour l'ordre de tri.
 *
 * @param args Tableau d'arguments
 * @param sort_order Tableau de type_sort_t à remplir
 * @param order_place Position courante dans sort_order
 * @param i Indice courant dans args
 * @return 0 si reconnu, 1 sinon
 */
static int get_order_aux_aux(char **args, type_sort_t *sort_order,
                             int *order_place, int *i) {
  if (!my_strcmp(args[*i], "NAME")) {
    if (args[*i + 1] && !my_strcmp(args[*i + 1], "-r")) {
      sort_order[*order_place] = NAME_R;
      (*i)++;
    } else
      sort_order[*order_place] = NAME;
    (*order_place)++;
    return 0;
  }
  if (!my_strcmp(args[*i], "ID")) {
    if (args[*i + 1] && !my_strcmp(args[*i + 1], "-r")) {
      sort_order[*order_place] = ID_R;
      (*i)++;
    } else
      sort_order[*order_place] = ID;
    (*order_place)++;
    return 0;
  }
  return 1;
}

/**
 * @brief Gère l'argument TYPE pour l'ordre de tri, sinon délègue à
 *        get_order_aux_aux.
 *
 * @param args Tableau d'arguments
 * @param sort_order Tableau de type_sort_t à remplir
 * @param order_place Position courante dans sort_order
 * @param i Indice courant dans args
 * @return 0 si reconnu, 1 sinon
 */
static int get_order_aux(char **args, type_sort_t *sort_order, int *order_place,
                         int *i) {
  if (!my_strcmp(args[*i], "TYPE")) {
    if (args[*i + 1] && !my_strcmp(args[*i + 1], "-r")) {
      sort_order[*order_place] = TYPE_R;
      (*i)++;
    } else
      sort_order[*order_place] = TYPE;
    (*order_place)++;
    return 0;
  }
  return get_order_aux_aux(args, sort_order, order_place, i);
}

/**
 * @brief Génère l'ordre de tri à partir des arguments.
 *
 * @param args Tableau d'arguments (ex: TYPE, NAME, ID, -r)
 * @return Tableau de type_sort_t représentant l'ordre de tri, ou NULL en cas
 *         d'erreur
 */
type_sort_t *get_order(char **args) {
  type_sort_t *sort_order = (type_sort_t *)malloc(sizeof(type_sort_t) * 3);
  int order_place = 0;

  if (!sort_order)
    return NULL;
  sort_order[0] = NOT;
  sort_order[1] = NOT;
  sort_order[2] = NOT;
  for (int i = 0; args[i]; i++) {
    if (get_order_aux(args, sort_order, &order_place, &i))
      return NULL;
  }
  return sort_order;
}
