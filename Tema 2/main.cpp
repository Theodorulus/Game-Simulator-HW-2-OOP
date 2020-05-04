/*#include <iostream>
#include <ctime>

#include "Game.h"

int main(int argc, const char* argv[]) {
    srand(time(NULL));
    Game game;
    game.Run(1);
    game.Run(4);
    return 0;
}*/


#include <iostream>
#include "Game.h"
#include <time.h>

using namespace std;

int main()
{
    /*Location l;
    l.x = 4;
    l.y = 4;
    cout << l << endl;
   
    Map m(5,'0');
    m.MarkLocation(l,'A');
    cout << m;
    cout << m.IsLocationMarked(l)<<endl;
    Location l1;
    l1.x = 0;
    l1.y = 0;
    cout << m.IsLocationMarked(l1) << endl;
    m.Clear();
    cout << m;
    Location l2;
    l2.x = 10;
    l2.y = 1;
    cout << m.ContainsLocation(l) << endl;
    cout << m.ContainsLocation(l2) << endl;
    cout << m.RandomLocation() << endl;
    m.MarkLocation(l1, 'T');
    cout << m;
    cout << m.TLCorner();
    cout << m.TRCorner();
    cout << m.BLCorner();
    cout << m.BRCorner();
    cout << endl;*/
    srand(time(NULL));
    Game game;
    game.Run();
    return 0;
}