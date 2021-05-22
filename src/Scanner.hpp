#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "Tokens.hpp"
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
    };
} // namespace lox

#endif // SCANNER_HPP
