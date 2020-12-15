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
    helloWorld();
    return i + 1;
}

void lel(size_t a, int b, float c)
{
    return;
}

long err(long a)
{
    return 5;
}

void err2(long a)
{
    return;
}

long err3()
{
    return 5;
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
