#include "TodoList.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
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

const std::string &getSaveDir() {
    static std::string confPath;

    if (!confPath.empty()) return confPath;

    if ( IS_LINUX ) {
        confPath = "/home/";

        const char* curUser = getenv( "USER" );
        std::string strUser;
        if ( curUser == NULL ) {
            std::cout << "Could not find $USER. Please ensure $USER is set in the environment variables" << std::endl;
            confPath = "";
            exit(1);
        }
        strUser = curUser; 
        confPath.append(strUser);
        confPath.append( "/.local/ToDo/" );
        return confPath;
    } else if ( IS_WINDOWS ) {
        char* appData;

        appData = getenv( "APPDATA" );
        if ( appData == NULL ) {
            std::cout << "Could not find %APPDATA%. Please ensure you are on a windows system.";
            confPath = "";
            exit(1);
        }
        confPath = appData;
        confPath.append( "/ToDo/" );
        return confPath;
    }
}

