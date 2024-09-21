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

inline const   int     MIN_ARGS   =   2;
inline const   char    ADD_STRING[] = "add";
inline const   char    LIST_STRING1[] = "check";
inline const   char    LIST_STRING2[] = "list";
inline const   char    DELETE_STRING[] = "delete";
inline const   char    TOGGLE_STRING[] = "toggle";
inline const   char    HELP_STRING[] = "help";
inline const   char    CLEAR_STRING[] = "clear";

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
const std::string &getSaveDir();
void PrintHelp();
void ClearList( std::vector<ToDoItem> &ItemList );


