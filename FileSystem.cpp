//
// Created by nicolas on 21/11/2020.
//

#include "FileSystem.h"
#include <iostream>
#include "File.h"


void FileSystem::run()
{
    std::string input;
    std::cout << "FS >>>\n";
    while (std::cin >> input)
    {
        if (input == "create")
        {
            std::cin >> input;
            current->addFile(File(input));
        }
        else if (input == "del")
        {
            std::cin >> input;
            try
            {
                current->delFile(current->findFile(input));
            } catch (std::exception&)
            {
                std::cout << "NO SUCH FILE\n";
            }
        }
        else if (input == "deldir")
        {
            std::cin >> input;
            try
            {
                current->delDir(current->findDirectory(input));
            } catch (std::exception&)
            {
                std::cout << "NO SUCH DIRECTORY\n";
            }
        }
        else if (input == "copy")
        {
            try
            {
                std::cin >> input;
                File nf = current->findFile(input);
                std::cin >> input;
                nf.name = input;
            }
            catch (std::exception&)
            {
                std::cout << "NO SUCH FILE";
            }
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

FileSystem::FileSystem()
{
    root = Directory();
    current = &root;
}
