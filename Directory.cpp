//
// Created by nicolas on 21/11/2020.
//

#include "Directory.h"
#include "Table.h"

Directory& Directory::findDirectory(const std::string &dirName)
{
    for (auto& dir : children)
    {
        if (dirName == dir.name)
        {
            return dir;
        }
    }
    throw std::exception();
}

File& Directory::findFile(const std::string &fileName)
{
    for (auto& file : files)
    {
        if (fileName == file.name)
        {
            return file;
        }
    }
    throw std::exception();
}

void Directory::addFile(const File& file)
{
    files.push_back(file);
}

void Directory::delFile(const File& file)
{
    if (Table::getChunk(file.index).copy == 1)
    {
        Table::delChunk(file.index);
        for (auto start = files.begin(); start != files.end(); start++)
        {
            if ((*start).name == file.name)
            {
                files.erase(start);
            }
        }
    }
    else
    {
        Table::getChunk(file.index).copy--;
    }
}

void Directory::addDir(const Directory& dir)
{
    children.push_back(dir);
}

void Directory::delDir(const Directory& dir)
{
    for (const auto& file : dir.files)
    {
        delFile(file);
    }
    for (const auto& direc : dir.children)
    {
        delDir(direc);
    }
    for (auto start = children.begin(); start != children.end(); start++)
    {
        if ((*start).name == dir.name)
        {
            children.erase(start);
        }
    }
}
