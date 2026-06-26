#ifndef CPPBRAINFUCKINTERPRETER_MEMORY_HPP
#define CPPBRAINFUCKINTERPRETER_MEMORY_HPP

#include <iostream>
#include <vector>

class Memory {
public:
    static void initializeMemory();

    static void movePointerLeft();
    static void movePointerRight();

    static void increaseMemoryCellValue();
    static void decreaseMemoryCellValue();

    static int getMemoryCellValue();
    static void setMemoryCellValue(uint8_t value);

    static void printMemoryCellValue();

    static std::vector<uint8_t> cells;
    static int pointer;
};


#endif //CPPBRAINFUCKINTERPRETER_MEMORY_HPP
