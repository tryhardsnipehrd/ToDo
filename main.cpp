#include <iostream>

#include "TodoList.hpp"

const   int     MIN_ARGS   =   2;

int main(int argc, char** argv) {
    // First we need to ensure that we have any arguments to the program
    if ( argc < MIN_ARGS ) {
        std::cout << "Usage:" << std::endl;
        std::cout << "\t" << argv[0] << " TBD" << std::endl;
        return 0;
    }
    Test();
}
