/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Excutor
*/

#include <stdlib.h>

#include "Executor.hpp"

namespace Process {

    /* CTOR & DTOR */

    Executor::Executor()
    {
        _rsrc.setPath("rsrc/c.json");
    }

    /* PUBLIC METHOD(S) */

    bool Executor::run(std::vector<std::string> v, const std::string &s, const bool vd)
    {
        Nyx::File tmp;

        tmp.setPath("MostimaFile.cpp");

        v.push_back(_jp.parseRV(_rsrc, "include"));

        if (vd)
            v.push_back(minimalCodeVoid(s));
        else
            v.push_back(minimalCode(s));

        tmp.create(v);

        system("g++ MostimaFile.cpp -w && ./a.out");
        system("rm MostimaFile.cpp a.out");
    }

    /* PRIVATE METHOD(S) */

    std::string Executor::minimalCode(const std::string &s)
    {
        return (_jp.parseRV(_rsrc, "begin") + s + _jp.parseRV(_rsrc, "end"));
    }

    std::string Executor::minimalCodeVoid(const std::string &s)
    {
        return (_jp.parseRV(_rsrc, "begin_void") + s + _jp.parseRV(_rsrc, "end_void"));
    }

}
