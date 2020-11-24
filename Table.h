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
    Chunk() = default;
    explicit Chunk(int addres) :
        addres(addres),
        copy(1),
        isLast(true)
    {

    }

    virtual ~Chunk()
    = default;

    int addres;
    int copy;
    bool isLast;
    char* memory{};
};

class Table
{
    static inline int indexes = 0;
    static inline std::map<int, std::unique_ptr<Chunk>> table{};
public:
    Table() = delete;

    static void delChunk(int addres);
    static std::unique_ptr<Chunk>& getChunk(int addres);
    static int createChunk();
};


#endif //OS4_TABLE_H
