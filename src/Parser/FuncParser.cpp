/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** FuncParser
*/

#include <iostream>
#include <sstream>

#include "FuncParser.hpp"

namespace Parser {

    /* CTOR & DTOR */
    FuncParser::FuncParser()
    {
        Nyx::File rsrc("rsrc/types.json");
        Nyx::JSONParser jp;

        _types = split(jp.parseRV(rsrc, "types"), ' ');
    }

    /* PUBLIC METHOD(S)*/

    std::vector<Func> FuncParser::parse(const std::vector<std::string> &content)
    {
        int count = 0;

        for (auto it = 0; it <= content.size(); it++) {
            if (content[it].find("{") != std::string::npos)
                count++;
            if (content[it].find("}") != std::string::npos)
                count--;

            if (count == 0
            && content[it].find("(") != std::string::npos
            && content[it].find(")") != std::string::npos)
                evaFunc(content[it]);
        }

        if (count != 0 || _err == true) {
            _func.clear();
            return _func;
        }
        return _func;
    }

    /* PRIVATE METHOD(S)*/

    std::vector<std::string> FuncParser::split(const std::string &s, char delimiter) const
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);

        while (std::getline(tokenStream, token, delimiter))
            tokens.push_back(token);
        return tokens;
    }

    std::string FuncParser::getType(const std::string &arg)
    {
        std::string r;
        int it = 0;

        if (arg[0] == ' ')
            it++;
        while (it <= arg.size()) {
            if (arg[it] == ' ')
                return r;
            r += arg[it++];
        }

        _err = true;
        return r;
    }

    std::string FuncParser::evaName(const std::string &s)
    {
        std::string r;
        int it = 0;

        while (s[it++] != ' ');
        while (s[it] != '(')
            r += s[it++];
        return r;
    }

    std::vector<std::string> FuncParser::evaArg(const std::string &s)
    {
        std::vector<std::string> v;
        std::string tmp;
        int it = 0;

        while (s[it++] != '(');
        while (s[it] != ')')
            tmp += s[it++];

        if (tmp.empty())
            return v;

        if (tmp.find(",") != std::string::npos) {
            for (const std::string &s : split(tmp, ','))
                v.push_back(getType(s));
        } else {
            v.push_back(getType(tmp));
        }

        return v;
    }

    std::string FuncParser::evaRet(const std::string &s)
    {
        std::string r;

        for (char c : s) {
            if (c == ' ')
                return r;
            r += c;
        }
        _err = true;
        return "";
    }

    bool FuncParser::validArg(const std::vector<std::string> &v) const
    {
        for (const std::string &arg : v)
            if (!validRet(arg))
                return false;
        return true;
    }

    bool FuncParser::validRet(const std::string &r) const
    {
        for (const std::string &s : _types)
            if (r == s)
                return true;
        return false;
    }

    void FuncParser::evaFunc(const std::string &s)
    {
        if (!validArg(evaArg(s)) || !validRet(evaRet(s)))
            return;
        _func.push_back({evaName(s), evaArg(s), evaRet(s)});
    }

}
