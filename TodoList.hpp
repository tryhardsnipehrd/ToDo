#pragma once

#include <fstream>
#include <string>
#include <vector>

#define TODO_FILE_LOCATION "./todolist.sav"

struct ToDoItem{
    std::string     Name;
    std::string     Description;
    bool            IsCompleted = false;
    int             ID;
};

void PrintList( const std::vector<ToDoItem> &ItemList );
void SaveList( const std::vector<ToDoItem> &ItemList );
void LoadList( std::vector<ToDoItem> &ItemList );




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
    std::ofstream saveFile;

    // Open the file for writing, disregarding any existing content, since we want to save the most recent data
    saveFile.open( TODO_FILE_LOCATION, std::ofstream::out | std::ofstream::trunc );

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

void LoadList( std::vector<ToDoItem> &ItemList ) {
    ToDoItem temp;
    std::ifstream saveFile;
    int numItems;
    std::string buf;

    // Open the data for reading
    saveFile.open( TODO_FILE_LOCATION, std::ifstream::in );

    // Now get the first line, since that is how many items we need to read
    std::getline( saveFile, buf );

    // Convert the number to an int
    numItems = stoi( buf );

    for ( int i = 0; i < numItems; i++ ) {
        std::getline( saveFile, buf );
        temp.ID = stoi( buf );

        std::getline( saveFile, buf );
        temp.Name = buf;

        std::getline( saveFile, buf );
        temp.Description = buf;

        std::getline( saveFile, buf );
        if ( buf.at(0) == '0' ) {
            temp.IsCompleted = false;
        } else {
            temp.IsCompleted = true;
        }

        ItemList.push_back( temp );
    }
};
