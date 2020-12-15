/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Entry
*/

#pragma once

    #include "File.hpp"
    #include "FuncParser.hpp"

namespace Process {

    class Entry {

        public:

            Entry(Nyx::File f);
            ~Entry() = default;

            bool run();

        private:

            void printParsed(const std::string &f) const;

        private:

            Nyx::File _f;
            std::vector<Parser::Func> _func;

    };

}
