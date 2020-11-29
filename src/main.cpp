/*
** EPITECH PROJECT, 2020
** Mostima
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    (void)ac;

    Core c;
    std::vector<std::string> v;

    for (size_t it = 1; av[it]; it++)
        v.push_back(av[it]);

    if (!c.run(v))
        return 84;
    return 0;
}
