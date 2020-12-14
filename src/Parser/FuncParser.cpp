/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** FuncParser
*/

#include "FuncParser.hpp"

#include <iostream>
#include <sstream>

namespace Parser {

    /* PUBLIC METHOD(S)*/

    const std::vector<Func> FuncParser::parse(const std::vector<std::string> &content)
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
                if (!evaFunc(content[it]))
                    _err = true;
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

    bool FuncParser::evaFunc(const std::string &s)
    {
        std::cout << evaRet(s) << std::endl;
        std::cout << evaName(s) << std::endl;
        for (std::string s : evaArg(s))
            std::cout << s << std::endl;
        std::cout << "---" << std::endl;


        return true;
    }

}
