#pragma once

#include <string>

namespace lox {

class ErrorReporter
{
    public:
        auto error(std::size_t line, std::string message) -> void;
        auto report(std::size_t line, std::string where, std::string message) -> void;
        auto errorOccured() const -> bool;

    private:
        bool _errorOccured{false};
};

} // namespace lox
