/*
** EPITECH PROJECT, 2024
** my_str_islower.c
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return 0;
    return 1;
}
