//
// Created by nicolas on 21/11/2020.
//

#include "Table.h"

Chunk& Table::getChunk(int addres)
{
    return Table::table.at(addres);
}

int Table::createChunk()
{
    Chunk ch(indexes);
    Table::table[indexes] = ch;
    return indexes++;
}

void Table::delChunk(int addres)
{
    auto index = Table::table.at(addres);
    if (!index.isLast)
    {
        delChunk(index.addres);
    }
    table.erase(addres);
}
