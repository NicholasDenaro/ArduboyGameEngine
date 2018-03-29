#ifndef SIGN_H
#define SIGN_H

#include "entity.h"
#include "sprite.h"

class Sign : public Entity
{
  public:
  const char* text;
  Sign();
  Sign(int x, int y, const char* text);
  bool activate() override;
};

#endif
