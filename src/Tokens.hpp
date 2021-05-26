#pragma once

#include <string>

namespace lox {

enum class TokenType {
    LEFT_PAREN, RIGHT_PARTEN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    IDENTIFIER, STRING, NUMBER,
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, END_OF_FILE
};

inline auto EnumToString(TokenType token) -> std::string
{
    switch(token) {
#define CASE(x) case x: return #x
        CASE(TokenType::LEFT_PAREN);
        CASE(TokenType::RIGHT_PARTEN);
        CASE(TokenType::LEFT_BRACE);
        CASE(TokenType::RIGHT_BRACE);
        CASE(TokenType::COMMA);
        CASE(TokenType::DOT);
        CASE(TokenType::MINUS);
        CASE(TokenType::PLUS);
        CASE(TokenType::SEMICOLON);
        CASE(TokenType::SLASH);
        CASE(TokenType::STAR);
        CASE(TokenType::BANG);
        CASE(TokenType::BANG_EQUAL);
        CASE(TokenType::EQUAL);
        CASE(TokenType::EQUAL_EQUAL);
        CASE(TokenType::GREATER);
        CASE(TokenType::GREATER_EQUAL);
        CASE(TokenType::LESS);
        CASE(TokenType::LESS_EQUAL);
        CASE(TokenType::IDENTIFIER);
        CASE(TokenType::STRING);
        CASE(TokenType::NUMBER);
        CASE(TokenType::AND);
        CASE(TokenType::CLASS);
        CASE(TokenType::ELSE);
        CASE(TokenType::FALSE);
        CASE(TokenType::FUN);
        CASE(TokenType::FOR);
        CASE(TokenType::IF);
        CASE(TokenType::NIL);
        CASE(TokenType::OR);
        CASE(TokenType::PRINT);
        CASE(TokenType::RETURN);
        CASE(TokenType::THIS);
        CASE(TokenType::SUPER);
        CASE(TokenType::TRUE);
        CASE(TokenType::VAR);
        CASE(TokenType::WHILE);
        CASE(TokenType::END_OF_FILE);
    }
    return "<unknown token>";
#undef CASE
}

} // namespace lox
