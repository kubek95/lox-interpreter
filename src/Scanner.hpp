#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Token.hpp"
#include <string>
#include <vector>

namespace lox {
    
    class Scanner
    {
        public:
            Scanner(std::string contentToScan);
            auto run() -> std::vector<Token>;

        private:
            std::string _contentToScan;
            std::vector<Token> tokens{};
    };
} // namespace lox

#endif // SCANNER_HPP
