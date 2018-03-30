#include "drawer.h"

Drawer::Drawer(){}

Drawer::Drawer(Arduboy2 arduboy)
{
  this->arduboy = arduboy;
}

void Drawer::draw(View view, Entity entity, int index, int color)
{
  Sprite* sprite = entity.sprite();
  if(sprite != NULL)
  {
    const unsigned char *pixels = sprite->bytes();
    int offset = index * sprite->width() * sprite->height() / 8;
    this->arduboy.drawBitmap(entity.x() - view.x(), entity.y() - view.y(), pixels + offset, sprite->width(), sprite->height(), color);
  }
}

void Drawer::fill(View view, Entity entity, int index, int mask, int color)
{
  draw(view, entity, mask + index, color);
  draw(view, entity, index, !color);
}


