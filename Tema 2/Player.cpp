#include "Player.h"
#include <iostream>

Player::~Player() 
{

}

bool PlayerA::Move(Map &map, int p)
{
    bool ok = 0;
    Location init = location_;
    Location location = location_;
    location.x += 1;
    location.y += 1;
    if (map.ContainsLocation(location))
    {
        if (map.Treasure(location))
            ok = 1;
        location_ = location;
    }
    if (location_ != init)
    {
        map.MarkLocation(init, '*');
        map.MarkLocation(location_, 'A');
    }
    return ok;
}

PlayerA::~PlayerA()
{

}

PlayerB::~PlayerB()
{

}

bool PlayerB::Move(Map &map, int p) 
{
    bool ok = 0;
    Location init = location_;
    Location location = location_;
    location.y += 1;
    if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
    {
        if (map.Treasure(location))
            ok = 1;
        location_ = location;
    }
    else
    {
        location = location_;
        location.x -= 1;
        if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
        {
            if (map.Treasure(location))
                ok = 1;
            location_ = location;
        }
        else
        {
            location = location_;
            location.y -= 1;
            if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
            {
                if (map.Treasure(location))
                    ok = 1;
                location_ = location;
            }
            else
            {
                location = location_;
                location.x += 1;
                if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
                {
                    if (map.Treasure(location))
                        ok = 1;
                    location_ = location;
                }
            }
        }
    }
    if (location_ != init)
    {
        map.MarkLocation(init, '*');
        map.MarkLocation(location_, 'B');
    }
    return ok;
}

PlayerC::~PlayerC()
{

}

bool PlayerC::Move(Map& map, int p) 
{
    bool ok = 0;
    Location init = location_;
    Location location = location_;
    if (p % 2)
    {
        location.x -= 1;
        location.y -= 1;
    }
    else
    {
        location.x += 1;
        location.y -= 1;
    }
    if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
    {
        if (map.Treasure(location))
            ok = 1;
        location_ = location;
    }
    else
    {
        location = location_;
        if (p % 2)
        {
            location.y += 1;
        }
        else
        {
            location.x -= 1;
        }
        if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
        {
            if (map.Treasure(location))
                ok = 1;
            location_ = location;
        }
    }
    if (location_ != init)
    {
        map.MarkLocation(init, '*');
        map.MarkLocation(location_, 'C');
    }
    return ok;
}

PlayerD::~PlayerD()
{

}

bool PlayerD::Move(Map& map, int p)
{
    bool ok = 0;
    Location init = location_;
    Location location = location_;
    if (p % 2)
    {
        location.x += 1;
    }
    else
    {
        location.y -= 1;
    }
    if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
    {
        if (map.Treasure(location))
            ok = 1;
        location_ = location;
    }
    else
    {
        location = location_;
        if (p % 2)
        {
            location.x -= 1;
        }
        else
        {
            location.y -= 1;
        }
        if (map.ContainsLocation(location) && !map.IsLocationMarked(location))
        {
            if (map.Treasure(location))
                ok = 1;
            location_ = location;
        }
    }
    if (location_ != init)
    {
        map.MarkLocation(init, '*');
        map.MarkLocation(location_, 'D');
    }
    return ok;
}


