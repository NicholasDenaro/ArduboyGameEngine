#ifndef DOOR_H
#define DOOR_H
#include <Arduboy2.h>
#include "entity.h"
#include "location.h"

class Door : public Entity
{
  private:
  Location* location;
  int destX;
  int destY;
  
  public:
  Door();
  Door(int x, int y, int destX, int destY, Location* location);
  bool activate() override;
};

#endif
