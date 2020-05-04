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

void Game::Afis() const
{
    cout << map_;
    /*cout << pa_.location() << pb_.location() << pc_.location() << pd_.location() << endl;
    if(treasures_.size())
        cout << "Comori ramase la locatiile: ";
    for (int i = 0; i < treasures_.size(); i++)
        cout << treasures_[i];*/
    cout << endl;
}

void Game::Run(int numRounds=-1)
{
    GenerateTreasures();
    cout << "Harta initiala: " << endl;
    Afis();
    bool a = 0, b = 0, c = 0, d = 0; // variabile care stabilesc daca playerii au gasit comoara sau nu pentru a sti daca se mai afla pe harta sau nu.
    Location loca = pa_.location(), locb = pb_.location(), locc = pc_.location(), locd = pd_.location(); // variabile care vor ajuta sa numere cate runde la rand un player a stat nemiscat
    int nra = 0, nrb = 0, nrc = 0, nrd = 0;
    while (treasures_.size() && (nra < 3 || nrb < 3 || nrc < 3 || nrd < 3) && (numRounds > 0 || numRounds == -1)) // daca au fost gasite toate comorile SAU daca niciun player dintre cei ramasi 
    {                                                                                                             // pe harta nu s-a mai miscat de 3 runde SAU numarul de runde a fost limitat
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
        if(numRounds != -1)
            numRounds--;
    }
    if (treasures_.size() && numRounds != 0)
        cout << "Simularea a fost incheiata deoarece nu au fost gasite toate comorile.";
    else
        if(!treasures_.size())
            cout << "Toate comorile au fost gasite.";
}

