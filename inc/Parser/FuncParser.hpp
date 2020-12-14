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

            std::vector<std::string> split(const std::string &s, char delimiter) const;

            std::string getType(const std::string &arg);

            std::string evaName(const std::string &s);
            std::vector<std::string> evaArg(const std::string &s);
            std::string evaRet(const std::string &s);

            bool evaFunc(const std::string &s);

        private:

            bool _err = false;

            std::vector<Func> _func;

    };

}
