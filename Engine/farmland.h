#ifndef FARMLAND_H
#define FARMLAND_H
#include "entity.h"

class Farmland : public Entity
{
  byte crop;
  bool watered;
  bool tilled;
  
  public:
  Farmalnd();
  Farmland(int x, int y);
  bool activate() override;
  int imageIndex(int index) override;
};

#endif
