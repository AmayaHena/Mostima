/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Func
*/

#include "Func.hpp"

namespace Parser {

    /* CTOR & DTOR */
    Func::Func(std::string name, std::vector<std::string> arg, std::string ret) :
    _name(name),
    _arg(arg),
    _ret(ret)
    {}

}
