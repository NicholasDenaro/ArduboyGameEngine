#include "game.h"
#include "sign.h"

Sign::Sign() : Sign(0, 0, "Hello  World") {}

Sign::Sign(int x, int y, const char* text) : Entity(x, y, NULL)
{
  this->text = text;
}

bool Sign::activate()
{
  Game::game->showText(text);
  return true;
}
