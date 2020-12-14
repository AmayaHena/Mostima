/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** FuncParser
*/

#include "FuncParser.hpp"

#include <iostream>

namespace Parser {

    /* PUBLIC METHOD(S)*/

    const std::vector<Func> FuncParser::parse(const std::vector<std::string> &content)
    {
        int count = 0;

        for (auto it = 0; it <= content.size(); it++) {

            if (content[it].find("{") != std::string::npos)
                count++;
            if (content[it].find("}") != std::string::npos)
                count--;

            if (count == 0
            && content[it].find("(") != std::string::npos
            && content[it].find(")") != std::string::npos)
                std::cout << content[it] << std::endl;;

        }

        if (count != 0) {
            _func.clear();
            return _func;
        }

        return _func;
    }

    /* PRIVATE METHOD(S)*/

}
