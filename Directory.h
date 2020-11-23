//
// Created by nicolas on 21/11/2020.
//

#ifndef OS4_DIRECTORY_H
#define OS4_DIRECTORY_H


#include <vector>
#include <string>
#include "File.h"

class Directory
{
public:
    std::string name;

    Directory& findDirectory(const std::string& dirName);
    File& findFile(const std::string& fileName);
    void addFile(const File& file);
    void delFile(const File& file);
    void addDir(const Directory& dir);
    void delDir(const Directory& dir);
private:
    std::vector<Directory> children{};
    std::vector<File> files{};
};


#endif //OS4_DIRECTORY_H
