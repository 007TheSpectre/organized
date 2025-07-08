/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del.c
*/

#include "organized.h"

/**
 * @brief Compare deux éléments data_t par leur id et libère le premier en cas
 *        d'égalité.
 *
 * @param data1 Premier élément à comparer et à libérer
 * @param data2 Deuxième élément à comparer
 * @return -1 si id1 < id2, 1 si id1 > id2, 0 si égalité (et libération)
 */
int my_delete_cmp(data_t *data1, data_t *data2) {
  if (data1->id < data2->id)
    return -1;
  if (data1->id > data2->id)
    return 1;
  print_type(data1);
  my_putstr(" n°");
  my_put_nbr(data1->id);
  my_putstr(" - \"");
  my_putstr(data1->name);
  my_putstr("\" deleted.\n");
  free(data1->name);
  free(data1);
  return 0;
}

/**
 * @brief Supprime des éléments de la liste organisée selon les ids passés en
 *        arguments.
 *
 * @param data Pointeur vers la structure organized_t
 * @param args Tableau de chaînes contenant les ids à supprimer
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int del(void *data, char **args) {
  organized_t *organized = (organized_t *)data;
  data_t data_ref;

  for (int i = 0; args[i]; i++)
    if (!my_str_isnum(args[i]))
      return 84;
  for (; *args; args++) {
    data_ref.id = my_getnbr(*args);
    my_delete_nodes(&organized->linked_list, &data_ref, my_delete_cmp);
  }
  return 0;
}
