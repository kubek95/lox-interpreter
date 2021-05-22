#include "gtest/gtest.h"

namespace lox {
    namespace ut {
        class UtMain : public ::testing::Test
        {
            protected:
        };

        TEST_F(UtMain, ShouldExitWithErrorWhenFileDoesNotExists)
        {
            
        }

        TEST_F(UtMain, ShouldRunPromptWhenInvokedWithoutParameters)
        {
        }

        TEST_F(UtMain, ShouldRunInterpreterWhenValidPathToLoxScriptHasBeenGiven)
        {
            
        }
    } // namespace ut
} // namespace lox
