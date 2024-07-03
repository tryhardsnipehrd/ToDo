#include <cstring>
#include <iostream>
#include <vector>

#include "TodoList.hpp"


int main(int argc, char** argv) {
    const   int     MIN_ARGS   =   2;
    const   char    NEW_STRING[] = "new";
    char    buf[80];
    std::vector<ToDoItem> ItemList;
    ToDoItem    tempItem;


    tempItem.Name = "Your First Item";
    tempItem.Description = "Add new items, remove existing ones, and make it your own!";
    tempItem.IsCompleted = true;

    // First we need to ensure that we have any arguments to the program
    if ( argc < MIN_ARGS ) {
        std::cout << "Usage:" << std::endl;
        std::cout << "\t" << argv[0] << " TBD" << std::endl;
        return 0;
    }
    
    // Now that we know we have enough args, we can continue to the main logic
    strncpy( buf, argv[1], 80 );

    if ( strcmp( buf, NEW_STRING ) == 0 ) {
        std::cout << "Creating a new list!" << std::endl;
        ItemList.push_back( tempItem ); 
        // DEBUG
        PrintList( ItemList );
    } 

    else {
        std::cout << "Invalid parameters passed: " << argv[1] << std::endl;
    }
}
