#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Map.h"

class Player {
protected:
    Location location_;
public:
    Player() { location_.x = location_.y = 0; }
    Player(Location location) : location_(location) { }
    Location location() const { return location_; }

    virtual bool Move(Map& map, int p) = 0; // p va fi pe post de numaurl rundei pentru a putea muta player-ul in functie de paritatea numarului rundei
    virtual ~Player() = 0;
};

class PlayerA : public Player {
public:
    using Player::Player;
    ~PlayerA();

    bool Move(Map& map, int p);
};

class PlayerB : public Player {
public:
    using Player::Player;
    ~PlayerB();

    bool Move(Map& map, int p);
};

class PlayerC : public Player {
public:
    using Player::Player;
    ~PlayerC();

    bool Move( Map& map, int p);
};

class PlayerD : public Player {
public:
    using Player::Player;
    ~PlayerD();

    bool Move(Map& map, int p);
};

#endif // PLAYER_H_INCLUDED
