#include "TodoList.hpp"

#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>

void PrintHelp() {
    std::cout << "Usage:\n\tToDoList <command>\n\n";
    std::cout << "help\tOutput this menu\n";
    std::cout << "add\tAdd an item to the list\n";
    std::cout << "list\tList the contents of the list\n";
    std::cout << "check\tSame as above\n";
    std::cout << "delete\tDelete an item from the list by id\n";
    std::cout << "toggle\tToggle the completion of an item\n";
    std::cout << "clear\tRemove all items that are completed\n";

    std::cout << std::endl;
}

std::string getSaveDir() {
    if ( IS_LINUX ) {
        char* curUser;
        std::string strUser;
        std::string confPath = "/home/";
        curUser = getenv( "USER" );
        if ( curUser == NULL ) {
            std::cout << "Could not find $USER. Please ensure $USER is set in the environment variables" << std::endl;
            exit(1);
        }
        strUser.assign( curUser, strlen( curUser ) ); 
        confPath.append(strUser);
        confPath.append( "/.local/ToDo/" );
        return confPath;
    }
}

