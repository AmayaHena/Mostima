/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Entry
*/

#pragma once

    #include "File.hpp"
    #include "FuncParser.hpp"
    #include "Executor.hpp"

namespace Process {

    class Entry {

        public:

            Entry(Nyx::File f);
            ~Entry() = default;

            bool run();

        private:

            void printParsed(const std::string &f) const;

            std::string prompt() const;

            std::string getFunction(const std::string &s) const;
            bool validFunc(const std::string &s);
            bool parseInput(const std::string &s);

            bool error();

        private:

            Nyx::File _f;
            std::vector<Parser::Func> _func;
            Executor _exec;

    };

}
