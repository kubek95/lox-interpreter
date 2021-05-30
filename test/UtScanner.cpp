#include "Scanner.hpp"
#include "ErrorReporter.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <memory>
#include <iostream>

namespace lox {
namespace ut {

class UtScanner : public ::testing::Test
{
    protected:
        auto initializeScanner(const std::string& toScan) -> void;
        void printMismatched(const std::vector<Token>& exp, const std::vector<Token>& rec);

        std::unique_ptr<Scanner> uut;
        std::shared_ptr<ErrorReporter> errorReporter = std::make_shared<ErrorReporter>();
        const std::string allTokensAsString = 
            R"tokens((){},.-+;*/!!===>>=<<==identifierExample"string"2.2
            and class else false fun for if nil or print return
            this super true var while //comment class else)tokens";
        const std::string cStyleComment = 
            R"comment(class elser /*class dsdfa*/
            /*super comment asdf
             */)comment";
        std::vector<Token> expectedCommentTokens {
            {TokenType::CLASS, "class", std::nullopt, 1},
            {TokenType::IDENTIFIER, "elser", std::nullopt, 1},
            {TokenType::END_OF_FILE, "", std::nullopt, 3}
        };
        std::vector<Token> expectedTokens {
                {TokenType::LEFT_PAREN, "(", std::nullopt, 1},
                {TokenType::RIGHT_PAREN, ")", std::nullopt, 1},
                {TokenType::LEFT_BRACE, "{", std::nullopt, 1},
                {TokenType::RIGHT_BRACE, "}", std::nullopt, 1},
                {TokenType::COMMA, ",", std::nullopt, 1},
                {TokenType::DOT, ".", std::nullopt, 1},
                {TokenType::MINUS, "-", std::nullopt, 1},
                {TokenType::PLUS, "+", std::nullopt, 1},
                {TokenType::SEMICOLON, ";", std::nullopt, 1},
                {TokenType::STAR, "*", std::nullopt, 1},
                {TokenType::SLASH, "/", std::nullopt, 1},
                {TokenType::BANG, "!", std::nullopt, 1},
                {TokenType::BANG_EQUAL, "!=", std::nullopt, 1},
                {TokenType::EQUAL_EQUAL, "==", std::nullopt, 1},
                {TokenType::GREATER, ">", std::nullopt, 1},
                {TokenType::GREATER_EQUAL, ">=", std::nullopt, 1},
                {TokenType::LESS, "<", std::nullopt, 1},
                {TokenType::LESS_EQUAL, "<=", std::nullopt, 1},
                {TokenType::EQUAL, "=", std::nullopt, 1},
                {TokenType::IDENTIFIER, "identifierExample", std::nullopt, 1},
                {TokenType::STRING, R"id("string")id", "string", 1},
                {TokenType::NUMBER, "2.2", 2.2, 1},
                {TokenType::AND, "and", std::nullopt, 2},
                {TokenType::CLASS, "class", std::nullopt, 2},
                {TokenType::ELSE, "else", std::nullopt, 2},
                {TokenType::FALSE, "false", std::nullopt, 2},
                {TokenType::FUN, "fun", std::nullopt, 2},
                {TokenType::FOR, "for", std::nullopt, 2},
                {TokenType::IF, "if", std::nullopt, 2},
                {TokenType::NIL, "nil", std::nullopt, 2},
                {TokenType::OR, "or", std::nullopt, 2},
                {TokenType::PRINT, "print", std::nullopt, 2},
                {TokenType::RETURN, "return", std::nullopt, 2},
                {TokenType::THIS, "this", std::nullopt, 3},
                {TokenType::SUPER, "super", std::nullopt, 3},
                {TokenType::TRUE, "true", std::nullopt, 3},
                {TokenType::VAR, "var", std::nullopt, 3},
                {TokenType::WHILE, "while", std::nullopt, 3},
                {TokenType::END_OF_FILE, "", std::nullopt, 3}
        };
};

auto UtScanner::initializeScanner(const std::string& toScan) -> void
{
    uut = std::make_unique<Scanner>(toScan, errorReporter);
}

void UtScanner::printMismatched(const std::vector<Token>& exp, const std::vector<Token>& rec)
{
    std::ostringstream os;
    os << "hello there \n";
    for (std::size_t i{0}; i < exp.size(); ++i) {
        if (rec.at(i) == exp.at(i)) {
        } else {
            os << "Expected: ";
            os << exp.at(i) << '\n';
            os << "Received: ";
            os << rec.at(i) << '\n';
        }
    }
    std::cout << os.str();
}

TEST_F(UtScanner, ShouldReturnEmptyListOfTokens)
{
    initializeScanner(allTokensAsString);
    auto result = uut->run();
    EXPECT_THAT(result, ::testing::ContainerEq(expectedTokens));
}

TEST_F(UtScanner, ShouldReturnIgnoreComments)
{
    initializeScanner(cStyleComment);
    auto result = uut->run();
    printMismatched(expectedCommentTokens, result);
    EXPECT_THAT(result, ::testing::ContainerEq(expectedCommentTokens));
}
} // namespace ut
} // namespace lox
