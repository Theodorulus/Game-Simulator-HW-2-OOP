#include "Game.h"
#include <iostream>

using namespace std;

Game::~Game() {

}

Game::Game() : map_(15, '-'), round_(0), pa_(map_.TLCorner()), pb_(map_.TRCorner()), pc_(map_.BRCorner()), pd_(map_.BLCorner())
{
    map_.MarkLocation(map_.TLCorner(), 'A');
    map_.MarkLocation(map_.TRCorner(), 'B');
    map_.MarkLocation(map_.BRCorner(), 'C');
    map_.MarkLocation(map_.BLCorner(), 'D');
}

void Game::GenerateTreasures()
{
    int nr = 0;
    Location loc;
    while(nr < 3)
    {
        loc = map_.RandomLocation();
        if (!map_.IsCorner(loc))
        {
            map_.MarkLocation(loc, 'T');
            treasures_.push_back(loc);
            nr++;
        }
    }
}

void Game::RunRound(bool &a, bool &b, bool &c, bool &d)
{
    round_++;
    cout << "Runda " << round_ << endl;
    bool agas, bgas, cgas, dgas;
    if(!a)
        agas = pa_.Move(map_, round_);
    if(!b)
        bgas = pb_.Move(map_, round_);
    if(!c)
        cgas = pc_.Move(map_, round_);
    if(!d)
        dgas = pd_.Move(map_, round_);
    
    if (!a && agas)
    {
        cout << "PlayerA a gasit comoara la " << pa_.location() << endl;
        vector<Location>::iterator it;
        it = find(treasures_.begin(), treasures_.end(), pa_.location());
        treasures_.erase(it);
        a = 1;
        map_.MarkLocation(pa_.location(),'*');
    }
    if (!b && bgas)
    {
        cout << "PlayerB a gasit comoara la " << pb_.location() << endl;
        vector<Location>::iterator it;
        it = find(treasures_.begin(), treasures_.end(), pb_.location());
        treasures_.erase(it);
        b = 1;
        map_.MarkLocation(pb_.location(), '*');
    }
    if (!c && cgas)
    {
        cout << "PlayerC a gasit comoara la " << pc_.location() << endl;
        vector<Location>::iterator it;
        it = find(treasures_.begin(), treasures_.end(), pc_.location());
        treasures_.erase(it);
        c = 1;
        map_.MarkLocation(pc_.location(), '*');
    }
    if (!d && dgas)
    {
        cout << "PlayerD a gasit comoara la " << pd_.location() << endl;
        vector<Location>::iterator it;
        it = find(treasures_.begin(), treasures_.end(), pd_.location());
        treasures_.erase(it);
        d = 1;
        map_.MarkLocation(pd_.location(), '*');
    }
    Afis();
}

void Game::Afis()
{
    cout << map_;
    //cout << pa_.location() << pb_.location() << pc_.location() << pd_.location() << endl;
    if(treasures_.size())
        cout << "Comori ramase la locatiile: ";
    for (int i = 0; i < treasures_.size(); i++)
        cout << treasures_[i];
    cout << endl;
}

void Game::Run()
{
    GenerateTreasures();
    bool a = 0, b = 0, c = 0, d = 0;
    Location loca = pa_.location(), locb = pb_.location(), locc = pc_.location(), locd = pd_.location();
    int nra = 0, nrb = 0, nrc = 0, nrd = 0;
    while (treasures_.size() && (nra < 3 || nrb < 3 || nrc < 3 || nrd < 3))
    {
        RunRound(a, b, c, d);
        if (!a)
            if (loca == pa_.location())
                nra++;
            else
                nra = 0;
        else
            nra = 3;
        if (!b)
            if (locb == pb_.location())
                nrb++;
            else
                nrb = 0;
        else
            nrb = 3;
        if (!c)
            if (locc == pc_.location())
                nrc++;
            else
                nrc = 0;
        else
            nrc = 3;
        if (!d)
            if (locd == pd_.location())
                nrd++;
            else
                nrd = 0;
        else
            nrd = 3;
        loca = pa_.location();
        locb = pb_.location();
        locc = pc_.location();
        locd = pd_.location();
    }
}
/*
void Game::Run(int numRounds) {
    for (int i = 0; i < numRounds; i++) {
        bool hadMovement = false;

        ++round_;
        cout << "Round " << round_ << endl;

        map_.Clear();

        for (int j = 0; j < players_.size(); j++) {
            Player* player = players_[j];
            Location fromLocation = player->location();
            player->Move(map_);
            Location toLocation = player->location();

            map_.MarkLocation(toLocation, '*');

            if (fromLocation != toLocation) {
                hadMovement = true;
                cout << "Player" << j + 1 << " moved from " << fromLocation << " to " << toLocation << endl;
            }
        }

        cout << "Map" << endl;
        cout << map_;

        if (!hadMovement) {
            cout << "Nobody moved" << endl;
            break;
        }
    }
}*/
