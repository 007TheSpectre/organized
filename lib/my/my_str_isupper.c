/*
** EPITECH PROJECT, 2024
** my_str_isupper.c
** File description:
** my_str_isupper.c
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return 0;
    return 1;
}
