#pragma once

#include <string>
#include <vector>

struct ToDoItem{
    std::string     Name;
    std::string     Description;
    bool            IsCompleted;
};

void PrintList( std::vector<ToDoItem> ItemList );




void PrintList( std::vector<ToDoItem> ItemList ) {
    for ( ToDoItem temp : ItemList ) {
        // Check if it's been completed
        if ( temp.IsCompleted ) {
            std::cout << "[x] "; 
        } else {
            std::cout << "[ ] ";
        }
        
        // Print the name of the item
        std::cout << temp.Name << std::endl;
        // And now the description
        std::cout << "\t" << temp.Description << std::endl;
        
    }
};


