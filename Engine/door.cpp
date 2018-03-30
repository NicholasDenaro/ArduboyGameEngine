#include "game.h"
#include "door.h"

Door::Door() : Door(0, 0, 0, 0, NULL) {}

Door::Door(int x, int y, int destX, int destY, Location* location) : Entity(x, y, NULL)
{
  this->destX = destX;
  this->destY = destY;
  this->location = location;
}

bool Door::activate()
{
  Game::game->setLocation(location);
  Player* player = Game::game->player;
  player->movePos(destX - player->x(), destY - player->y());
  return true;
}
