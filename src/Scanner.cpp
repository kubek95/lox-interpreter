#include "Scanner.hpp"

namespace lox {

Scanner::Scanner(std::string contentToScan) :
    _contentToScan{std::move(contentToScan)}
{}

auto Scanner::run() -> std::vector<Token> 
{
    return std::vector<Token>{};
}

} // namespace lox
