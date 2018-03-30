#include <Arduboy2.h>
#include "game.h"
#include "drawer.h"
#include "location.h"
#include "sprite.h"
#include "player.h"
#include "door.h"
#include "sign.h"

int freeRam();

Game* Game::game = NULL;

Player* Game::player = NULL;

Game::Game() {}

Game::Game(Arduboy2 arduboy)
{
  arduboy = arduboy;
  drawer = Drawer(arduboy);
  tiles = Entity(0, 0, StaticSprites::tileSprite);
  Game::player = new Player(8, 8, StaticSprites::playerSprite);
  view = View(WIDTH, HEIGHT);
  _imageIndex = 0;
  tileMap = new unsigned char[256];
  tileMap[' '] = 0;
  tileMap['%'] = 1;
  tileMap[':'] = 2;
  tileMap['|'] = 4;
  tileMap['-'] = 5;
  tileMap['T'] = 8;
  tileMap['t'] = 9;
  tileMap['B'] = 10;
  tileMap['O'] = 11;
  tileMap['Q'] = 12;
  tileMap['H'] = 16;
  tileMap['W'] = 16;
  tileMap['D'] = 17;
  tileMap['_'] = 18;
  tileMap['='] = 20;
  tileMap['b'] = 22;
  tileMap['d'] = 23;
  locations = new Location*[7];
  locations[0] = new Location(17, 16, Maps::loc);
  locations[1] = new Location(6, 5, Maps::house);
  locations[2] = new Location(5, 4, Maps::house2);
  locations[3] = new Location(32, 14, Maps::farm);
  locations[4] = new Location(8, 5, Maps::farmhouse);
  locations[5] = new Location(8, 5, Maps::mine);
  locations[6] = new Location(15, 5, Maps::town);
  _location = locations[4];
  counter = 0;
}


void Game::tick()
{
  arduboy.pollButtons();
  arduboy.clear();

  view.centerOn(*_location, *player);
  view.draw(drawer, *_location, tiles, tileMap);

  _location->tick(arduboy);

  _imageIndex++;
  
  Entity** entities = _location->getEntities();
  for(int i = 0; i < _location->entitiesLength(); i++)
  {
    if(entities[i] != NULL)
    {
      Entity* entity = entities[i];
      drawer.fill(view, *entity, entity->imageIndex(_imageIndex), 16, WHITE);
    }
  }

  if(arduboy.justPressed(A_BUTTON))
  {
    counter++;
    Serial.println(freeRam());
  }
  
  arduboy.display();
}

void Game::start()
{
  bool success = _location->addEntity(player);
  
  locations[0]->addEntity(new Sign(3 * 8, 6 * 8, Texts::signGreetings));
  locations[0]->addEntity(new Sign(9 * 8, 2 * 8, Texts::signToFarm));
  locations[0]->addEntity(new Sign(11 * 8, 6 * 8, Texts::signToTown));
  locations[0]->addEntity(new Sign(10 * 8, 12 * 8, Texts::signToMine));
  
  locations[0]->addEntity(new Door(4 * 8, 3 * 8, 3 * 8, 3 * 8, locations[1])); // to north house
  locations[1]->addEntity(new Door(3 * 8, 4 * 8, 4 * 8, 4 * 8, locations[0]));
  
  locations[0]->addEntity(new Door(3 * 8, 12 * 8, 3 * 8, 2 * 8, locations[2])); // to south house
  locations[2]->addEntity(new Door(3 * 8, 3 * 8, 3 * 8, 13 * 8, locations[0]));
  
  locations[0]->addEntity(new Door(8 * 8, 0 * 8, 3 * 8, 12 * 8, locations[3])); // to farm
  locations[3]->addEntity(new Door(3 * 8, 13 * 8, 8 * 8, 1 * 8, locations[0]));
  
  locations[3]->addEntity(new Door(4 * 8, 3 * 8, 3 * 8, 3 * 8, locations[4])); // to farmhouse
  locations[4]->addEntity(new Door(3 * 8, 4 * 8, 4 * 8, 4 * 8, locations[3]));
  
  locations[0]->addEntity(new Door(8 * 8, 15 * 8, 4 * 8, 1 * 8, locations[5])); // to mine
  locations[5]->addEntity(new Door(4 * 8, 0 * 8, 8 * 8, 14 * 8, locations[0]));
  locations[5]->addEntity(new Sign(3 * 8, 2 * 8, Texts::signMine));
  
  locations[0]->addEntity(new Door(16 * 8, 7 * 8, 1 * 8, 2 * 8, locations[6])); // to town
  locations[6]->addEntity(new Door(0 * 8, 2 * 8, 15 * 8, 7 * 8, locations[0]));
  locations[6]->addEntity(new Sign(10 * 8, 3 * 8, Texts::signTown));
}

Location* Game::location()
{
  return _location;
}

void Game::setLocation(Location* location)
{
  //Serial.println("new location");
  _location->removeEntity(player);
  _location = location;
  _location->addEntity(player);
}

int Game::imageIndex()
{
  return _imageIndex;
}

void Game::showText(const char* text)
{
  arduboy.fillRect(0, HEIGHT - 16, WIDTH, 16, BLACK);
  arduboy.setCursor(1, HEIGHT - 15);
  int count = 0;
  int lineStart = 0;
  int len = strlen_P(text);
  char ch;
  for(int i = 0; i < len; i++)
  {
    ch = pgm_read_byte_near(text + i);
    arduboy.print(ch);
    int faster = arduboy.pressed(A_BUTTON) ? 3 : 1;

    if(arduboy.pressed(B_BUTTON))
    {
      return;
    }
    
    delay(100 / faster);
    arduboy.display();
    if(arduboy.getCursorX() + 8 >= WIDTH)
    {
      if(count >= 1)
      {
        arduboy.fillRect(0, HEIGHT - 16, WIDTH, 16, BLACK);
        arduboy.setCursor(1, HEIGHT - 15);
        for(int j = lineStart; j < len && arduboy.getCursorX() + 8 < WIDTH; j++)
        {
          ch = pgm_read_byte_near(text + j);
          arduboy.print(ch);
        }
      }
      
      count++;
      arduboy.setCursor(1, HEIGHT - 15 + (count > 0 ? 8 : 0));
      lineStart = i + 1;
    }
  }
  while(arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)){}
  while(!arduboy.pressed(A_BUTTON) && !arduboy.pressed(B_BUTTON)){}
  while(arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)){}
}

