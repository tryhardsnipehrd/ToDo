#pragma once

#include <fstream>
#include <string>
#include <vector>

struct ToDoItem{
    std::string     Name;
    std::string     Description;
    bool            IsCompleted = false;
    int             ID;
};

void PrintList( const std::vector<ToDoItem> &ItemList );
void SaveList( const std::vector<ToDoItem> &ItemList );




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
        std::cout << "\t" << temp.Description << std::endl;
        
    }
};

void SaveList( const std::vector<ToDoItem> &ItemList ) {
    const std::string fileLocation = "./todolist.sav";
    std::ofstream saveFile;

    // Open the file for writing, disregarding any existing content, since we want to save the most recent data
    saveFile.open( fileLocation, std::ofstream::out | std::ofstream::trunc );

    // First we write the amount of items we have to the first line
    saveFile << ItemList.size() << "\n";

    for ( ToDoItem temp : ItemList ) {
        saveFile << temp.ID << "\n";
        saveFile << temp.Name << "\n";
        saveFile << temp.Description << "\n";
        saveFile << temp.IsCompleted << std::endl;
    }

    saveFile.close();
};
