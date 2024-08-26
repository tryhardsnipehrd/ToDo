#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "TodoList.hpp"


int main(int argc, char** argv) {
    const   int     MIN_ARGS   =   2;
    const   char    ADD_STRING[] = "add";
    const   char    LIST_STRING1[] = "check";
    const   char    LIST_STRING2[] = "list";
    const   char    DELETE_STRING[] = "delete";
    const   char    TOGGLE_STRING[] = "toggle";
    const   char    HELP_STRING[] = "help";
    const   char    CLEAR_STRING[] = "clear";
    std::vector<ToDoItem> itemList;
    ToDoItem    tempItem;
    std::string tempString;


    // First we need to ensure that we have any arguments to the program
    if ( argc < MIN_ARGS ) {
        PrintHelp();
        return 0;
    }

    // Verify that our file exists
    CheckSaveDir();

    // First we need to load our list.
    LoadList( itemList );
    
    if ( strcmp( argv[1], ADD_STRING ) == 0 ) {
        std::cout << "Name of the ToDo List Item: ";
        std::getline( std::cin, tempString );
        tempItem.Name = tempString;

        std::cout << "Description: ";
        std::getline( std::cin, tempString );
        tempItem.Description = tempString;

        if ( itemList.empty() ) {
            tempItem.ID = 1;
        } else {
            tempItem.ID = itemList.back().ID + 1;
        }

        itemList.push_back( tempItem );

        SaveList( itemList );
    } else if ( strcmp( argv[1], LIST_STRING1 ) == 0 ) {
        PrintList( itemList );
    } else if ( strcmp( argv[1], LIST_STRING2 ) == 0 ) {
        PrintList( itemList );
    } else if ( strcmp( argv[1], DELETE_STRING ) == 0 ) {
        if ( argc != 3 ) {
            std::cout << "Please specify exactly one ID to remove." << std::endl;
            return 0;
        }

        DeleteItem( itemList, std::stoi( argv[2] ) );
        SaveList( itemList );
    } else if ( strcmp( argv[1], TOGGLE_STRING ) == 0 ) {
        if ( argc != 3 ) {
            std::cout << "Please specify exactly one ID to toggle." << std::endl;
            return 0;
        }

        ToggleItem( itemList, std::stoi( argv[2] ) );
        SaveList( itemList );

    } else if ( strcmp( argv[1], HELP_STRING ) == 0 ) {
        PrintHelp(); 
    } else if ( strcmp( argv[1], CLEAR_STRING ) == 0 ) {
        ClearList( itemList );
        SaveList( ItemList );
    }

    else {
        std::cout << "Invalid parameters passed: " << argv[1] << std::endl;
    }
}
