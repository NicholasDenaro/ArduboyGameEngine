#include "game.h"
#include "player.h"

Player::Player() : Player(0, 0, Sprite()) {}

Player::Player(int x, int y, Sprite sprite) : Entity(x, y, sprite)
{
  _dir = 0;
  moved = false;
}

void Player::tick(Arduboy2 arduboy)
{
  moved = false;
  if(arduboy.pressed(LEFT_BUTTON))
  {
    movePos(-1,0);
    moved = true;
  }
  
  if(arduboy.pressed(RIGHT_BUTTON))
  {
    movePos(1,0);
    moved = true;
  }
  
  if(arduboy.pressed(UP_BUTTON))
  {
    movePos(0,-1);
    moved = true;
  }
  
  if(arduboy.pressed(DOWN_BUTTON))
  {
    movePos(0,1);
    moved = true;
  }
  
  if(arduboy.pressed(A_BUTTON))
  {
    Game::game.location()->activateEntity(_x - (_dir - 1) * 8, _y);
  }
}

void Player::movePos(int dx, int dy)
{
  if(dx > 0)
  {
    _dir = 0;
  }
  
  if(dx < 0)
  {
    _dir = 2;
  }

  setPos(_x + dx, _y + dy);
}

int Player::dir()
{
  return _dir;
}

int Player::imageIndex(int index)
{
  return (_dir * 4) + (moved ? 1 : 0) * ((index / 4) % 4);
}

