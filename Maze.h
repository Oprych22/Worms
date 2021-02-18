#include <allegro.h>
#include <winalleg.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef _Maze_
#define _Maze_
class Maze
{
protected:
    int blockSize, viewport_x, viewport_y, viewport_h, viewport_w, fullsize_x, fullsize_y, frame, hole;
    BITMAP* blockBG;
    BITMAP*blockUp;
    BITMAP*blockUpDown;
    BITMAP*blockUpSide;
    BITMAP*block3Side;
    BITMAP*blockAllSide;
    BITMAP* ladder;
    vector<BITMAP*> basket;

public:
    Maze(int b, int x, int y, int h, int w, int fx, int fy);
    int getHeight();
    int getWidth();
    int blockSizeShow();
    void render(BITMAP*, int);
    int getViewX();
    int getViewY();
    void setViewX(int xx);
    void setViewY(int xx);
    int widthInPixels();
    int heightInPixels();
    void frameI();
    void holeDig(int, int);
    void wormInHole(int, int);
    void fillHole(int, int);
    void killWorm(int, int);
    void addLevel1();
    void addLevel2();
    void addLevel3();

    vector<string> maze;
};
#endif


