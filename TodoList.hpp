#pragma once

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
void PrintHelp();

