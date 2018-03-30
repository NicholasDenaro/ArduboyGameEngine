#include "game.h"
#include "player.h"

Player::Player() : Player(0, 0, NULL) {}

Player::Player(int x, int y, Sprite* sprite) : Entity(x, y, sprite)
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
    int xshift = _dir % 2 == 0 ? _dir - 1 : 0;
    int yshift = _dir % 2 == 1 ? _dir - 2 : 0;
    Game::game->location()->activateEntity(this, _x + 4 - xshift * 6, _y + 4 + yshift * 6);
  }
  
  Game::game->location()->activateEntity(this, _x + 4, _y + 4);
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
  
  if(dy < 0)
  {
    _dir = 1;
  }
  
  if(dy > 0)
  {
    _dir = 3;
  }
  
  int ii = _x + 4 + dx;
  int jj = _y + 4 + dy;
  int xshift = 0;
  int yshift = 0;

  for(int j = -1; j < 2; j++)
  {
    for(int i = -1; i < 2; i++)
    {
      /*if(i == -1 && _x < 8)
      {
        Serial.print(ii + i * 2);
        Serial.print(" ");
        Serial.println((ii + i * 2) / 8);
      }*/

      if((ii + i * 2) < 0)
      {
        xshift = -8;
      }

      if((jj + j * 2) < 0)
      {
        yshift = -8;
      }
      
      char tile = Game::game->location()->getTile((ii + i * 2 + xshift) / 8, (jj + j * 2 + yshift) / 8);
      if(tile == 'W' || tile == 'H' || tile =='T' || tile == 't' || tile == 'B' || tile == 'b' || tile == 'd' || tile == 'Q' || tile == 'O')
      {
        return;
      }
    }
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

