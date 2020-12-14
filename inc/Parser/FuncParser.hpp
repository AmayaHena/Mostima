/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** FuncParser
*/

#pragma once

    #include <utility>

    #include "File.hpp"
    #include "JSONParser.hpp"
    #include "Func.hpp"

namespace Parser {

    class FuncParser {

        public:

            FuncParser();
            ~FuncParser() = default;

            std::vector<Func> parse(const std::vector<std::string> &content);

            inline bool getError() const { return _err; }

        private:

            std::vector<std::string> split(const std::string &s, char delimiter) const;

            std::string getType(const std::string &arg);

            std::string evaName(const std::string &s);
            std::vector<std::string> evaArg(const std::string &s);
            std::string evaRet(const std::string &s);

            bool validArg(const std::vector<std::string> &v) const;
            bool validRet(const std::string &r) const;

            void evaFunc(const std::string &s);

        private:

            bool _err = false;

            std::vector<Func> _func;

            std::vector<std::string> _types;

    };

}
