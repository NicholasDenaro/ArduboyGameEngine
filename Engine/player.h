#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "sprite.h"

class Player : public Entity
{
  int _dir;

  public:
  bool moved;
  Player();
  Player(int x, int y, Sprite* sprite);
  void tick(Arduboy2* arduboy) override;
  void movePos(int dx, int dy);
  int dir();
  int imageIndex(int index) override;
};

#endif
