#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Token.hpp"
#include "ErrorReporter.hpp"

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

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
            auto peek() const -> char;
            auto scanString() -> void;
            auto scanNumber() -> void;
            auto peekNext() const -> char;
            auto counsumeNumberInSource() -> void;
            auto identifier() -> void;
            auto determineIdentifierType(const std::string& identifier) const -> TokenType;

            std::string _contentToScan;
            std::shared_ptr<ErrorReporter> _errorReporter;
            std::vector<Token> _tokens{};
            std::size_t _start{0};
            std::size_t _current{0};
            std::size_t _line{1};
            static const std::unordered_map<std::string, TokenType> _keywords;
    };
} // namespace lox

#endif // SCANNER_HPP
