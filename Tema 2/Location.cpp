#include "Location.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const Location loc)
{
    out << "(" << loc.y + 1 << "," << loc.x + 1 << ")";
    return out;
}

bool operator==(Location l1, Location l2)
{
    return ((l1.x == l2.x) && (l1.y == l2.y));
}

bool operator!=(Location l1, Location l2)
{
    return !(l1 == l2);
}

