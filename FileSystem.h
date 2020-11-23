//
// Created by nicolas on 21/11/2020.
//
#pragma once

#ifndef OS4_FILESYSTEM_H
#define OS4_FILESYSTEM_H


#include "Directory.h"

class FileSystem
{
public:
    void run();

private:
    Directory root;
    Directory* current;
};


#endif //OS4_FILESYSTEM_H
