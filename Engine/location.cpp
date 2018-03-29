#include "entity.h"
#include "location.h"
#include <avr/pgmspace.h>

Location::Location() : Location(8, 8, new unsigned char[64]) {}

Location::Location(int width, int height, const unsigned char* tiles)
{
  this->_width = width;
  this->_height = height;
  this->tiles = tiles;
  _entitiesLength = 5;
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

void Location::tick(Arduboy2 arduboy)
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
      delete entities[i];
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

bool Location::activateEntity(int x, int y)
{
  for(int i = 0; i < _entitiesLength; i++)
  {
    Entity* ent = entities[i];
    if(ent != NULL)
    {
      int xdiff = ent->x() - x;
      int ydiff = ent->y() - y;
      if(xdiff > -4 && xdiff < 4 && ydiff > -4 && ydiff < 4)
      {
        entities[i]->activate();
        return true;
      }
    }
  }
  
  return false;
}
