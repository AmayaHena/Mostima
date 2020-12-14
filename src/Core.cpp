/*
** EPITECH PROJECT, 2020
** Mostima
** File description:
** Core
*/

#include "Core.hpp"
#include "FuncParser.hpp"

/* PUBLIC METHOD(S) */

bool Core::run(const std::vector<std::string> &v) noexcept
{
    if (!avCheck(v))
        return false;

    _f.setPath(v[0]);
    Parser::FuncParser fp;

    if (fp.getError())
        return false;

    for (Parser::Func f : fp.parse(_f.getContent())) {
        std::cout << "name: " << f.getName() << std::endl;
        std::cout << "ret: " << f.getRet() << std::endl;
        std::cout << "arg(s): " << std::endl;
        for (const std::string &s : f.geArg())
            std::cout << "- " << s << std::endl;
        std::cout << "---" << std::endl;
    }

    return true;
}

/* PRIVATE METHOD(S) */

bool Core::avCheck(const std::vector<std::string> &v)
{
    if (v.empty())
        return help("Files Warning");

    if (!_f.setPath(v[0]) || _f.getExtension() != "c")
        return help("C File '" + v[0] + "' doesn't exists");

    return true;
}

bool Core::help(const std::string &s)
{
    std::cout << s << '\n';
    return false;
}

