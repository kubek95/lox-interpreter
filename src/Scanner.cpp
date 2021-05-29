#include "Scanner.hpp"

#include <optional>
#include <cctype>
#include <cstdlib>
#include <iostream>

namespace lox {

const std::unordered_map<std::string, TokenType> Scanner::_keywords {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE}
};

Scanner::Scanner(std::string contentToScan, std::shared_ptr<ErrorReporter> errorReporter) :
    _contentToScan{std::move(contentToScan)},
    _errorReporter{std::move(errorReporter)}
{}

auto Scanner::run() -> std::vector<Token> 
{
    auto tokens{scanTokens()};
    for (const auto& token : tokens) {
        std::ostringstream os;
        os << token;
        std::cout << os.str() << '\n';
    }
    return tokens;
}

auto Scanner::isAtEnd() const -> bool
{
    return _current >= _contentToScan.size();
}

auto Scanner::advance() -> char
{
    return _contentToScan.at(_current++);
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

auto Scanner::peek() const -> char
{
    return isAtEnd() ? '\n' : _contentToScan.at(_current);
}

auto Scanner::scanString() -> void
{
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') {
            ++_line;
        }
        advance();
    }
    if (isAtEnd()) {
        _errorReporter->error(_line, "Unterminated string.");
        return;
    }
    advance();
    addToken(TokenType::STRING, _contentToScan.substr(_start+1, _current - _start));
}

auto Scanner::peekNext() const -> char
{
    if (_current + 1 >= _contentToScan.length()) {
        return '\0';
    }
    return _contentToScan.at(_current+1);
}

auto Scanner::counsumeNumberInSource() -> void
{
    while (std::isdigit(peek())) {
        advance();
    }
}

auto Scanner::scanNumber() -> void
{
    counsumeNumberInSource();
    if (peek() == '.' && std::isdigit(peekNext())) {
        advance();
        counsumeNumberInSource(); 
    }
    auto numberStr{_contentToScan.substr(_start, _current - _start)};
    addToken(TokenType::NUMBER, std::stod(numberStr));
}

auto Scanner::determineIdentifierType(const std::string& identifier) const -> TokenType
{
    auto result = _keywords.find(identifier);
    return result == _keywords.end() ? TokenType::IDENTIFIER : result->second;
}

auto Scanner::identifier() -> void
{
    while(std::isalnum(peek())) {
        advance();
    }
    auto identifier{_contentToScan.substr(_start, _current - _start)};
    addToken(determineIdentifierType(identifier));
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
        case '/':
            if (matchNext('/')) {
                while (peek() != '\n' && !isAtEnd()) {
                    advance();
                } 
            } else {
                addToken(TokenType::SLASH);
            }
            break;
        case ' ':
        case '\t':
        case '\r':
            break;
        case '\n':
            ++_line;
            break;
        case '"': scanString(); break;
        case 'o':
            
        default: 
            if (std::isdigit(c)) {
                scanNumber();
            } else if (std::isalpha(c)) {
                identifier();
            } else {
                _errorReporter->error(_line, "Unexptected character.");
            }
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
