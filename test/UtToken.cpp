#include "gtest/gtest.h"

#include "Token.hpp"

namespace lox {
namespace ut {

class UtToken: public ::testing::Test
{
    protected:
};

TEST_F(UtToken, ShouldPrintStringTokenContentCorrectly)
{
    Token uut{TokenType::AND, "lexeme", "35", 1};
    std::ostringstream stringizedToken;
    stringizedToken << uut;
    ASSERT_EQ("TokenType::AND lexeme 35", stringizedToken.str());
}

TEST_F(UtToken, ShouldPrintIntTokenContentCorrectly)
{
    Token uut{TokenType::NUMBER, "numb", 43, 1};
    std::ostringstream stringizedToken;
    stringizedToken << uut;
    ASSERT_EQ("TokenType::NUMBER numb 43", stringizedToken.str());
}

TEST_F(UtToken, ShouldPrintDoubleTokenCorrectly)
{
    Token uut{TokenType::NUMBER, "double", 2.3, 4};
    std::ostringstream stringizedToken;
    stringizedToken << uut;
    ASSERT_EQ("TokenType::NUMBER double 2.3", stringizedToken.str());
}
} // namespace ut
} // namespace lox
