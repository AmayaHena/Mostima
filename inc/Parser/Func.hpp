/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Func
*/

    #include <string>
    #include <vector>

namespace Parser {

    class Func {

        public:

            Func(std::string &define);
            ~Func() = default;

            inline const std::string &getName() const { return _name; }
            inline const std::vector<std::string> &geArg() const { return _arg; }

            inline const size_t getArgNb() const { return _arg.size(); }

        private:

        std::string _name;
        std::vector<std::string> _arg;

    };

}
