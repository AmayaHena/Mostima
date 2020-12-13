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

    #include "File.hpp"

class Core final {

    public:

        Core() = default;
        ~Core() = default;

        bool run(const std::vector<std::string> &v) noexcept;

    private:

        bool avCheck(const std::vector<std::string> &v);

        bool help(const std::string &s);

    private:

        Nyx::File _f;

};
