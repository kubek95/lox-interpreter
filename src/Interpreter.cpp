#include "Interpreter.hpp"
#include "Scanner.hpp"
#include "Token.hpp"

#include <iostream>
#include <sstream>

namespace lox {

auto Interpreter::runInterpreter(std::string source) -> void
{
    Scanner scanner{std::move(source)};
    auto tokens = scanner.run();
    for(const auto& token: tokens) {
        std::ostringstream os;
        os << token;
        std::cout << os.str() << '\n';
    } 
}

auto Interpreter::report(int line, std::string where, std::string message) -> void
{
    std::cerr << "[line " << line << "] Error " << where << " : " << message << '\n';
    errorOccured = true;
}

auto Interpreter::error(int line, std::string message) -> void
{
    report(line, "", std::move(message));
}

} // namespace lox
