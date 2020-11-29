/*
** EPITECH PROJECT, 2020
** Mostima
** File description:
** Core
*/

#include "Core.hpp"

/* PUBLIC METHOD(S) */

bool Core::run(const std::vector<std::string> &v)
{
    if (v.empty()) {
        help("no files given");
        return false;
    }
    return true;
}

/* PRIVATE METHOD(S) */

void Core::help(const std::string &s)
{
    std::cout << s << '\n';
}

