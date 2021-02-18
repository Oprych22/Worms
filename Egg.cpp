#include "Egg.h"

Egg::Egg(string n, int x, int y, string fn, Maze* MazeIn, int ch, int cw)
     :Being(n, x, y, fn, MazeIn, ch, cw)
{
    carried = false;
}
bool Egg::getCarried()
{
    return carried;
}
void Egg::setCarried(bool b)
{
    carried = b;
}
bool Egg::caught(Player *h)
{

    double PlayerLeft = h->getX();
    double PlayerTop = h->getY();
    double PlayerBottom = PlayerTop + h->getHeight();
    double PlayerRight = PlayerLeft + h->getWidth();
    double eggRight = xpos + charW;
    double eggBottom = ypos + charH;

    if ((PlayerBottom > ypos && PlayerBottom < eggBottom) &&
       ((PlayerRight > xpos && PlayerRight < eggRight) ||
        (PlayerLeft < eggRight && PlayerLeft > xpos)))
    {
        return true;
    }
    if ((PlayerTop < eggBottom && PlayerTop > ypos) &&
       ((PlayerRight > xpos && PlayerRight < eggRight) ||
        (PlayerLeft < eggRight && PlayerLeft > xpos)))
    {
        return true;
    }
    return false;
};




