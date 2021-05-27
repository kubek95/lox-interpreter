#pragma once

#include "ErrorReporter.hpp"

#include <memory>
#include <string>

namespace lox {

class Interpreter
{
    public:
        auto runInterpreter(std::string source) -> void;

    private:
        std::shared_ptr<ErrorReporter> _errorReporter{};
};

} // namepace lox
