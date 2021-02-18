#include "Worm.h"

Worm::Worm(string n, int x, int y, string fn, Maze* MazeIn, int ch, int cw)
        :Being(n, x, y, fn, MazeIn, cw, ch)
{
    unstuck = 0;
    moving = false;
    ar1 = MazeIn;
    name = n;
    buried = false;
    timeToWake= 0;
    charH = cw;
    charW = cw;
}
void Worm::chase(Player *h, int timePassed)
{
    if (h->getX() < xpos)
    {
        moveLeft(timePassed);
    }
    if (h->getY() < ypos)
    {
        moveUp(timePassed);
    }
    if (h->getX() > xpos)
    {
        moveRight(timePassed);
    }
    if (h->getY() > ypos)
    {
        moveDown(timePassed);
    }
}
bool Worm::isMoving()
{
    return moving;
}
bool Worm::isBlocked(int x ,int y, Maze* Maze)
{
    if(Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'X' ||
       Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'U' ||
       Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'T' ||
       Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'W'  ||
    Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'D')
    {
        return true;
    }
    return false;
}
bool Worm::isHole(int x ,int y, Maze* Maze)
{
    if(Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'x')
    {
        return true;
    }
    return false;
}
/*
Worm Worm::spawn(int mx, int my, vector <Worm*> worms)
{
    srand((unsigned)time(0));
    int randomX, randomY;
    int highestX = (ar1->getWidth() * ar1->blockSizeShow()) - mx;
    int highestY = (ar1->getHeight() * ar1->blockSizeShow()) - my;
    int rangeX=(highestX-mx)+1;
    int rangeY=(highestY-my)+1;

    randomX = mx+int(rangeX*rand()/(RAND_MAX + 1.0));
    cout << randomX << endl;
    randomY = my+int(rangeY*rand()/(RAND_MAX + 1.0));
    cout << randomY << endl;

    if (!isBlocked(randomX, randomY, ar1) &&
        !isBlocked(randomX+32, randomY, ar1) &&
        !isBlocked(randomX, randomY + 32, ar1) &&
        !isBlocked(randomX+32, randomY + 32, ar1))
    {
        return Worm("Worm", randomX, randomY, "worm1.bmp", ar1, 32, 32);
    } else {
        spawn(mx, my, worms);
    }
}
*/

void Worm::patrol2(int time, Maze* Maze)
{
    /*
    unstuck+= time;
    if (xVelocity == 0 && unstuck > 20 && yVelocity == 0)
    {
        ypos -= 4;
        xpos -= 4;
        unstuck = 0;
    }
    */
    if (isBlocked(xpos + charW, ypos+charH+2, ar1) ||
        isBlocked(xpos  , ypos+charH+2, ar1) ||
        isBlocked(xpos + (charW*0.5) , ypos+charH+2, ar1) ||
        buried)
    {
        yVelocity = 0;
        if (!moving)
        {
            if (!isBlocked(xpos-3, ypos + (yVelocity), ar1) &&
                (isBlocked(xpos-3, ypos + (yVelocity)+charH+2, ar1) ||
                 isHole(xpos-3, ypos + (yVelocity)+charH+2, ar1)))
            {
                if(xVelocity > -0.3)
                {
                    xVelocity -=0.1;
                }
                else if (isHole(xpos+charW-5, ypos+ charH+2, ar1))
                {
                    setXVelocity(0);
                    ypos +=30;
                    buried = true;
                    Maze->wormInHole(xpos+(charW*0.5), ypos+(charH*0.5));
                }
            }
            else
            {
                moving = true;
            }
        }
        else if (moving)
        {
            if (!isBlocked(xpos+charW+3, ypos + (yVelocity), ar1) &&
                 (isBlocked(xpos+charW+3, ypos + (yVelocity)+charH+2, ar1) ||
                 isHole(xpos+charW+3, ypos + (yVelocity)+charH+2, ar1)))
               {
                if(xVelocity < 0.3)
                {
                    xVelocity +=0.1;
                }
                else if (isHole(xpos+3, ypos+ charH+2, ar1))
                {
                    setXVelocity(0);
                    ypos +=30;
                    buried = true;
                    Maze->wormInHole(xpos+(charW*0.5), ypos+(charH*0.5));
                }
            }
            else
            {
                moving = false;
            }
        }

    }
    if (buried)
    {
        timeToWake += time;
        if (timeToWake > 4500)
        {
            ypos-=30;
            buried = false;
            Maze->fillHole(xpos+15, ypos+37);
            patrol2(time, Maze);
            timeToWake = 0;
        }
    }
}

bool Worm::getBuried(int x, int y)
{
    if (buried && ((x>xpos && x<xpos+charW) && (y>ypos && y<ypos+charH)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Worm::eaten(Player *h)
{
    double PlayerLeft = h->getX();
    double PlayerTop = h->getY();
    double PlayerBottom = PlayerTop + h->getHeight();
    double PlayerRight = PlayerLeft + h->getWidth();
    double WormRight = xpos + charW;
    double WormBottom = ypos + charH;

        if (!buried &&
            (PlayerBottom > ypos && PlayerBottom < WormBottom) &&
           ((PlayerRight > xpos && PlayerRight < WormRight) ||
            (PlayerLeft < WormRight && PlayerLeft > xpos)))
        {
            return true;
        }
        if ( !buried &&
            (PlayerTop < WormBottom && PlayerTop > ypos) &&
           ((PlayerRight > xpos && PlayerRight < WormRight) ||
            (PlayerLeft < WormRight && PlayerLeft > xpos)))
        {
            return true;
        }
    return false;
};

