/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** test_crit
*/

#include <Core.hpp>

int main()
{
    Core c;
    std::vector<std::string> v;

    v.push_back("a.out");
    if (c.run(v))
        return 84;

    v.clear();
    v.push_back("zeajielzaj/ezaoilheolizja/ezailpejzilma.c");
    if (c.run(v))
        return 84;

    v.clear();
    v.push_back("zeajielzaj/ezaoilheolizja/ezailpejzilma/ezaeza");
    if (c.run(v))
        return 84;

    return 0;
}
