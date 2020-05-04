#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"

using namespace std;

//class Player;

class Game {
    Map map_;
    PlayerA pa_;
    PlayerB pb_;
    PlayerC pc_;
    PlayerD pd_;

    vector <Location> treasures_;
    int round_;
public:
    Game();
    ~Game();
    void GenerateTreasures();
    void RunRound(bool &a, bool &b, bool &c, bool &d);
    void Afis() const;
    void Run(int numRounds);
};

#endif /* GAME_H */
