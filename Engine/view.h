#ifndef VIEW_H
#define VIEW_H

#include "drawer.h"
#include "location.h"
#include "entity.h"

class Entity;
class Drawer;

class View
{
  private:
  int _x;
  int _y;
  int _width;
  int _height;

  public:
  View();
  View(int width, int height);
  void draw(Drawer drawer, Location location, Entity tiles, unsigned char* tMap);
  void centerOn(Location location, Entity entity);
  int x();
  int y();
};

#endif
