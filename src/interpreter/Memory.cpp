#include "Memory.hpp"

#include <iostream>

std::vector<uint8_t> Memory::cells = {};

int Memory::pointer = 0;

void Memory::initializeMemory() {
    Memory::cells = {};
    for (int i = 0; i < 30000; i++) {
        Memory::cells.push_back(0);
    }
    pointer = 0;
}

void Memory::movePointerLeft() {
    pointer--;
    if (pointer < 0) {
        std::cerr << "Fatal error: memory pointer cannot be negative.\n";
        exit(-1);
    }
}

void Memory::movePointerRight() {
    pointer++;
    if (pointer >= Memory::cells.size()) {
        std::cerr << "Fatal error: memory pointer cannot be greater than 29,999.\n";
        exit(-1);
    }
}

void Memory::increaseMemoryCellValue() {
    Memory::cells[pointer]++;
}

void Memory::decreaseMemoryCellValue() {
    Memory::cells[pointer]--;
}

int Memory::getMemoryCellValue() {
    return Memory::cells[pointer];
}

void Memory::setMemoryCellValue(uint8_t value) {
    Memory::cells[pointer] = value;
}

void Memory::printMemoryCellValue() {
    std::cout.put(Memory::cells[pointer]);
}
