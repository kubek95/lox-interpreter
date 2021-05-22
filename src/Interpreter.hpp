#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>

namespace lox {

class Interpreter
{
    public:
        Interpreter();
        auto runInterpreter(std::string source) -> void;

    private:
        auto report(int line, std::string where, std::string message) -> void;
        auto error(int line, std::string message) -> void;

        bool errorOccured {false};
};

} // namepace lox

#endif // INTERPRETER_HPP
