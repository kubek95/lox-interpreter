#include "Token.hpp"

namespace lox {

Token::Token(TokenType tokenType, std::string lexeme, LiteralType literal, int line):
    _tokenType{tokenType},
    _lexeme{std::move(lexeme)},
    _literal{literal},
    _line{line}
{
}

} // namespace lox
