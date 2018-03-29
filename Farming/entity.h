#ifndef ENTITY_H
#define ENTITY_H
#include <Arduboy2.h>
#include "sprite.h"

class Entity
{
  protected:
  int _x;
  int _y;
  Sprite _sprite;
  
  public:
  Entity();
  Entity(int x, int y, Sprite sprite);
  virtual void tick(Arduboy2 arduboy);
  void setPos(int x, int y);
  int x();
  int y();
  Sprite sprite();
  virtual int imageIndex(int index);
  virtual bool activate();
};

#endif
