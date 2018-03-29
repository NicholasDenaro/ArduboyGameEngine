#include "sprite.h"

Sprite::Sprite() : Sprite(0, 0, 0){ }

Sprite::Sprite(const unsigned char *image, unsigned char width, unsigned char height)
{
  this->image = image;
  this->_width = width;
  this->_height = height;
}

const unsigned char* Sprite::bytes()
{
  return this->image;
}

unsigned char Sprite::width()
{
  return this->_width;
}

unsigned char Sprite::height()
{
  return this->_height;
}

