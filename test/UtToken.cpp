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
    ASSERT_EQ("TokenType::AND lexeme 35 1", stringizedToken.str());
}

TEST_F(UtToken, ShouldPrintDoubleTokenCorrectly)
{
    Token uut{TokenType::NUMBER, "double", 2.3, 4};
    std::ostringstream stringizedToken;
    stringizedToken << uut;
    ASSERT_EQ("TokenType::NUMBER double 2.3 4", stringizedToken.str());
}

TEST_F(UtToken, ShouldPrintNullWhenLiteralIsEmpty)
{
    Token uut{TokenType::END_OF_FILE, "", std::nullopt, 5};
    std::ostringstream stringizedToken;
    stringizedToken << uut;
    ASSERT_EQ("TokenType::END_OF_FILE  null 5", stringizedToken.str());

}
} // namespace ut
} // namespace lox
