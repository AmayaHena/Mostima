/*
** EPITECH PROJECT, 2020
** Mostima
** File description:
** Core
*/

#pragma once

    #include <iostream>
    #include <vector>
    #include <string>

class Core final {

    public:

        Core() = default;
        ~Core() = default;

        bool run(const std::vector<std::string> &v);

    private:

        void help(const std::string &s);

};
