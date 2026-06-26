#ifndef CPPBRAINFUCKINTERPRETER_INTERPRETER_HPP
#define CPPBRAINFUCKINTERPRETER_INTERPRETER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class Interpreter {
public:
    Interpreter(const std::string& path = "");

    void setFilePath(const std::string& path = "");
    void initialize();

    void run();

private:
    std::unordered_map<int, int>  _createBracketsMap();
    int _keyFromValue(int value);


    bool isExtendedMode;
    std::string filePath;
    std::string fileContent;
    std::unordered_map<int, int> bracketsMap;
};


#endif //CPPBRAINFUCKINTERPRETER_INTERPRETER_HPP
