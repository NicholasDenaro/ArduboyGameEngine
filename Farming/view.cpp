#include "view.h"

View::View() : View(WIDTH, HEIGHT) {}

View::View(int width, int height)
{
  this->_width = width;
  this->_height = height;
}

void View::draw(Drawer drawer, Location location, Entity tiles, unsigned char* tMap)
{
  int xoffset = _x / 8;
  int yoffset = _y / 8;
  int xend = xoffset + _width / 8;
  int yend = yoffset + _height / 8;
  
  for(int j = yoffset; j <= yend; j++)
  {
    for(int i = xoffset; i <= xend; i++)
    {
      tiles.setPos(i * 8, j * 8);
      if(i < location.width() && j < location.height())
      {
        char mapTile = location.getTile(i,j);
        char tile = tMap[mapTile];
        drawer.draw(*this, tiles, tile, WHITE);
      }
    }
  }
}

void View::centerOn(Location location, Entity entity)
{
  _x = entity.x() - _width / 2;
  _y = entity.y() - _height / 2;

  if(_x < 0)
  {
    _x = 0;
  }

  if(_y < 0)
  {
    _y = 0;
  }

  if(_x + _width > location.width() * 8)
  {
    _x = location.width() * 8 - _width;
  }

  if(_y + _height > location.height() * 8)
  {
    _y = location.height() * 8 - _height;
  }
}

int View::x()
{
  return _x;
}

int View::y()
{
  return _y;
}

