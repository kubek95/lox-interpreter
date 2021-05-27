#include "ErrorReporter.hpp"
#include <iostream>

namespace lox {

auto ErrorReporter::report(std::size_t line, std::string where, std::string message) -> void
{
    std::cerr << "[line " << line << "] Error " << where << " : " << message << '\n';
    _errorOccured = true;
}

auto ErrorReporter::error(std::size_t line, std::string message) -> void
{
    report(line, "", std::move(message));
}

auto ErrorReporter::errorOccured() const -> bool
{
    return _errorOccured;
}

} // namespace lox
