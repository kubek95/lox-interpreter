#include "Scanner.hpp"
#include "ErrorReporter.hpp"
#include "gtest/gtest.h"
#include <memory>

namespace lox {
namespace ut {
    
class UtScanner : public ::testing::Test
{
    protected:
        UtScanner();
        std::unique_ptr<Scanner> uut;
        std::shared_ptr<ErrorReporter> errorReporter;
};

UtScanner::UtScanner()
{
    errorReporter = std::make_shared<ErrorReporter>();
    uut = std::make_unique<Scanner>("d<>ummySource", errorReporter);
}

TEST_F(UtScanner, ShouldReturnEmptyListOfTokens)
{
    auto result = uut->run();
    ASSERT_TRUE(result.empty());
}

} // namespace ut
} // namespace lox
