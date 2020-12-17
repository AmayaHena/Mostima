/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** test_crit
*/

#include <FuncParser.hpp>

int main()
{
    Parser::FuncParser fp;
    Nyx::File f("../../CExample/simple.c");

    std::vector<Parser::Func> v = fp.parse(f.getContent());

    if (v.empty())
        return 84;

    if (v[0].getName() != "helloWorld")
        return 84;
    if (v[0].getArgNb() != 0)
        return 84;

    if (v[1].getName() != "itearate")
        return 84;
    if (v[1].getArgNb() != 1)
        return 84;

    if (v[2].getName() != "lel")
        return 84;
    if (v[2].getArgNb() != 3)
        return 84;

    if (v[3].getName() != "iterateHelloWorld")
        return 84;
    if (v[3].getArgNb() != 1)
        return 84;

    v.clear();

    f.setPath("../CExample/error_1.c");

    if (!v.empty())
        return 84;

    return 0;
}
