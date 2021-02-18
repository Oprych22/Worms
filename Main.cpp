#include <allegro.h>
#include <winalleg.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Being.h"
#include "Worm.h"
#include "Player.h"
#include "Maze.h"
#include "Egg.h"

#define WIDTH 1972
#define HEIGHT 1020
#define VPH 600
#define VPW 800

int main()
{
    int prevTime = GetTickCount();
    int currentTime = 0, levelTime = 0, timePassed = 0;
    srand((unsigned)time(0));
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    int vpx = 0;
    int vpy = 0;
    bool levelComplete = true;
    bool dead = false;
    int level = -1, levelNo = 0;
    int wormAmount = 25;
    int eggAmount = 5;
    int lives = 3;
    int newTimer, timerTry = 0;

    set_gfx_mode(GFX_AUTODETECT_WINDOWED,VPW,VPH,0,0);
    clear_to_color(screen,makecol(255,255,255));

    vector<Maze *> levels;
    vector<Worm *> worms;
    vector<Egg *> eggs;
    vector<int> xPos;
    vector<int> yPos;
    Player* cr1;
    int die = 0;

    levels.push_back(new Maze(WIDTH/58, vpx, vpy, VPH, VPW, WIDTH, HEIGHT));
    levels.push_back(new Maze(WIDTH/58, vpx, vpy, VPH, VPW, WIDTH, HEIGHT));
    levels.push_back(new Maze(WIDTH/58, vpx, vpy, VPH, VPW, WIDTH, HEIGHT));

    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *bg=load_bitmap("backbackground.bmp",NULL);
    BITMAP *bg2=load_bitmap("Background3.bmp",NULL);
    BITMAP *start =load_bitmap("start.bmp", NULL);
    BITMAP *bg4=load_bitmap("foreground2.bmp", NULL);
    BITMAP* egg=load_bitmap("egg.bmp", NULL);
    BITMAP* newPlayer=load_bitmap("man3.bmp", NULL);

    levels[0]->addLevel1();
    levels[1]->addLevel2();
    levels[2]->addLevel3();

    while (!key[KEY_ENTER])
    {
        blit (start, buffer, 0, 0, 0 , 0 , WIDTH, HEIGHT);
        //textout_centre_ex(buffer, font, "Press S to start saving the world!", 400, 400,makecol(255, 0, 255), -1);
        blit (buffer,screen,0,0,0,0,screen->w,screen->h);
    }
        while (!key[KEY_ESC])
        {
            if (levelComplete)
            {
                levelNo++;
                newTimer = 180;
                levels.erase(levels.begin() + level);
                while (levelTime < 200)
                {
                    clear_to_color(buffer, makecol(0, 0, 0));
                    textprintf_centre_ex(buffer, font, 400, 300,
                                        makecol(0, 100, 243), -1,
                                        "Level: %d",
                                        levelNo );
                    //textprintf_centre_ex(buffer, font, , level, 400, 300,makecol(255, 0, 255), -1);
                    blit (buffer,screen,0,0,0,0,screen->w,screen->h);
                    levelTime += 1;
                }
                levelTime =0;
                cr1 = new Player("Carl", 80, 80, lives, 100, "man3.bmp", levels[level], 30, 18);
                cr1->addFrame("man4.bmp");
                //cr1->setLife(100);
                worms.clear();
                for (unsigned int p = 0; p < worms.size(); p++)
                {
                    worms.erase(worms.begin()+p);
                }
                unsigned int i= 0;
                while ( worms.size() < wormAmount)
                {
                    int mx = 38;
                    int my = 110;
                    int randomX, randomY;
                    int highestX = (WIDTH - mx);
                    int highestY = (HEIGHT - 60);
                    int rangeX=(highestX-mx)+1;
                    int rangeY=(highestY-my)+1;
                    randomX = mx+int(rangeX*rand()/(RAND_MAX + 1.0));
                    randomY = my+int(rangeY*rand()/(RAND_MAX + 1.0));
                    for (unsigned int g = 0; g < xPos.size(); g++)
                    {
                        while (randomX > xPos[g]-100 &&
                               randomY > yPos[g]-100 &&
                               randomX < xPos[g]+100 &&
                               randomY < yPos[g]+100)
                        {
                            randomX = mx+int(rangeX*rand()/(RAND_MAX + 1.0));
                            randomY = my+int(rangeY*rand()/(RAND_MAX + 1.0));
                        }
                    }
                    xPos.push_back(randomX);
                    yPos.push_back(randomY);
                    worms.push_back(new Worm("Worm"+ i, randomX, randomY, "worm3.bmp", levels[level], 32, 32));
                    if (

                            worms[i]->isBlocked(randomX, randomY + 33, levels[level]) ||
                            worms[i]->isBlocked(randomX+33, randomY, levels[level]) ||
                            worms[i]->isBlocked(randomX+33, randomY+33, levels[level]) ||
                            worms[i]->isBlocked(randomX+32, randomY + 32, levels[level]) ||
                            worms[i]->isBlocked(randomX+32, randomY , levels[level]) ||
                            worms[i]->isBlocked(randomX, randomY + 32, levels[level]) ||
                            worms[i]->isBlocked(randomX+16, randomY + 16, levels[level]) ||
                            worms[i]->isBlocked(randomX, randomY, levels[level]) ||
                            worms[i]->isLadder(randomX+32, randomY-1, levels[level]) ||
                            worms[i]->isLadder(randomX-1, randomY + 32, levels[level]) ||
                            worms[i]->isLadder(randomX, randomY, levels[level]) ||
                            worms[i]->isLadder(randomX+32, randomY + 32, levels[level]))
                        {
                            worms.erase(worms.begin()+i);
                        }
                        else
                        {
                            worms[i]->addFrame("worm4.bmp");

                            clear_to_color(buffer, makecol(0, 0, 0));
                            textprintf_centre_ex(buffer, font, 400, 300,
                                        makecol(0, 100, 243), -1,
                                        "Level: %d",
                                        levelNo );
                            textprintf_centre_ex(buffer, font, 400, 350,
                            makecol(0, 100, 243), -1,
                            "Loading Worm %d / %d",
                            i, wormAmount );

                            blit (buffer,screen,0,0,0,0,screen->w,screen->h);
                            i++;
                        }
                }
                xPos.clear();
                yPos.clear();
                //worms.push_back(new Worm("Worm", 1780, 660, "worm1.bmp", levels[level], 140, 140));

                //i=0;
                unsigned int j= 0;
                while ( eggs.size() < eggAmount)
                {
                    int mx = 38;
                    int my = 110;
                    int randomX, randomY;
                    int highestX = (WIDTH - mx);
                    int highestY = (HEIGHT - 60);
                    int rangeX=(highestX-mx)+1;
                    int rangeY=(highestY-my)+1;
                    randomX = mx+int(rangeX*rand()/(RAND_MAX + 1.0));
                    randomY = my+int(rangeY*rand()/(RAND_MAX + 1.0));

                    for (unsigned int g = 0; g < xPos.size(); g++)
                    {
                        while (randomX > xPos[g]-150 &&
                               randomY > yPos[g]-150 &&
                               randomX < xPos[g]+150 &&
                               randomY < yPos[g]+150)
                        {
                            randomX = mx+int(rangeX*rand()/(RAND_MAX + 1.0));
                            randomY = my+int(rangeY*rand()/(RAND_MAX + 1.0));
                        }
                    }
                    xPos.push_back(randomX);
                    yPos.push_back(randomY);
                    eggs.push_back(new Egg("Egg "+ j, randomX, randomY, "egg2.bmp", levels[level], 30, 28));

                    if (eggs[j]->isBlocked(randomX+32, randomY + 32, levels[level]) ||
                        eggs[j]->isBlocked(randomX+32, randomY , levels[level]) ||
                        eggs[j]->isBlocked(randomX, randomY + 32, levels[level]) ||
                        eggs[j]->isBlocked(randomX+16, randomY + 16, levels[level]) ||
                        eggs[j]->isBlocked(randomX, randomY, levels[level]) ||
                        eggs[j]->isLadder(randomX+32, randomY-1, levels[level]) ||
                        eggs[j]->isLadder(randomX-1, randomY + 32, levels[level]) ||
                        eggs[j]->isLadder(randomX, randomY, levels[level]) ||
                        eggs[j]->isLadder(randomX+32, randomY + 32, levels[level]))
                    {
                        eggs.erase(eggs.begin()+j);
                    }
                    else
                    {
                        j++;
                    }
                }
                xPos.clear();
                yPos.clear();
                //j=0;
                /*
                cr1->setXVelocity(0);
                cr1->setYVelocity(0);
                cr1->setX(80);
                cr1->setY(80);
                */
                wormAmount += 5;
                eggAmount += 2;
                levelComplete = false;
            }
            currentTime =  GetTickCount();
            timePassed = currentTime - prevTime;
            acquire_screen();
            clear(buffer);

            if (key[KEY_LEFT])
            {
                cr1->moveLeft(timePassed);
            }
            else if (key[KEY_RIGHT])
            {
                cr1->moveRight(timePassed);
            }
            else
            {
                cr1->stopH();
            }
            if (key[KEY_UP] && cr1->getClimbing() )
            {
                cr1->moveUp(timePassed);
            }
            else if (key[KEY_DOWN] && cr1->getClimbing())
            {
                cr1->moveDown(timePassed);
            }
            else if (cr1->getClimbing()) {
                cr1->stopV();
            }
            if (key[KEY_SPACE])
            {
                cr1->jump(levels[level]);
            }
            if (key[KEY_X])
            {
                levels[level]->holeDig(cr1->getX()+(cr1->getWidth()/2), cr1->getY() + cr1->getHeight()+3);

                for (unsigned int n = 0; n < worms.size(); n++)
                {
                    if (worms[n]->getBuried(cr1->getX()+(cr1->getWidth()/2), cr1->getY() + cr1->getHeight()+4))
                    {
                        levels[level]->killWorm(cr1->getX()+(cr1->getWidth()/2), cr1->getY() + cr1->getHeight()+4);
                        worms.erase(worms.begin()+n);
                    }
                }
            }
            vpx = cr1->getX()-(VPW/2);
            vpy = cr1->getY()-(VPH/2);

            if (vpx < 0)
            {
                vpx = 0;
            }
            if (vpy < 0)
            {
                vpy = 0;
            }
            if ((vpx + VPW) > (levels[level]->getWidth()*levels[level]->blockSizeShow()))
            {
                vpx = levels[level]->getWidth() * levels[level]->blockSizeShow() - VPW;
            }
            if ((vpy + VPH) > (levels[level]->getHeight()*levels[level]->blockSizeShow()))
            {
                vpy = levels[level]->getHeight() * levels[level]->blockSizeShow() - VPH;
            }

            levels[level]->setViewY(vpy);
            levels[level]->setViewX(vpx);

            blit (bg, buffer, vpx, vpy, 0 , 0 , WIDTH, HEIGHT);
            masked_blit (bg2, buffer, vpx*0.25,vpy*0.25,0,165-vpy,WIDTH,HEIGHT);
           // masked_blit (bg3, buffer, vpx*0.2,vpy*0.20,0,0,WIDTH,HEIGHT);

            for (unsigned int n = 0; n < eggs.size(); n++)
            {
                eggs[n]->draw(buffer, vpx, vpy, timePassed);
                eggs[n]->move(timePassed, levels[level]);

                if (eggs[n]->caught(cr1) && cr1->getEgg()== false && dead == false)
                {
                    eggs[n]->setCarried(true);
                }
                else if (dead == true)
                {
                    eggs[n]->setCarried(false);
                    cr1->setEgg(false);
                }

                if (eggs[n]->getCarried())
                {
                    cr1->setEgg(true);
                    if (cr1->getXVelocity() < 0)
                    {
                        eggs[n]->setX(cr1->getX()-3 + cr1->getXVelocity());
                        eggs[n]->setY(cr1->getY()-10 +cr1->getYVelocity());
                    }
                    else
                    {
                        eggs[n]->setX(cr1->getX()-10 + cr1->getXVelocity());
                        eggs[n]->setY(cr1->getY()-10+ cr1->getYVelocity());

                    }
                    if (cr1->isBasket(cr1->getX(), cr1->getY(), levels[level]))
                    {
                        eggs.erase(eggs.begin()+n);
                        levels[level]->frameI();
                        cr1->setEgg(false);
                    }
                    if(eggs.empty())
                    {
                        levelComplete = true;
                    }

                }

            }


            cr1->draw(buffer, vpx, vpy, timePassed);
            cr1->move(timePassed, levels[level]);
            levels[level]->render(buffer, timePassed);
            for (unsigned int n = 0; n < worms.size(); n++)
            {


                worms[n]->draw(buffer, vpx, vpy, timePassed);
                worms[n]->move(timePassed*0.5, levels[level]);
                worms[n]->patrol2(timePassed, levels[level]);
                textprintf_ex(buffer, font, worms[4]->getX()-vpx, worms[4]->getY()-vpy-10,
                                        makecol(255, 0, 0), -1,
                                        "Tim");

                if (worms[n]->eaten(cr1))
                {
                    cr1->takeLife(4);
                    cout << "Worm " << n << endl;
                    if (cr1->getLife() <= 0){
                        cr1->livesLost();
                        lives--;
                        cr1->setXVelocity(0);
                        cr1->setYVelocity(0);
                        cr1->setX(80);
                        cr1->setY(80);
                        dead = true;
                        cr1->setLife(100);
                    }

                }
            }

            rectfill (buffer, 0 , 0 , VPW , 34, makecol(0,0,0));
            if (eggs.size() <= 7)
            {
                for (unsigned int n = 0; n < eggs.size(); n++)
                {
                    masked_stretch_blit (egg, buffer, 0, 0, 200, 200, 18*n+270, 14, 16, 16);
                }
            }
            else
            {
                for (unsigned int n = 0; n < eggs.size() && n < 7; n++)
                {
                    masked_stretch_blit (egg, buffer, 0, 0, 200, 200, 18*n+270, 2, 16, 16);
                }
                for (unsigned int n = 0; n < eggs.size() - 7; n++)
                {
                    masked_stretch_blit (egg, buffer, 0, 0, 200, 200, 18*n+270, 18, 16, 16);
                }
            }
            textout_ex(buffer, font, "Eggs Left:", 185, 20,makecol(255, 0, 255), -1);
            for (unsigned int k = 0; k < cr1->livesLeft(); k++)
            {
               masked_stretch_blit (newPlayer, buffer, 0, 0, 112, 200, 24*k+110, 10, 12, 20);
            }
            textout_ex(buffer, font, "Lives Left:", 10, 20,makecol(255, 0, 255), -1);

            timerTry += timePassed;

            if(timerTry > 1000)
            {
                newTimer -= 1;
                timerTry = 0;
            }

            textprintf_centre_ex(buffer, font, 445, 20,
                                         makecol(255, 0, 255), -1,
                                         "Timer: %d", newTimer);



            textout_centre_ex(buffer, font, "Life:", VPW-280, 20,makecol(255, 0, 255), -1);

            rectfill (buffer, VPW-240 , 8 , (VPW-38) , 32, makecol(255,0,0));
            rectfill (buffer, VPW-40 , 10 , (VPW-240) +(cr1->getLife()*2) , 30, makecol(0,0,0));
            rectfill (buffer, VPW-40 , 10 , VPW-40 , 30, makecol(255,0,0));




            if (dead)
            {
                die += timePassed;
                if (die < 3000)
                {
                    textout_centre_ex(buffer, font, "You Lost a Life", VPW/2, VPH/2,makecol(0, 0, 255), -1);
                }
                else
                {
                    die = 0;
                    dead = false;
                }
            }

            if (cr1->livesLeft()== 0 && !(key[KEY_ESC]) || newTimer <= 0)
            {
                clear_to_color(buffer, makecol(0, 0, 0));
                    textprintf_centre_ex(buffer, font, 400, 300,
                                         makecol(0, 100, 243), -1,
                                         "Game Over");
                    //textprintf_centre_ex(buffer, font, , level, 400, 300,makecol(255, 0, 255), -1);
                    blit (buffer,screen,0,0,0,0,screen->w,screen->h);
            }

            masked_stretch_blit (bg4, buffer, vpx*2,0, 3680, 200, 0,880-vpy,3680,200);


            //rectfill (buffer, 0 , 0, VPW , 40, makecol(0,0,0));

            blit (buffer,screen,0,0,0,0,screen->w,screen->h);
            prevTime = currentTime;
            release_screen();
            rest(15);

        }

    /*
    for (unsigned int n = 0; n < worms.size(); n++)
    {
        delete worms[n];
    }
    */
    delete cr1;
    delete levels[level];
    destroy_bitmap(buffer);



    return 0;
}
END_OF_MAIN();



