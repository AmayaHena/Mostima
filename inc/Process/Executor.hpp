/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Excutor
*/

#pragma once

    #include "File.hpp"
    #include "JSONParser.hpp"

namespace Process {

    class Executor {

        public:

            Executor();
            ~Executor() = default;

            bool run(std::vector<std::string> v, const std::string &s);

        private:

            std::string minimalCode(const std::string &s);

        private:

            Nyx::File _rsrc;
            Nyx::JSONParser _jp;

    };

}
