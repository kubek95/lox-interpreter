#include "Interpreter.hpp"

#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>

namespace lox {

auto extractStringFromFile(std::ifstream& fileStream) -> std::string
{
    std::ostringstream ostr;
    ostr << fileStream.rdbuf();
    return ostr.str();
}


auto main(int argc, char** argv) -> int
{
    if(argc > 2) {
        std::cerr << "Usage: cpplox [script]\n";
        return 64;
    } else if(argc == 1){
        // run prompt
        while(true) {
            std::cout << "> ";
            std::string command{};
            std::cin >> command;
            if(command.empty()) {
                break;
            }
            Interpreter interpreter;
            interpreter.runInterpreter(std::move(command));
        }
    } else {
        // run provided script
        std::ifstream fileStream {argv[1]};
        if (!fileStream.is_open()) {
            return -1;
        }
        Interpreter interpreter;
        interpreter.runInterpreter(extractStringFromFile(fileStream));
    }

    return 0;
}

} // namespace lox

