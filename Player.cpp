#include "Player.h"

Player::Player(string n, int x, int y, int s, int l, string fn, Maze* mazeIn, int ch, int cw)
     :Being(n, x, y, fn, mazeIn, ch, cw)
{
    lives = s;
    life = l;
    score = 0;
    gotEgg = false;
}
void Player::setEgg(bool b)
{
    gotEgg = b;
}
bool Player::getEgg()
{
    return gotEgg;
}
void Player::setLife(int s)
{
    life = s;
}
int Player::getLife()
{
    return life;
}
void Player::takeLife(int l)
{
    life -= l;
}
int Player::livesLeft()
{
    return lives;
}
void Player::livesLost()
{
    lives--;
};




