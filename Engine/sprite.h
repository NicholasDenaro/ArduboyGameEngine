#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
  private:
  const unsigned char *image;
  unsigned char _width;
  unsigned char _height;

  public:
  Sprite();
  Sprite(const unsigned char *image, unsigned char width, unsigned char height);
  const unsigned char* bytes();
  unsigned char width();
  unsigned char height();
};

#endif
