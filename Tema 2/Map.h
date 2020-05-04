#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include "Location.h"

class Map
{
    int size_;
    char** data_;

    const char symbol_;
public:
    Map(int size, char symbol);
    ~Map();

    void MarkLocation(Location loc, char symbol);

    bool IsLocationMarked(Location loc) const;

    void Clear();

    bool ContainsLocation(Location loc) const;

    bool Treasure(Location loc) const;

    Location TLCorner() const;
    Location TRCorner() const;
    Location BLCorner() const;
    Location BRCorner() const;
    bool IsCorner(Location loc) const;

    Location RandomLocation();

    friend std::ostream& operator<<(std::ostream& out, const Map& map);
};

#endif // MAP_H_INCLUDED
