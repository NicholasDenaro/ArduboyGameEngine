#ifndef DRAWER_H
#define DRAWER_H
#include <Arduboy2.h>
#include "view.h"
#include "entity.h"

class View;

class Drawer
{
  private:
  Arduboy2* arduboy;

  public:
  Drawer();
  Drawer(Arduboy2* arduboy);
  void draw(View view, Entity entity, int index, int color);
  void fill(View view, Entity entity, int index, int mask, int color);
  
};

#endif
