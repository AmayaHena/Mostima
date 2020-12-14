/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** FuncParser
*/

#pragma once

    #include <utility>

    #include "Func.hpp"

namespace Parser {

    class FuncParser {

        public:

            FuncParser() = default;
            ~FuncParser() = default;

            const std::vector<Func> parse(const std::vector<std::string> &content);

            inline bool getError() const { return _err; }

        private:

            bool _err = false;

            std::vector<Func> _func;

    };

}
