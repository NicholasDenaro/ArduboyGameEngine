#include <Arduboy2.h>
#include "game.h"
#include "drawer.h"
#include "location.h"
#include "sprite.h"
#include "player.h"
#include "sign.h"

int freeRam();

Game Game::game = Game();

Game::Game() {}

Game::Game(Arduboy2 arduboy)
{
  arduboy = arduboy;
  drawer = Drawer(arduboy);
  tiles = Entity(0, 0, StaticSprites::tileSprite);
  player = new Player(64, 64, StaticSprites::playerSprite);
  view = View(WIDTH, HEIGHT);
  _imageIndex = 0;
  tileMap[256] = new unsigned char[256];
  tileMap[' '] = 0;
  tileMap['T'] = 1;
  tileMap['H'] = 2;
  tileMap['_'] = 3;
  tileMap['|'] = 8;
  tileMap['%'] = 9;
  tileMap['D'] = 10;
  tileMap['-'] = 16;
  tileMap['t'] = 17;
  tileMap[':'] = 24;
  tileMap['='] = 25;
  _location = new Location(17, 16, Maps::loc);
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
  }
  
  arduboy.display();
}

void Game::start()
{
  bool success = _location->addEntity(player);
  _location->addEntity(new Sign(3 * 8, 6 * 8, Texts::signGreetings));
  _location->addEntity(new Sign(9 * 8, 2 * 8, Texts::signToSpring));
  _location->addEntity(new Sign(11 * 8, 6 * 8, Texts::signToTown));
  _location->addEntity(new Sign(10 * 8, 12 * 8, Texts::signToMine));
}

Location* Game::location()
{
  return _location;
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
    delay(100);
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
  while(arduboy.pressed(A_BUTTON)){}
  while(!arduboy.pressed(A_BUTTON)){}
  while(arduboy.pressed(A_BUTTON)){}
}

