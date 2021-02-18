#include <allegro.h>
#include <iostream>
#include <string>
#include "Being.h"
#include "Player.h"

using namespace std;


#ifndef _Worm_
#define _Worm_

class Worm : public Being
{
private:
    bool moving, buried;
    Maze* ar1;
    int timeToWake, unstuck;

public:
    Worm(string, int, int, string, Maze*, int, int);
    void chase(Player*, int timePassed);
    bool eaten(Player*);
    bool isMoving();
    //Worm spawn(int, int, vector <Worm*>);
    void patrol2(int, Maze*);
    bool isBlocked(int, int, Maze*);
    bool isHole(int,int,Maze*);
    bool getBuried(int, int);
 //   Worm spawn(int, int);
};
#endif

