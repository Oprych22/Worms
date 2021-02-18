#include <allegro.h>
#include <winalleg.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "Maze.h"

using namespace std;

#ifndef _Being_
#define _Being_
class Being
{
protected:
    string name;
    int cur_frame, frame, animCharCounter, charH, charW;
    vector<BITMAP*> bmp;
    BITMAP* climbingFrame;
    double xVelocity, yVelocity;
    double xpos, ypos;
    BITMAP *saved;
    Maze* aPointer;
    bool climbing;

public:
    Being (string n, double x, double y, string fn, Maze* MazeIn, int, int);
    ~Being();
    void print();
    void move(int time, Maze* ar1);
    void jump(Maze*);
    double moveUp(int timePassed);
    double moveLeft(int timePassed);
    double moveDown(int timePassed);
    double moveRight(int timePassed);
    void stopH();
    void stopV();
    double getX();
    double getY();
    int getHeight();
    int getWidth();
    bool getClimbing();
    void setY(int y);
    void setX(int x);
    void display();
    void draw(BITMAP*, int vpx, int vpy, double timePassed);
    void addFrame(string fn);
    bool isBlocked(int x, int y, Maze* Maze);
    bool isLadder(int x, int y, Maze* Maze);
    bool isBasket(int x, int y, Maze* Maze);
    void setYVelocity(int yVel);
    void setXVelocity(int xVel);
    double getYVelocity();
    double getXVelocity();
};
#endif

