#include "Being.h"
Being::Being(string n, double x, double y, string fn, Maze* mazeIn, int ch, int cw)
{
    name=n;
    xpos=x;
    ypos=y;
    bmp.push_back(load_bitmap(fn.c_str(), NULL));
    cur_frame = 0;
    xVelocity = 0;
    yVelocity = 0;
    aPointer = mazeIn;
    animCharCounter = 0;
    frame = 0;
    climbing = false;
    climbingFrame=load_bitmap("Player5.bmp", NULL);
    charH=ch;
    charW=cw;
}


void Being::print()
{
    cout << "Name: " << name << endl;
    cout << "X Position: " << xpos << endl;
    cout << "Y Position: " << ypos << endl;
}
void Being::display()
{
    cout << cur_frame;
}
bool Being::getClimbing(){
    return climbing;
}
void Being::move(int time, Maze* ar1){

    if (isLadder(xpos, ypos + (yVelocity * time), ar1) ||
        isLadder(xpos + charW, ypos + (yVelocity * time), ar1) ||
        isLadder(xpos, ypos  + (yVelocity * time)+ charH+1, ar1) ||
        isLadder(xpos + charW, ypos + (yVelocity * time) + charH+1, ar1))
        {
            climbing = true;
            if (yVelocity < 0)
            {
                yVelocity -=0.15;
            }
        }
        else
        {
            climbing = false;
        }

    if (yVelocity < 0)
    {
        if(!isBlocked(xpos, ypos + (yVelocity * time), ar1) &&
           !isBlocked(xpos + charW, ypos + (yVelocity * time), ar1) &&
           !isBlocked(xpos, ypos + (yVelocity * time)-1, ar1) &&
           !isBlocked(xpos + charW, ypos + (yVelocity * time)-1, ar1))
        {
            ypos += yVelocity * time;
            if (yVelocity  <  0.6)
                yVelocity +=0.15;
        }
        else
        {
            yVelocity = 0;
        }
    }
    else if (yVelocity >= 0)
    {
        if ((!isBlocked(xpos, ypos + (yVelocity * time)-1, ar1) &&
            !isBlocked(xpos + charW, ypos + (yVelocity * time)-1, ar1) ||
            !isBlocked(xpos, ypos + (yVelocity * time), ar1) &&
            !isBlocked(xpos + charW, ypos + (yVelocity * time), ar1)) &&
            !isBlocked(xpos + charW, ypos + (yVelocity * time) + charH, ar1) &&
            !isBlocked(xpos, ypos + (yVelocity * time) + charH, ar1))
        {

            ypos += yVelocity * time;
            if (yVelocity  <  0.6)
                yVelocity +=0.15;
        }
        else
        {
            yVelocity = 0;
        }
    }
        if(xVelocity > 0 || xVelocity < 0)
    	{
    		if (!isBlocked(xpos + (xVelocity * time), ypos, ar1) &&
                !isBlocked(xpos + (xVelocity * time) + charW-1, ypos, ar1) &&
    			!isBlocked(xpos + (xVelocity * time) , ypos + charH, ar1) &&
    			!isBlocked(xpos + (xVelocity * time) + charW-1, ypos + charH, ar1))
    		{

    			xpos += xVelocity * time;
    		}
    		else
    		{
	    	    xVelocity = 0;
	    	}
        }
}
void Being::jump(Maze* aPointer)
{
    if (isBlocked(xpos + charW, ypos + charH+3, aPointer) ||
        isBlocked(xpos     , ypos +  charH+3, aPointer) )
        yVelocity = -0.8;
    else if ((isLadder(xpos, ypos + charH, aPointer) ||
             isLadder(xpos + charW, ypos  +charH, aPointer)) &!
             (isLadder(xpos, ypos + charH-4, aPointer) ||
             isLadder(xpos + charW-1, ypos  + charH-4, aPointer)))
        yVelocity = -0.8;
}
double Being::moveUp(int timePassed)
{
    if(yVelocity > -0.18 && climbing)
     {
          yVelocity -=0.18;
     }
     return yVelocity;
}
double Being::moveDown(int timePassed)
{
    if(yVelocity < 0.1 && climbing)
     {
          yVelocity +=0.1;
     }
     return yVelocity;
}
double Being::moveLeft(int timePassed)
{

    if(xVelocity > -0.4)
     {
          xVelocity -=0.1;
     }
     return xVelocity;
}
double Being::moveRight(int timePassed)
{
    if(xVelocity < 0.4)
     {
          xVelocity +=0.1;
     }
     return xVelocity;
}
void Being::stopH()
{
    xVelocity = 0;
}
void Being::stopV()
{
    yVelocity = 0;
}
void Being::setYVelocity(int yVel)
{
    yVelocity = yVel;
}
void Being::setXVelocity(int xVel)
{
    xVelocity = xVel;
}
double Being::getY()
{
    return ypos;
}
double Being::getX()
{
    return xpos;
}
void Being::setX(int x)
{
    xpos = x;
}
void Being::setY(int y)
{
    ypos = y;
}
Being::~Being()
{
    for (unsigned int i=0; i > bmp.size();i++)
    {
        destroy_bitmap(bmp[i]);
    }
}
void Being::draw(BITMAP* surface,int vpx, int vpy, double timePassed)
{
        animCharCounter += timePassed;
        if ( animCharCounter > 160 && (xVelocity != 0 ||(yVelocity !=0 && climbing)))
        {
            frame = (cur_frame + 1) % bmp.size();
            animCharCounter = 0;
        }
        if (xVelocity >= 0)
        {
            stretch_sprite(surface,bmp[frame],xpos-vpx,ypos-vpy, charW, charH);
            /*
            rectfill (surface, xpos-vpx, ypos-vpy, xpos-vpx+1, ypos-vpy+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx+charW-1, ypos-vpy, xpos-vpx+charW, ypos-vpy+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx, ypos-vpy+charH-1, xpos-vpx+1, ypos-vpy+charH+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx+charW-1, ypos-vpy+charH-1, xpos-vpx+charW, ypos-vpy+charH, makecol(0,0,0) );
            */
        }
        else if (xVelocity < 0)
        {
            BITMAP * temp = create_bitmap(charW, charH);
            clear_to_color(temp,makecol(255,0,255));
            masked_stretch_blit( bmp[frame], temp, 0, 0, bmp[frame]->w, bmp[frame]->h,0,0, charW, charH);
            draw_sprite_h_flip(surface, temp, xpos-vpx, ypos-vpy);
            /*
            rectfill (surface, xpos-vpx, ypos-vpy, xpos-vpx+1, ypos-vpy+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx+charW, ypos-vpy, xpos-vpx+charW+1, ypos-vpy+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx, ypos-vpy+charH, xpos-vpx+1, ypos-vpy+charH+1, makecol(0,0,0) );
            rectfill (surface, xpos-vpx+charW, ypos-vpy+charH, xpos-vpx+charW+1, ypos-vpy+charH+1, makecol(0,0,0) );
            */
        }
        cur_frame = frame;
}
void Being::addFrame(string fn)
{
    bmp.push_back(load_bitmap(fn.c_str(), NULL));
}
double Being::getXVelocity()
{
    return xVelocity;
}
double Being::getYVelocity()
{
    return yVelocity;
}
int Being::getHeight()
{
    return charH;
}
int Being::getWidth()
{
    return charW;
}
bool Being::isLadder(int x ,int y, Maze* Maze)
{

    if(Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'L')
    {
        return true;
    }
    return false;
}
bool Being::isBasket(int x ,int y, Maze* Maze)
{

    if(Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'B' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'b')
    {
        return true;
    }
    return false;
}
bool Being::isBlocked(int x ,int y, Maze* Maze)
{
    if (Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'W' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'X' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'U' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'T' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'x' ||
        Maze->maze[y/Maze->blockSizeShow()][x/Maze->blockSizeShow()] == 'D')
    {
        return true;
    }
    return false;
};






