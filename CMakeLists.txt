cmake_minimum_required(VERSION 4.2)
project(CppBrainfuckInterpreter)

set(CMAKE_CXX_STANDARD 26)

add_executable(CppBrainfuckInterpreter src/main.cpp
        src/interpreter/Interpreter.cpp
        src/interpreter/Interpreter.hpp
        src/interpreter/Memory.cpp
        src/interpreter/Memory.hpp)
