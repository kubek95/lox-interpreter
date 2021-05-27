#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Token.hpp"
#include "ErrorReporter.hpp"

#include <string>
#include <vector>
#include <memory>

namespace lox {
    
    class Scanner
    {
        public:
            Scanner(std::string contentToScan,
                    std::shared_ptr<ErrorReporter> errorReporter);
            auto run() -> std::vector<Token>;

        private:
            auto scanTokens() -> std::vector<Token>;
            auto isAtEnd() const -> bool;
            auto scanToken() -> void;
            auto advance() -> char;
            auto addToken(TokenType tokenType) -> void;
            auto addToken(TokenType tokenType, std::optional<LiteralType> literal) -> void;
            auto matchNext(char nextChar) -> bool;
            
            std::string _contentToScan;
            std::shared_ptr<ErrorReporter> _errorReporter;
            std::vector<Token> _tokens{};
            std::size_t _start{0};
            std::size_t _current{0};
            std::size_t _line{1};
    };
} // namespace lox

#endif // SCANNER_HPP
