/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

/**
 * @brief Ajoute un élément à la liste organisée.
 * @param data Pointeur vers la structure organized_t
 * @param args Tableau d'arguments (type, nom, ...)
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int add(void *data, char **args);
/**
 * @brief Supprime des éléments de la liste organisée.
 * @param data Pointeur vers la structure organized_t
 * @param args Tableau d'arguments (ids à supprimer)
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int del(void *data, char **args);
/**
 * @brief Trie la liste organisée.
 * @param data Pointeur vers la structure organized_t
 * @param args Arguments de tri
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int sort(void *data, char **args);
/**
 * @brief Affiche les éléments de la liste organisée.
 * @param data Pointeur vers la structure organized_t
 * @param args Inutilisé
 * @return 0 Toujours 0
 */
int disp(void *data, char **args);

/**
 * @brief Lance le shell interactif de gestion d'éléments.
 * @param data Pointeur vers la structure organized_t
 * @return Code de retour du shell
 */
int workshop_shell(void *data);

#endif /* SHELL_H */
