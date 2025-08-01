/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        nb++;
        nb = nb * -1;
        my_put_nbr(nb / 10);
        my_putchar('8');
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
        return 0;
    }
    my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
