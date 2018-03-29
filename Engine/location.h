#ifndef LOCATION_H
#define LOCATION_H
#include <Arduboy2.h>
#include "entity.h"

class Location
{
  private:
  int _width;
  int _height;
  unsigned char* tiles;
  Entity** entities;
  int _entitiesLength;
  int entityCount;

  public:
  Location();
  Location(int width, int height, const unsigned char* tiles);
  unsigned char getTile(int x, int y);
  void tick(Arduboy2 arduboy);
  int width();
  int height();
  bool addEntity(Entity* entity);
  bool removeEntity(Entity* entity);
  int entitiesLength();
  Entity** getEntities();
  bool activateEntity(int x, int y);
};

#endif
