#include "Token.hpp"

namespace lox {

Token::Token(TokenType tokenType, std::string lexeme, std::optional<LiteralType> literal, int line):
    _tokenType{tokenType},
    _lexeme{std::move(lexeme)},
    _literal{literal},
    _line{line}
{
}

auto Token::operator==(const Token& rhs) const -> bool
{
    return _tokenType == rhs._tokenType &&
        _lexeme == rhs._lexeme &&
        _literal == rhs._literal &&
        _line == rhs._line;
}

} // namespace lox
