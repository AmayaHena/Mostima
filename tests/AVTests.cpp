/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** test_crit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <cstdlib>

#include <Core.hpp>

#define ASSERT_INT(a, b) cr_assert_eq(a, b, "Expected %d, got %d\n", b, a)

Test(void, void)
{
    Core c;
    std::vector<std::string> v;

    ASSERT_INT(0, c.run(v));

    v.push_back("a.out");

    ASSERT_INT(0, c.run(v));

    v.clear();
    v.push_back("zeajielzaj/ezaoilheolizja/ezailpejzilma.c");

    ASSERT_INT(0, c.run(v));

    v.clear();
    v.push_back("zeajielzaj/ezaoilheolizja/ezailpejzilma/ezaeza");

    ASSERT_INT(0, c.run(v));
}
