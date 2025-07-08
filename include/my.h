/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

/**
 * @brief Puissance récursive.
 */
int my_compute_power_rec(int nb, int p);
/**
 * @brief Racine carrée entière.
 */
int my_compute_square_root(int nb);
/**
 * @brief Premier nombre premier supérieur ou égal à nb.
 */
int my_find_prime_sup(int nb);
/**
 * @brief Convertit une chaîne en entier.
 */
int my_getnbr(char const *str);
/**
 * @brief Affiche si n est négatif.
 */
int my_isneg(int n);
/**
 * @brief Teste si nb est premier.
 */
int my_is_prime(int nb);
/**
 * @brief Affiche un caractère.
 */
int my_putchar(char c);
/**
 * @brief Affiche un nombre entier.
 */
int my_put_nbr(int nb);
/**
 * @brief Affiche une chaîne de caractères.
 */
int my_putstr(char const *str);
/**
 * @brief Inverse une chaîne de caractères.
 */
char *my_revstr(char *str);
/**
 * @brief Trie un tableau d'entiers.
 */
void my_sort_int_array(int *array, int size);
/**
 * @brief Met la première lettre de chaque mot en majuscule.
 */
char *my_strcapitalize(char *str);
/**
 * @brief Concatène deux chaînes.
 */
char *my_strcat(char *dest, char const *src);
/**
 * @brief Compare deux chaînes.
 */
int my_strcmp(char const *s1, char const *s2);
/**
 * @brief Copie une chaîne.
 */
char *my_strcpy(char *dest, char const *src);
/**
 * @brief Teste si la chaîne ne contient que des lettres.
 */
int my_str_isalpha(char const *str);
/**
 * @brief Teste si la chaîne ne contient que des minuscules.
 */
int my_str_islower(char const *str);
/**
 * @brief Teste si la chaîne ne contient que des chiffres.
 */
int my_str_isnum(char const *str);
/**
 * @brief Teste si la chaîne ne contient que des caractères imprimables.
 */
int my_str_isprintable(char const *str);
/**
 * @brief Teste si la chaîne ne contient que des majuscules.
 */
int my_str_isupper(char const *str);
/**
 * @brief Retourne la longueur d'une chaîne.
 */
int my_strlen(char const *str);
/**
 * @brief Met une chaîne en minuscules.
 */
char *my_strlowcase(char *str);
/**
 * @brief Concatène n caractères de src à dest.
 */
char *my_strncat(char *dest, char const *src, int nb);
/**
 * @brief Compare n caractères de deux chaînes.
 */
int my_strncmp(char const *s1, char const *s2, int n);
/**
 * @brief Copie n caractères d'une chaîne.
 */
char *my_strncpy(char *dest, char const *src, int n);
/**
 * @brief Cherche une sous-chaîne.
 */
char *my_strstr(char *str, char const *to_find);
/**
 * @brief Met une chaîne en majuscules.
 */
char *my_strupcase(char *str);
/**
 * @brief Échange deux entiers.
 */
void my_swap(int *a, int *b);
/**
 * @brief Duplique une chaîne.
 */
char *my_strdup(char const *src);
/**
 * @brief Découpe une chaîne en mots.
 */
char **my_str_to_word_array(char const *str);
/**
 * @brief Affiche un message d'erreur sur stderr.
 */
int my_put_error(const char *err_msg);

#endif /* MY_H_ */
