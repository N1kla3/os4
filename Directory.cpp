//
// Created by nicolas on 21/11/2020.
//

#include "Directory.h"
#include "File.h"
#include "Table.h"

File Directory::findDirectory(const std::string &dirName)
{
}

Directory Directory::findFile(const std::string &fileName)
{
}

void Directory::addFile(const File& file)
{
    files.push_back(file);
}

void Directory::delFile(const File& file)
{
    if (Table::getChunk(file.index)->copy == 1)
    {
        Table::delChunk(file.index);
    }
    else
    {
        Table::getChunk(file.index)->copy--;
    }
}

void Directory::addDir(const Directory& dir)
{
    childs.push_back(dir);
}

void Directory::delDir(const Directory& dir)
{
    for (const auto& file : dir.files)
    {
        delFile(file);
    }
    for (const auto& direc : dir.childs)
    {
        delDir(direc);
    }
    for (auto start = childs.begin(); start != childs.end(); start++)
    {
        if ((*start).name == dir.name)
        {
            childs.erase(start);
        }
    }
}
