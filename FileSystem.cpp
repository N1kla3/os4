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
            current->addFile(input);
        }
        else if (input == "createdir")
        {
            std::cin >> input;
            current->addDir(input);
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
                int index = current->findFile(input)->index;
                std::cin >> input;
                auto nf = std::make_shared<File>(input);
                nf->index = index;
                Table::getChunk(nf->index)->copy++;
            }
            catch (std::exception&)
            {
                std::cout << "NO SUCH FILE";
            }
        }
        else if (input == "move")
        {
            std::cin >> input;
            try
            {
                auto dir = current->findDirectory(input);
                std::cin >> input;
                auto file = current->findFile(input);
                dir->moveFile(file);
                current->delFile(file);
            }
            catch (std::exception&)
            {
                std::cout << "NO SUCH CONSUMABLES";
            }
        }
        else if (input == "read")
        {

        }
        else if (input == "write")
        {

        }
        else if (input == "cd")
        {
            std::cin >> input;
            if (input == root->name)
            {
                current = root;
            } else {
                try
                {
                    current = current->findDirectory(input);
                }
                catch (std::exception&)
                {
                    std::cout << "NO SUCH DIRECTORY\n";
                }
            }
        }
        else if (input == "ls")
        {
            current->print();
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
    root = std::make_shared<Directory>(Directory("root"));
    current = root;
}
