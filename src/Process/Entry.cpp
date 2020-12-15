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

}
