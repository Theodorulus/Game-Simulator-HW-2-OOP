#include "Map.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

Map::Map(int size, char symbol) : size_(size), symbol_(symbol)
{
    data_ = new char* [size_];
    for (int i = 0; i < size_; i++)
    {
        data_[i] = new char[size_];
        for (int j = 0; j < size_; j++)
        {
            data_[i][j] = symbol;
        }
    }
}

void Map::MarkLocation(Location loc, char symbol)
{
    assert(symbol != symbol_);
    data_[loc.y][loc.x] = symbol;
}

bool Map::IsLocationMarked(Location loc) const
{
    return data_[loc.y][loc.x] != symbol_ && data_[loc.y][loc.x] != 'T';
}

void Map::Clear() {
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            data_[i][j] = symbol_;
        }
    }
}

Map::~Map() {
    for (int i = 0; i < size_; i++) {
        delete[] data_[i];
    }
    delete[] data_;
}

bool Map::ContainsLocation(Location loc) const
{
    return loc.x >= 0 && loc.x < size_&& loc.y >= 0 && loc.y < size_;
}

bool Map::Treasure(Location loc) const
{
    return data_[loc.y][loc.x] == 'T';
}

Location Map::TLCorner() const
{
    Location loc;
    loc.x = 0;
    loc.y = 0;
    return loc;
}

Location Map::TRCorner() const
{
    Location loc;
    loc.x = size_ - 1;
    loc.y = 0;
    return loc;
}

Location Map::BLCorner() const
{
    Location loc;
    loc.x = 0;
    loc.y = size_ - 1;
    return loc;
}

Location Map::BRCorner() const
{
    Location loc;
    loc.x = size_ - 1;
    loc.y = size_ - 1;
    return loc;
}

bool Map::IsCorner(Location loc) const
{
    return ((loc.x == 0 && loc.y == 0) || (loc.x == 0 && loc.y == size_ - 1) || (loc.x == size_ - 1 && loc.y == 0) || (loc.x == size_ - 1 && loc.y == size_ - 1));
}

Location Map::RandomLocation()
{
    Location l;
    l.x = rand() % size_;
    l.y = rand() % size_;
    return l;
}

std::ostream& operator<<(std::ostream& out, const Map& map)
{
    for (int i = 0; i < map.size_; i++)
    {
        for (int j = 0; j < map.size_; j++)
        {
            out << map.data_[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
