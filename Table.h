//
// Created by nicolas on 21/11/2020.
//
#pragma once

#ifndef OS4_TABLE_H
#define OS4_TABLE_H

#include <map>
#include <memory>

struct Chunk
{
    Chunk(int addres, int alloc) :
        addres(addres),
        copy(1),
        isLast(true)
    {

    }

    virtual ~Chunk()
    {

    }


    int addres;
    int copy;
    bool isLast;
    char* memory;

};

class Table
{
    static inline int indexes = 0;
    static std::map<int, Chunk*> table;
public:
    Table() = delete;

    static void delChunk(int addres);
    static Chunk* getChunk(int addres);
    static int createChunk();
};


#endif //OS4_TABLE_H
