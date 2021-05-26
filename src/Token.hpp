#pragma once

#include "Tokens.hpp"
#include <string>
#include <sstream>
#include <variant>

namespace lox {

using LiteralType = std::variant<int,
                                 std::string,
                                 double>;
class Token
{
    public:
        Token(TokenType tokenType, std::string lexeme, LiteralType literal, int line);
        friend auto operator<<(std::ostringstream& os, Token token) -> std::ostringstream&;

    private:
        TokenType _tokenType;
        std::string _lexeme;
        LiteralType _literal;
        int _line;
};

inline auto operator<<(std::ostringstream& os, Token token) -> std::ostringstream&
{
    
    os << EnumToString(token._tokenType)
       << std::string{" "}
       << token._lexeme
       << std::string{" "};
       
    if (std::holds_alternative<int>(token._literal)) {
        os << std::get<int>(token._literal);
    } else if (std::holds_alternative<double>(token._literal)) {
        os << std::get<double>(token._literal);
    } else {
        os << std::get<std::string>(token._literal);
    }
    return os;
}

} // namespace lox
