#ifndef GAME_H
#define GAME_H

#include "drawer.h"
#include "location.h"
#include "sprite.h"
#include "player.h"

namespace StaticSprites
{
    const PROGMEM unsigned char playerSpriteData[] = {
      0x60, 0xD6, 0xA9, 0x95, 0xD1, 0xB5, 0xEE, 0x00, 0x00, 0x70, 0xC0, 0xEE, 0xD1, 0x95, 0xB1, 0xE4, 0x60, 0xD6, 0xA9, 0x95, 0xD1, 0xB5, 0xEE, 0x00, 0x00, 0xF0, 0xCE, 0xD1, 0x75, 0x91, 0xB5, 0xEE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0xB5, 0xD1, 0x95, 0xA9, 0xD6, 0x60, 0xEE, 0xB5, 0x91, 0x75, 0xD1, 0xCE, 0xF0, 0x00, 0x00, 0xEE, 0xB5, 0xD1, 0x95, 0xA9, 0xD6, 0x60, 0xE4, 0xB1, 0x95, 0xD1, 0xEE, 0xC0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x56, 0x6A, 0x2E, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x30, 0x10, 0x2E, 0x6A, 0x4E, 0x0A, 0x00, 0x20, 0x56, 0x6A, 0x2E, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x30, 0x2E, 0x0A, 0x6E, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A, 0x2E, 0x6A, 0x56, 0x20, 0x00, 0x00, 0x4A, 0x6E, 0x0A, 0x2E, 0x30, 0x00, 0x00, 0x00, 0x00, 0x4A, 0x2E, 0x6A, 0x56, 0x20, 0x00, 0x0A, 0x4E, 0x6A, 0x2E, 0x10, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    static Sprite* playerSprite = new Sprite(StaticSprites::playerSpriteData, 8, 8);

    const PROGMEM unsigned char tileSpriteData[] = {
      0xFF, 0xDF, 0xBF, 0xDF, 0xFB, 0xF7, 0xFB, 0xFF, 0xFF, 0xFD, 0xDA, 0xAD, 0xDF, 0xF7, 0xEB, 0xF7, 0xFF, 0xBD, 0xD7, 0xB7, 0xFD, 0xDD, 0x6B, 0xFF, 0xFF, 0xDD, 0xBB, 0xDD, 0xBB, 0xDD, 0xBB, 0xFF, 0xFF, 0x88, 0x77, 0xDD, 0x7B, 0xEE, 0x11, 0xFF, 0xAB, 0xBD, 0xB5, 0xDD, 0xBB, 0xAD, 0xB5, 0xDD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE1, 0xF5, 0x91, 0x85, 0xF5, 0xE1, 0xFF, 0xFF, 0x87, 0xB9, 0x5E, 0x5E, 0xB9, 0x87, 0xFF, 0xFF, 0x81, 0xB5, 0xB5, 0xA5, 0xB5, 0x81, 0xFF, 0xC3, 0xBD, 0x4D, 0x5E, 0x7A, 0xA5, 0x99, 0xE7, 0xFF, 0xC7, 0x9B, 0x33, 0x3B, 0xAB, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB6, 0x86, 0x30, 0x36, 0xA6, 0x86, 0xB0, 0x32, 0xB6, 0xB6, 0x02, 0xFA, 0xFA, 0xDA, 0x02, 0xB6, 0xB6, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x32, 0xFF, 0xFF, 0x81, 0xFF, 0xFF, 0x30, 0xFF, 0xFF, 0xFB, 0xDB, 0xDB, 0xDB, 0xDF, 0xDF, 0xDB, 0xFB, 0xB6, 0xB6, 0x06, 0x02, 0x02, 0x02, 0x06, 0xB6, 0xFF, 0x00, 0xB9, 0xB5, 0xB5, 0xB9, 0x00, 0xFF, 0xFF, 0x01, 0xED, 0xE1, 0xAD, 0xED, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    };
    
    static Sprite* tileSprite = new Sprite(StaticSprites::tileSpriteData, 8, 8);
};

namespace Texts
{
  static const PROGMEM char signGreetings[] = {"Hello World! This is a long winded sign, so be ready for some text! This is a small demo for the engine that I will be writing. You can find the source code on my GitHub page /NicholasDenaro. Please let me know if you like it!"};
  static const PROGMEM char signToFarm[] = {"North to Farm"};
  static const PROGMEM char signToMine[] = {"South to Mines"};
  static const PROGMEM char signToTown[] = {"East to Town"};

  
}

namespace Maps
{
    const PROGMEM unsigned char loc[273] = 
      "tttttttt|tttttttt"
      "t       |    %% t"
      "t%%HHH  |T  %%% t"
      "t%%HDH  |  %%%  t"
      "t%%%----|   %%  t"
      "t       |       t"
      "t  T    |  T    t"
      "t      Q|--------"
      "t      Q|       t"
      "t      Q|   ::  t"
      "t      Q|  :::  t"
      "t HHH   |  :::  t"
      "t HDH   | T::   t"
      "t  -----|       t"
      "t       |       t"
      "tttttttt|tttttttt";

      const PROGMEM unsigned char house[31] = 
      "WWWWWW"
      "b==W=="
      "W=WW=="
      "======"
      "WWW_WW";

      const PROGMEM unsigned char house2[21] = 
      "WWWWW"
      "====="
      "=bW=="
      "WWW_W";

      const PROGMEM unsigned char farm[513] = 
      "tttttttttttttttttttttttttttttttt"
      "t                              t"
      "t HHHHH                        t"
      "t HHDHH                        t"
      "t %%|%%    ::::::::::::::::    t"
      "t   |      ::::::::::::::::    t"
      "t B |      ::::::::::::::::    t"
      "t  |-      ::::::::::::::::    t"
      "t  |       ::::::::::::::::    t"
      "t  |       ::::::::::::::::    t"
      "t  |       ::::::::::::::::    t"
      "t  |       ::::::::::::::::    t"
      "t  |                           t"
      "ttt|tttttttttttttttttttttttttttt";

      const PROGMEM unsigned char farmhouse[41] = 
      "WWWWWWWW"
      "=====db="
      "========"
      "========"
      "WWW_WWWW";

      const PROGMEM unsigned char mine[41] = 
      "OOOO|OOO"
      "O::::::O"
      "O::T:::O"
      "O::::::O"
      "OOOOOOOO";

      const PROGMEM unsigned char town[76] = 
      "tttHHHtHHHtHHHt"
      "tQ HDH%HDH%HDHt"
      "------------- t"
      "tQ %%%    T  %t"
      "ttttttttttttttt";
};

class Game
{
  private:
  Arduboy2 arduboy;
  Drawer drawer;
  Entity tiles;
  Location* _location;
  Location** locations;
  View view;
  int _imageIndex;
  int counter;
  unsigned char* tileMap;
  
  public:
  static Player* player;
  static Game* game;
  Game();
  Game(Arduboy2 arduboy);
  void tick();
  void start();

  Location* location();
  void setLocation(Location* location);
  int imageIndex();

  void showText(const char* text);
};

#endif
