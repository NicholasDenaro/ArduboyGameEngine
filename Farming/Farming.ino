#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "game.h"

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
  
  Serial.begin(9600);
  Serial.println(freeRam());
  Game::game = Game(arduboy);
  //delay(4000);
  Game::game.start();
  Serial.println(freeRam());
  
  /*if(!arduboy.pressed(A_BUTTON))
  {
    sound.tone(NOTE_C5,50,NOTE_E7,150);
  }*/
  arduboy.setCursor(0,0);
  arduboy.print(F("Hello"));
  arduboy.display();
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  Game::game.tick();
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
