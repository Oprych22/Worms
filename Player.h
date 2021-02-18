#include <allegro.h>
#include <iostream>
#include <string>
#include "Being.h"

using namespace std;

#ifndef _Player_
#define _Player_
class Player : public Being
{
protected:
    int lives, life;
    double score;
    bool gotEgg;

public:
    Player(string, int, int, int, int, string, Maze*, int, int);
    int livesLeft();
    void livesLost();
    void setLife(int);
    int getLife();
    void takeLife(int);
    bool getEgg();
    void setEgg(bool);
};
#endif


