#include "entity.h"
#include "sprite.h"

Entity::Entity() : Entity(0, 0, Sprite()) {}

Entity::Entity(int x, int y, Sprite sprite)
{
  this->_sprite = sprite;
  this->setPos(x, y);
}

void Entity::tick(Arduboy2 arduboy)
{
  
}

void Entity::setPos(int x, int y)
{
  _x = x;
  _y = y;
}

int Entity::x()
{
  return _x;
}

int Entity::y()
{
  return _y;
}

Sprite Entity::sprite()
{
  return this->_sprite;
}

int Entity::imageIndex(int index)
{
  return index;
}

bool Entity::activate()
{
  return false;
}

