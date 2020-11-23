//
// Created by nicolas on 21/11/2020.
//

#include "FileSystem.h"
#include <iostream>


void FileSystem::run()
{
    std::string input;
    std::cout << "FS >>>\n";
    while (std::cin >> input)
    {
        if (input == "create")
        {
            std::cin >> input;
            std::cout << input;
        }
        else if (input == "del")
        {

        }
        else if (input == "copy")
        {

        }
        else if (input == "move")
        {

        }
        else if (input == "read")
        {

        }
        else if (input == "write")
        {

        }
        else
        {
            std::cout << "Incorrect Command\n";
        }
        std::cout << "\nFS >>>\n";
    }
}
