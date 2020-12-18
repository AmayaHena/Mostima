/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** sample
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int my_strlen(char *str)
{
    int it = 0;

    while (str[it] != '\0')
        it++;

    return (it);
}

bool isGoodPwd(char *pwd)
{
    if (my_strlen(pwd) < 5)
        return false;
    return true;
}
