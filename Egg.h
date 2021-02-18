#include <allegro.h>
#include <iostream>
#include <string>
#include "Being.h"
#include "Player.h"

using namespace std;

#ifndef _Egg_
#define _Egg_
class Egg : public Being
{
protected:
    bool carried;
public:
    Egg(string, int, int, string, Maze*, int, int);
    bool caught(Player*);
    bool getCarried();
    void setCarried(bool);

};
#endif



