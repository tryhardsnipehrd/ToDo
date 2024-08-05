#pragma once

#include <filesystem>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


#define INVERT(x) (x = !x)
#define IS_LINUX false
#define IS_WINDOWS false

#ifdef __linux__
    #undef IS_LINUX
    #define IS_LINUX true
#endif
#ifdef _WIN32
    #undef IS_WINDOWS
    #define IS_WINDOWS true
#endif


struct ToDoItem{
    std::string     Name;
    std::string     Description;
    bool            IsCompleted = false;
    int             ID;
};

void PrintList( const std::vector<ToDoItem> &ItemList );
void SaveList( const std::vector<ToDoItem> &ItemList );
void LoadList( std::vector<ToDoItem> &ItemList );
void DeleteItem( std::vector<ToDoItem> &ItemList, int ID );
void ToggleItem( std::vector<ToDoItem> &ItemList, int ID );
void CheckSaveDir();
std::string getSaveDir();


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
}

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


void CheckSaveDir() {
    std::filesystem::create_directory( getSaveDir() );
}

void PrintHelp() {
    std::cout << "Usage:\n";
    std::cout << "\tToDoList <command>\n\n";
    std::cout << "Valid Commands:\n";
    std::cout << "help\tOutput this menu\n";
    std::cout << "add\tAdd an item to the list\n";
    std::cout << "check\tCheck the contents of the list\n";
    std::cout << "list\tSame as check\n";
    std::cout << "delete\tRemove an item from the list\n";
    std::cout << "toggle\tToggle the completion status of an item" << std::endl;
}


std::string getSaveDir() {
    char* curUser;
    std::string strUser;
    std::string confPath = "/home/";

    if ( IS_LINUX ) {
        curUser = getenv( "USER" );
        if ( curUser == NULL ) {
            std::cout << "Could not find $USER. Please ensure $USER is set in the environment variables" << std::endl;
            exit(1);
        }
        strUser.assign( curUser, strlen( curUser ) ); 
        confPath.append(strUser);
        confPath.append( "/.local/ToDo/" );
    }

    return confPath;
}
