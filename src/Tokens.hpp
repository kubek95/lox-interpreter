#ifndef TOKEN_HPP
#define TOKEN_HPP

namespace lox {

enum class Token {
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

inline constexpr const char* EnumToString(Token token)
{
    switch(token) {
#define CASE(x) case x: return #x
        CASE(Token::LEFT_PAREN);
        CASE(Token::RIGHT_PARTEN);
        CASE(Token::LEFT_BRACE);
        CASE(Token::RIGHT_BRACE);
        CASE(Token::COMMA);
        CASE(Token::DOT);
        CASE(Token::MINUS);
        CASE(Token::PLUS);
        CASE(Token::SEMICOLON);
        CASE(Token::SLASH);
        CASE(Token::STAR);
        CASE(Token::BANG);
        CASE(Token::BANG_EQUAL);
        CASE(Token::EQUAL);
        CASE(Token::EQUAL_EQUAL);
        CASE(Token::GREATER);
        CASE(Token::GREATER_EQUAL);
        CASE(Token::LESS);
        CASE(Token::LESS_EQUAL);
        CASE(Token::IDENTIFIER);
        CASE(Token::STRING);
        CASE(Token::NUMBER);
        CASE(Token::AND);
        CASE(Token::CLASS);
        CASE(Token::ELSE);
        CASE(Token::FALSE);
        CASE(Token::FUN);
        CASE(Token::FOR);
        CASE(Token::IF);
        CASE(Token::NIL);
        CASE(Token::OR);
        CASE(Token::PRINT);
        CASE(Token::RETURN);
        CASE(Token::THIS);
        CASE(Token::SUPER);
        CASE(Token::TRUE);
        CASE(Token::VAR);
        CASE(Token::WHILE);
        CASE(Token::END_OF_FILE);
    }
    return "<unknown token>";
#undef CASE
}

} // namespace lox

#endif // TOKEN_HPP
