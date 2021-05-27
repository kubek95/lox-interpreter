#pragma once

#include "Tokens.hpp"
#include <string>
#include <sstream>
#include <variant>
#include <optional>

namespace lox {

using LiteralType = std::variant<int,
                                 std::string,
                                 double>;
class Token
{
    public:
        Token(TokenType tokenType, std::string lexeme, std::optional<LiteralType> literal, int line);
        friend auto operator<<(std::ostringstream& os, Token token) -> std::ostringstream&;

    private:
        TokenType _tokenType;
        std::string _lexeme;
        std::optional<LiteralType> _literal;
        int _line;
};

inline auto operator<<(std::ostringstream& os, Token token) -> std::ostringstream&
{
    
    os << EnumToString(token._tokenType)
       << std::string{" "}
       << token._lexeme
       << std::string{" "};
       
    if (!token._literal.has_value()) {
        os << "null";
    } else if (std::holds_alternative<int>(token._literal.value())) {
        os << std::get<int>(token._literal.value());
    } else if (std::holds_alternative<double>(token._literal.value())) {
        os << std::get<double>(token._literal.value());
    } else {
        os << std::get<std::string>(token._literal.value());
    }
    return os;
}

} // namespace lox
