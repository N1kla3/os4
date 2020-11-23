//
// Created by nicolas on 21/11/2020.
//

#ifndef OS4_DIRECTORY_H
#define OS4_DIRECTORY_H


#include <vector>
#include <string>

class File;

class Directory
{
public:
    std::string name;

    File findDirectory(const std::string& dirName);
    Directory findFile(const std::string& fileName);
    void addFile(const File& file);
    void delFile(const File& file);
    void addDir(const Directory& dir);
    void delDir(const Directory& dir);
private:
    std::vector<Directory> childs;
    std::vector<File> files;
};


#endif //OS4_DIRECTORY_H
