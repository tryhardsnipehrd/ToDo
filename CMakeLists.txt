cmake_minimum_required(VERSION 3.22)
project(TodoList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=llvm-include-order,misc-include-cleaner;
    )

add_executable(TodoList main.cpp functions.cpp)
