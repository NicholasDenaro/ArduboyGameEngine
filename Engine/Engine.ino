#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2* arduboy = new Arduboy2();
ArduboyTones* sound = new ArduboyTones(arduboy->audio.enabled);
#include "game.h"

const uint16_t startupTone[] PROGMEM = {NOTE_B6,20,NOTE_C5,60,NOTE_REST,50,NOTE_F7,300, TONES_END};

void setup() {
  // put your setup code here, to run once:
  arduboy->begin();
  arduboy->setFrameRate(30);
  arduboy->clear();
  
  Serial.begin(9600);
  Serial.println(freeRam());
  Game::game = new Game(arduboy, sound);
  Game::game->start();
  //test();
  arduboy->setCursor(0,0);
  arduboy->print(F("Hello"));
  arduboy->display();
  
  sound->tones(startupTone);
}

void test()
{
  Serial.println(freeRam());
  new Location*[5];
  Serial.print("array ");
  Serial.println(freeRam());
  Location** locations = new Location*[5];
  locations[0] = new Location(17, 16, Maps::loc);
  Serial.print("main ");
  Serial.println(freeRam());
  locations[1] = new Location(6, 5, Maps::house);
  Serial.print("house ");
  Serial.println(freeRam());
  locations[2] = new Location(6, 4, Maps::house2);
  Serial.print("house2 ");
  Serial.println(freeRam());
  locations[3] = new Location(32, 16, Maps::farm);
  Serial.print("farm ");
  Serial.println(freeRam());
  locations[4] = new Location(8, 5, Maps::farmhouse);
  Serial.print("farmhouse ");
  Serial.println(freeRam());
  unsigned char* tileMap = new unsigned char[256]{};
  Serial.print("tilemap ");
  Serial.println(freeRam());
}

void loop() {
  if (!(arduboy->nextFrame()))
    return;
  Game::game->tick();
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
