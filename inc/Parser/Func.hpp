/*
** EPITECH PROJECT, 2020
** Mostima [WSL: Ubuntu-18.04]
** File description:
** Func
*/

    #include <string>
    #include <vector>

namespace Func {

    class Func {

        public:

            Func(std::string name, std::vector<std::string> arg, std::vector<std::string> content);
            ~Func() = default;

            inline const std::string &getName() const { return _name; }
            inline const std::vector<std::string> &geArg() const { return _arg; }
            inline const std::vector<std::string> &getContent() const { return _content; }

        private:

        std::string _name;
        std::vector<std::string> _arg;
        std::vector<std::string> _content;

    };

}
