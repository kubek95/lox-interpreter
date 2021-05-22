#include "Scanner.hpp"
#include "gtest/gtest.h"
#include <memory>

namespace lox {
namespace ut {
    
class UtScanner : public ::testing::Test
{
    protected:
        std::unique_ptr<Scanner> uut = std::make_unique<Scanner>("defaultPath");
};

TEST_F(UtScanner, ShouldReturnEmptyListOfTokens)
{
    auto result = uut->run();
    ASSERT_TRUE(result.empty());
}

} // namespace ut
} // namespace lox
