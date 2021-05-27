#include "Interpreter.hpp"
#include "Scanner.hpp"
#include "Token.hpp"

#include <iostream>
#include <sstream>

namespace lox {

auto Interpreter::runInterpreter(std::string source) -> void
{
    Scanner scanner{std::move(source), _errorReporter};
    auto tokens = scanner.run();
    for(const auto& token: tokens) {
        std::ostringstream os;
        os << token;
        std::cout << os.str() << '\n';
    } 
}

} // namespace lox
