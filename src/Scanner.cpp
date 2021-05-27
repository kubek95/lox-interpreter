#include "Scanner.hpp"

#include <optional>

namespace lox {

Scanner::Scanner(std::string contentToScan, std::shared_ptr<ErrorReporter> errorReporter) :
    _contentToScan{std::move(contentToScan)},
    _errorReporter{std::move(errorReporter)}
{}

auto Scanner::run() -> std::vector<Token> 
{
    return std::vector<Token>{};
}

auto Scanner::isAtEnd() const -> bool
{
    return _current >= _contentToScan.size();
}

auto Scanner::advance() -> char
{
    return _contentToScan.at(_current);
}

auto Scanner::addToken(TokenType tokenType) -> void
{
    addToken(tokenType, std::nullopt);
}

auto Scanner::addToken(TokenType tokenType, std::optional<LiteralType> literal) -> void
{
    auto lexem = _contentToScan.substr(_start, _current - _start);
    _tokens.emplace_back(tokenType, lexem, literal, _line);
}

auto Scanner::matchNext(char expected) -> bool
{
    if (isAtEnd()) {
        return false;
    }
    if (_contentToScan.at(_current) != expected) {
        return false;
    }
    ++_current;
    return true;
}

auto Scanner::scanToken() -> void
{
    char c = advance();
    switch(c) {
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PARTEN); break;
        case '{': addToken(TokenType::RIGHT_BRACE); break;
        case '}': addToken(TokenType::LEFT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '!': addToken(matchNext('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': addToken(matchNext('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': addToken(matchNext('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>': addToken(matchNext('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
        default: 
            _errorReporter->error(_line, "Unexptected character.");
            break; 
    }
}

auto Scanner::scanTokens() -> std::vector<Token>
{
    while (!isAtEnd()) {
        _start = _current;
        scanToken();
    }
    _tokens.emplace_back(TokenType::END_OF_FILE, "", std::nullopt, _line);
    return _tokens;
}

} // namespace lox
