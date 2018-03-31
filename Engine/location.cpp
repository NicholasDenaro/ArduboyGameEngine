#include "entity.h"
#include "location.h"
#include <avr/pgmspace.h>

Location::Location() : Location(8, 8, new unsigned char[64]) {}

Location::Location(int width, int height, const unsigned char* tiles)
{
  this->_width = width;
  this->_height = height;
  this->tiles = tiles;
  _entitiesLength = 10;
  entities = new Entity*[_entitiesLength];
  if(entities != NULL)
  {
    for(int i = 0; i < _entitiesLength; i++)
    {
      entities[i] = NULL;
    }
  }
  else
  {
    _entitiesLength = 0;
    Serial.println("couldn't create array");
  }
  entityCount = 0;
}

unsigned char Location::getTile(int x, int y)
{
  if(x < 0 || y < 0 || x >= _width || y >= _height)
  {
    return 'W';
  }
  
  return pgm_read_word(tiles + (x + y * this->_width));
}

int Location::width()
{
  return this->_width;
}


int Location::height()
{
  return this->_height;
}

void Location::tick(Arduboy2* arduboy)
{
  for(int i = 0; i < _entitiesLength; i++)
  {
    if(entities[i] != NULL)
    {
      entities[i]->tick(arduboy);
    }
  }
}

bool Location::addEntity(Entity* entity)
{
  if(entity == NULL)
  {
    Serial.println("OOM?");
  }
  
  if(entityCount < _entitiesLength)
  {
    for(int i = 0; i < _entitiesLength; i++)
    {
      if(entities[i] == NULL)
      {
        entities[i] = entity;
        entityCount++;
        return true;
      }
    }
  }
  
  return false;
}

bool Location::removeEntity(Entity* entity)
{
  for(int i = 0; i < _entitiesLength; i++)
  {
    if(entity == entities[i])
    {
      entities[i] = NULL;
      entityCount--;
      return true;
    }
  }
  
  return false;
}

Entity** Location::getEntities()
{
  return entities;
}

int Location::entitiesLength()
{
  return _entitiesLength;
}

bool Location::activateEntity(Entity* entity, int x, int y)
{
  for(int i = 0; i < _entitiesLength; i++)
  {
    Entity* ent = entities[i];
    if(ent != NULL && ent != entity)
    {
      int entx = ent->x() + 4;
      int enty = ent->y() + 4;
      int xdiff = entx - x;
      int ydiff = enty - y;
      /*Serial.print(xdiff);
      Serial.print(",");
      Serial.println(ydiff);*/
      if(xdiff > -4 && xdiff < 4 && ydiff > -4 && ydiff < 4)
      {
        entities[i]->activate();
        return true;
      }
    }
  }
  
  return false;
}
