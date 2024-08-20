#include "TodoList.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


void SaveList( const std::vector<ToDoItem> &ItemList ) {
    std::ofstream saveFile;
    std::string ToDoFileLocation = getSaveDir();
    ToDoFileLocation.append( "ToDoItems.dat" );

    // Open the file for writing, disregarding any existing content, since we want to save the most recent data
    saveFile.open( ToDoFileLocation, std::ofstream::out | std::ofstream::trunc );
    if ( !saveFile.is_open() ) {
        std::cout << "File Not Opened" << std::endl;
        return;
    }

    // First we write the amount of items we have to the first line
    saveFile << ItemList.size() << "\n";

    for ( ToDoItem temp : ItemList ) {
        saveFile << temp.ID << "\n";
        saveFile << temp.Name << "\n";
        saveFile << temp.Description << "\n";
        saveFile << temp.IsCompleted << std::endl;
    }

    saveFile.close();
}

void LoadList( std::vector<ToDoItem> &ItemList ) {
    ToDoItem temp;
    std::ifstream saveFile;
    int numItems;
    std::string buf;
    std::string ToDoFileLocation = getSaveDir();
    ToDoFileLocation.append( "ToDoItems.dat" );

    // Open the data for reading
    saveFile.open( ToDoFileLocation, std::ifstream::in );
 
    // Verify that the file actually exists...
    // If not, we need to return so we don't accidentally do dumb things...
    if ( !saveFile.is_open() ) {
        std::cout << "File Not Opened" << std::endl;
        std::cout << "If this is a first run, this is expected. Please run again after completing your current task." << std::endl;
        return;
    }

    // Now get the first line, since that is how many items we need to read
    std::getline( saveFile, buf );

    // Convert the number to an int
    numItems = stoi( buf );

    ItemList.reserve( numItems );

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
}

void CheckSaveDir() {
    std::filesystem::create_directory( getSaveDir() );
}
