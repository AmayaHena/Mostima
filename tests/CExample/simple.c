/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** simple
*/

#include <stdio.h>

void helloWorld()
{
    printf("Hello world");
}

int iterate(int i)
{
    return i++;
}

void lel(size_t a, int b, float c)
{
    return;
}

int iterateHelloWorld(int nb)
{
    int i = 0;

    while (nb <= i) {
        printf("Hello world\n");
        i++;
    }

    return nb;
}
