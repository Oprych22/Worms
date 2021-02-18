#include "Maze.h"
Maze::Maze(int b, int x, int y, int h, int w, int fx, int fy)
{
    blockSize = b;
    viewport_x = x;
    viewport_y = y;
    viewport_h = h;
    viewport_w = w;
    fullsize_x= fx;
    fullsize_y = fy;
    frame = 0;
    hole =0;
    basket.push_back(load_bitmap("basket.bmp", NULL));
    basket.push_back(load_bitmap("basket1.bmp", NULL));
    basket.push_back(load_bitmap("basket2.bmp", NULL));
    basket.push_back(load_bitmap("basket3.bmp", NULL));
    basket.push_back(load_bitmap("basket4.bmp", NULL));
    basket.push_back(load_bitmap("basket5.bmp", NULL));
    basket.push_back(load_bitmap("basket6.bmp", NULL));
    basket.push_back(load_bitmap("basket7.bmp", NULL));
    basket.push_back(load_bitmap("basket8.bmp", NULL));
    basket.push_back(load_bitmap("basket9.bmp", NULL));
    basket.push_back(load_bitmap("basket10.bmp", NULL));
    basket.push_back(load_bitmap("basket11.bmp", NULL));
    blockBG=load_bitmap("block.bmp", NULL);
    blockUp=load_bitmap("block1.bmp", NULL);
    blockUpDown=load_bitmap("block2.bmp", NULL);
    blockUpSide=load_bitmap("block3.bmp", NULL);
    block3Side=load_bitmap("block4.bmp", NULL);
    blockAllSide=load_bitmap("block5.bmp", NULL);
    ladder=load_bitmap("Ladder.bmp", NULL);
}
void Maze::frameI()
{
    frame++;
}
void Maze::addLevel1()
{
    maze.push_back("X                                                        X");
    maze.push_back("X                                                        X");
    maze.push_back("X                                            Bb          X");
    maze.push_back("X                                L           bb          X");
    maze.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLXXXXXXXXXXXXXXXXXXXXXXXX");
    maze.push_back("X                    L           L                       X");
    maze.push_back("X              L     L    LXXXXXXL             L         X");
    maze.push_back("X       XXXXXXXL     L    L      L             L         X");
    maze.push_back("X    XX        L     XXXXXL      XXXXXXXXXXXXXXL         X");
    maze.push_back("X    L         LL         L                    L         X");
    maze.push_back("X  XXL     XXXXLXXL       L                    L         X");
    maze.push_back("X    L            L       LXXXXXXXXXXXXXXXXXXXXLXXXXXXXXXX");
    maze.push_back("X    L            L       L                    L         X");
    maze.push_back("X    L            L       L                    L         X");
    maze.push_back("X    L            XXXXXXXXLXXXXXXX             L         X");
    maze.push_back("X    L                    L                    LXXXXXXXXXX");
    maze.push_back("X    L                    L                    L         X");
    maze.push_back("X    LXXXXXXX  L     L    L      L             L         X");
    maze.push_back("X              LXXXXXL    L      LXXX                    X");
    maze.push_back("X              L     L    L      L                       X");
    maze.push_back("X              L     L    LXXXXXXL            XXXXX      X");
    maze.push_back("X           XXXL     L    L                       L      X");
    maze.push_back("X    XXXXX     L     XXXXXL              XXXXX   XL      X");
    maze.push_back("X    L         L          L            XX        XL      X");
    maze.push_back("X  XXL     XX  LXX        L                      XL      X");
    maze.push_back("X    L                    LXXXXXXXXXX            XXXXXXXXX");
    maze.push_back("X    L                    L                              X");
    maze.push_back("X    L                    L                              X");
    maze.push_back("XUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUX");
    maze.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
void Maze::addLevel2()
{
    maze.push_back("X                                                        X");
    maze.push_back("X                                                        X");
    maze.push_back("X                                            Bb          X");
    maze.push_back("X                                            bb          X");
    maze.push_back("XXXXXXXXXLLLLLLLLLL                        LXXXXXXXXXXXXXX");
    maze.push_back("X        L        XXXLXXXXXXXX             L             X");
    maze.push_back("X        L           L    LXXXXXX          L             X");
    maze.push_back("X        LXXXXXL     L                     L             X");
    maze.push_back("X    XX  L     L     LL          XXXXXXXXXXLXXXL         X");
    maze.push_back("X        L     LL     L                    L   L         X");
    maze.push_back("X  XXL   L XXXXLXXL   L                        L         X");
    maze.push_back("X    L   L        L   L    XXXLXXXXXXXXXXXXXXXXLXXXXXXXXXX");
    maze.push_back("X    LXXXL        L           L                L         X");
    maze.push_back("X    L            L           L                L         X");
    maze.push_back("X    L     XX     XXXXXXXX XXXLXXXL                      X");
    maze.push_back("X    L                            L       XXX   XXXXXXXXXX");
    maze.push_back("X    L                            L                      X");
    maze.push_back("X    LXXXXXXXL                    L      XXX             X");
    maze.push_back("X            L  XXXXXL           LXXX                    X");
    maze.push_back("X            L       L           L         XXX           X");
    maze.push_back("X            L       L    LXXXXXXL              XXX      X");
    maze.push_back("X           XXXL     L    L                              X");
    maze.push_back("X    XXXXX     L     XXXXXL              XXXXX   X       X");
    maze.push_back("X              L          L            XX        X       X");
    maze.push_back("X  XXLXXXX XX  LXX        L                      X XXXXX X");
    maze.push_back("X    L                    LXXXXXXXXXX                    X");
    maze.push_back("X    L         XXL        L                              X");
    maze.push_back("X    L           L        L                              X");
    maze.push_back("XUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUX");
    maze.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
void Maze::addLevel3()
{
    maze.push_back("X                                                        X");
    maze.push_back("X                                                        X");
    maze.push_back("X                          Bb                            X");
    maze.push_back("X                          bb                            X");
    maze.push_back("XXXXXXXXX                LXXXXXX                         X");
    maze.push_back("X                        L                               X");
    maze.push_back("X                        LLXXXXXXL                       X");
    maze.push_back("X        XXXXXXL         L       L                       X");
    maze.push_back("X    XX  L     L         L       LXXXXXXXXXLXXXL         X");
    maze.push_back("X        L     L         L                 L   L         X");
    maze.push_back("X  XXL   L XXXXLXXL      L          LXXXXXXX   L         X");
    maze.push_back("X    L   L        L      XXXXXL     L          XXXXLXXXXXX");
    maze.push_back("X    LXXXL        L           L     L          X   L     X");
    maze.push_back("X    L            L           L     LXXXXXL    X   L     X");
    maze.push_back("X    L     XX     XXXXXXX  XXXLXXXL       L        L     X");
    maze.push_back("X    L                            L      LXXX   XXXXXXXXXX");
    maze.push_back("X    L                 XXXXX      L      L               X");
    maze.push_back("X    LXXXXXXXL                    L      XXX             X");
    maze.push_back("X            L  XXXXXL           LXXX                    X");
    maze.push_back("X            L       L           L         XXX           X");
    maze.push_back("X            L       L    LXXXXXXL              XXX      X");
    maze.push_back("X           XXXL     L    L                              X");
    maze.push_back("X              L     XXXXXL              XXXXXL     XXX  X");
    maze.push_back("X      XXXX    L          L            XX     L          X");
    maze.push_back("X              L          L          XX       XXXXLXXXXXXX");
    maze.push_back("X  XXXXXX                 LXXXXXXXXXX             L      X");
    maze.push_back("X              XXL    XXXX                        L      X");
    maze.push_back("X                L                                L      X");
    maze.push_back("XUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUX");
    maze.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
int Maze::getHeight()
{
    return maze.size();
}
int Maze::heightInPixels()
{
    return maze.size() * blockSize;
}
int Maze::widthInPixels()
{
    return maze[0].length() * blockSize;
}
int Maze::getWidth()
{
    return maze[0].length();
}
int Maze::blockSizeShow()
{
    return blockSize;
}
void Maze::holeDig(int x, int y)
{

    if ((maze[y/blockSize][x/blockSize] == 'X'||
        maze[y/blockSize][x/blockSize] == 'U') &&
        hole > 1500)
    {
        maze[y/blockSize][x/blockSize] = 'x';
        hole = 0;
    }
}
void Maze::wormInHole(int x, int y)
{
    maze[y/blockSize][x/blockSize] = 'W';
}
void Maze::fillHole(int x, int y)
{
    if (maze[y/blockSize][x/blockSize] == 'W')
    {
        maze[y/blockSize][x/blockSize] = 'X';
    }
}
void Maze::killWorm(int x, int y)
{
    if (maze[y/blockSize][x/blockSize] == 'W')
    {
        maze[y/blockSize][x/blockSize] = 'D';
    }
}
/*
void Maze::render(BITMAP* b){

    for (int i=viewport_y/blockSize; i < fullsize_y/blockSize; i++) {
        for (int j=viewport_x/blockSize; j < fullsize_x/blockSize; j++) {
            if (maze[i][j] == 'X') {
                rectfill (b, (j*blockSize) - viewport_x, (i*blockSize) - viewport_y, ((j*blockSize) + blockSize) - viewport_x, ((i*blockSize) + blockSize) - viewport_y, makecol(0,0,255) );
            }
        }
    }
};

*/
void Maze::render(BITMAP* b,int  timePassed)
{
    hole += timePassed;
    for (int i=viewport_y/blockSize; i < fullsize_y/blockSize; i++)
    {
        for (int j=viewport_x/blockSize; j < fullsize_x/blockSize; j++)
        {
            if (maze[i][j] == 'X')
            {
               stretch_blit (blockBG, b, 0,0,32,32,(j*blockSize) - viewport_x,(i*blockSize) - viewport_y,blockSize,blockSize);
            }
            if (maze[i][j] == 'W')
            {
               stretch_blit (block3Side, b, 0,0,32,32,(j*blockSize) - viewport_x ,(i*blockSize) - viewport_y + (0.8*blockSize),blockSize,blockSize*0.2);
            }
            if (maze[i][j] == 'L')
            {
               masked_stretch_blit (ladder, b, 0,0,32,32,(j*blockSize) - viewport_x,(i*blockSize) - viewport_y,blockSize,blockSize);
            }
            if (maze[i][j] == 'B')
            {
               masked_stretch_blit (basket[frame], b, 0,0,152,128,(j*blockSize) - viewport_x,(i*blockSize) - viewport_y,blockSize*2,blockSize*2);
            }
            if (maze[i][j] == 'U')
            {
               stretch_blit (blockUp, b, 0,0,32,32,(j*blockSize) - viewport_x,(i*blockSize) - viewport_y,blockSize,blockSize);
            }
            if (maze[i][j] == 'T')
            {
               stretch_blit (block3Side, b, 0,0,32,32,(j*blockSize) - viewport_x,(i*blockSize) - viewport_y,blockSize,blockSize);
            }
            if (maze[i][j] == 'x')
            {
               stretch_blit (block3Side, b, 0,0,32,32,(j*blockSize) - viewport_x ,(i*blockSize) - viewport_y + (0.8*blockSize),blockSize,blockSize*0.2);
            }
            if (maze[i][j] == 'R')
            {
               rotate_sprite ( b, blockUp, (j*blockSize) - viewport_x ,(i*blockSize) - viewport_y , 128);
            }
            if (maze[i][j] == 'D')
            {
               rectfill (b, (j*blockSize) - viewport_x, (i*blockSize) - viewport_y, ((j*blockSize) + blockSize) - viewport_x, ((i*blockSize) + blockSize) - viewport_y-3, makecol(255,0,0) );
               stretch_blit (block3Side, b, 0,0,32,32,(j*blockSize) - viewport_x ,(i*blockSize) - viewport_y + (0.8*blockSize),blockSize,blockSize*0.2);
            }
        }
    }
}
void Maze::setViewX(int xx)
{
    viewport_x = xx;
}
void Maze::setViewY(int yy)
{
    viewport_y = yy;
}
int Maze::getViewX()
{
    return viewport_x;
}
int Maze::getViewY()
{
    return viewport_y;
}


