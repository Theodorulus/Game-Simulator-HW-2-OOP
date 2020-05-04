#include <iostream>
#include "Game.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    Game game;
    int numRounds;
    cout << "Instructiuni:\n";
    cout << "Casutele neexplorate de pe harta vor fi marcate cu '-'.\nCasutele explorate deja de un cautator de comori vor fi marcate cu '*'.\n";
    cout << "Casutele marcate cu T arata faptul ca acolo se afla o comoara.\n";
    cout << "Casutele marcate cu A / B / C / D arata faptul ca acolo se afla playerul A / respectiv B / respectiv C / respectiv D in runda curenta.\n\n";
    cout << "Cate runde doresti sa fie jucate? (Pentru a simula pana cand se termina jocul, scrie 0) ";
    cin >> numRounds;
    if (numRounds == 0)
        numRounds = -1;
    game.Run(numRounds);
    return 0;
}