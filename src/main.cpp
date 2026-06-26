#include <iostream>
#include <string>

#include "interpreter/Interpreter.hpp"

int main(int argc, char** argv) {
    std::string filePath;
    if (argc >= 2) {
        filePath = argv[1];
    } else {
        return -1;
    }

    auto* interpreter = new Interpreter(filePath);
    interpreter->initialize();

    interpreter->run();

    std::cout << std::endl;
    return 0;
}
