//
// Created by nicolas on 21/11/2020.
//

#include "Table.h"

Chunk* Table::getChunk(int addres)
{
    try
    {
        return table.at(addres);
    }
    catch (std::out_of_range&)
    {
        return nullptr;
    }
}

int Table::createChunk()
{
    auto ch(indexes);
    table.insert(indexes, ch);
    return indexes++;
}

void Table::delChunk(int addres)
{
    auto index = table.at(addres);
    if (!index->isLast)
    {
        delChunk(index->addres);
    }
    table.erase(addres);
}
