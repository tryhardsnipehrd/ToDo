#include "TodoList.hpp"

#include <iostream>
#include <vector>

void PrintList( const std::vector<ToDoItem> &ItemList ) {
    for ( ToDoItem temp : ItemList ) {
    
        std::cout << temp.ID << ". ";
        // Check if it's been completed
        if ( temp.IsCompleted ) {
            std::cout << "[x] "; 
        } else {
            std::cout << "[ ] ";
        }
        
        // Print the name of the item
        std::cout << temp.Name << "\n";
        // And now the description
        std::cout << "\t" << temp.Description << "\n";
        
    }
    std::cout << std::endl;
}

void DeleteItem( std::vector<ToDoItem> &ItemList, int ID ) {
    int i;
    ToDoItem temp;

    for ( i=0; i<ItemList.size(); i++ ) {
        if ( ItemList.at(i).ID == ID ) {
            ItemList.erase( ItemList.begin() + i );
            return;
        }
    }
}

void ToggleItem( std::vector<ToDoItem> &ItemList, int ID ) {
    int i;

    for ( i=0; i<ItemList.size(); i++ ) {
        if ( ItemList.at(i).ID == ID ) {
            INVERT(ItemList.at(i).IsCompleted);
            return;
        }
    }
}

void ClearList( std::vector<ToDoItem> &ItemList ) {
    std::vector<int> idsToRemove;
    int i;

    for ( i=0; i<ItemList.size(); i++ ) {
        if ( ItemList.at(i).IsCompleted ) {
            idsToRemove.push_back( ItemList.at(i).ID );
        }
    }

    for ( i=0; i<idsToRemove.size(); i++ ) {
        DeleteItem( ItemList, idsToRemove.at(i) );
    }

    SaveList( ItemList );
}
