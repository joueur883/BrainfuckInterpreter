#include "Interpreter.hpp"

#include "Memory.hpp"

#include <filesystem>

Interpreter::Interpreter(const std::string& path) {
    filePath = path;
    isExtendedMode = false;
}

void Interpreter::setFilePath(const std::string &path) {
    filePath = path;
}

void Interpreter::initialize() {
    if (!std::filesystem::exists(filePath)) {
        std::cerr << "Fatal errror: file path doesn't exist.\n";
        exit(-1);
    }

    std::ifstream ifs(filePath);
    std::string line;

    while (std::getline(ifs, line)) {
        fileContent += line;
    }

    if (!fileContent.empty()) {
        if (fileContent[0] == '#') {
            isExtendedMode = true;
        }
    }

    Memory::initializeMemory();
}


std::unordered_map<int, int> Interpreter::_createBracketsMap() {
    std::unordered_map<int, int> toReturn = {};
    std::unordered_map<int, int> depths = {};

    int depth = 0;

    for (int i = 0; i < fileContent.length(); i++) {
        if (fileContent[i] == '[') {
            depth++;
            depths[depth] = i;
        } else if (fileContent[i] == ']') {
            if (depths.contains(depth)) {
                toReturn[depths[depth]] = i;
                depths.erase(depth);
            }
            depth--;
        }
    }

    return toReturn;
}

int Interpreter::_keyFromValue(int value) {
    for (const auto& element : bracketsMap) {
        if (element.second == value) {
            return element.first;
        }
    }

    return -1;
}

void Interpreter::run() {
    int i = 0;

    /*
     * How the bracketMap works:
     * +++[>+++++[-]<-]
     * Becomes:
     * {
     *  {3, 15},  3: first [, 15: last ]
     *  {10, 12}  10: second [, 12: next ]
     * }
     */
    bracketsMap = _createBracketsMap();

    while (true) {
        if (i >= fileContent.length()) {
            break;
        }

        switch (fileContent[i]) {
            case '<':
                Memory::movePointerLeft();
                break;
            case '>':
                Memory::movePointerRight();
                break;
            case '+':
                Memory::increaseMemoryCellValue();
                break;
            case '-':
                Memory::decreaseMemoryCellValue();
                break;
            case ',':
                Memory::setMemoryCellValue(getchar());
                break;
            case '.':
                Memory::printMemoryCellValue();
                break;
            case '!':
                if (isExtendedMode) {
                    std::cout << Memory::getMemoryCellValue() << std::endl;
                }
                break;
            case '?':
                if (isExtendedMode) {
                    std::string theVoid;
                    std::getline(std::cin, theVoid);
                }
                break;
            case '[':
                if (bracketsMap.contains(i)) {
                    if (Memory::getMemoryCellValue() == 0) {
                        i = bracketsMap.at(i) + 1;
                    }
                }
                break;
            case ']':
                if (Memory::getMemoryCellValue() != 0) {
                    int newI = _keyFromValue(i);
                    if (newI != -1) {
                        i = newI;
                    }
                }
                break;
            default:
                break;
        }
        i++;
    }
}
