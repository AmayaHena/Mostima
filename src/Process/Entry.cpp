/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Entry
*/

#include "Entry.hpp"

namespace Process {

    /* CTOR & DTOR */

    Entry::Entry(Nyx::File f) :
    _f(f)
    {}

    /* PUBLIC METHOD(S) */

    bool Entry::run()
    {
        Parser::FuncParser fp;

        _func = fp.parse(_f.getContent());
        if (fp.getError() || _func.empty())
            return false;

        printParsed(_f.getName());

        while (1) {
            std::string in = prompt();
            if (in == "exit")
                return true;
            parseInput(in);
        }

        return true;
    }

    /* PRIVATE METHOD(S) */

    void Entry::printParsed(const std::string &f) const
    {
        std::cout << "Avaible function in " << f << '\n';

        for (const Parser::Func &f : _func) {
            std::cout << "\033[1;32m" << f.getRet() << "\033[0m ";
            std::cout << f.getName() << "(";

            for (const std::string &s : f.geArg())
                std::cout << " \033[1;32m" << s << "\033[0m ";

            std::cout << ")\n";
        }
    }

    std::string Entry::prompt() const
    {
        std::string s;

        std::cout << "> ";
        std::getline(std::cin, s);
        std::cin.clear();
        return s;
    }

    std::string Entry::getFunction(const std::string &s) const
    {
        if (s.find('(') != std::string::npos)
            return s.substr(0, s.find('('));
        return "";
    }

    bool Entry::validFunc(const std::string &s)
    {
        for (Parser::Func f : _func)
            if (f.getName() == s)
                return true;
        return false;
    }

    bool Entry::parseInput(const std::string &s)
    {
        if (getFunction(s) == "")
            return error();

        if (validFunc(getFunction(s)))
            std::cout << "Success" << std::endl;
        else
            return error();
        return true;
    }

    bool Entry::error()
    {
        std::cerr << "Error on input" << std::endl;
        return false;
    }

}
