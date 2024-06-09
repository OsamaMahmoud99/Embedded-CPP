#ifndef GAME_H
#define GAME_H

#include "keypad.h"
#include "lcd.h"

extern void Game_DisplayIntro(LCD& lcd);
extern void Game_DisplayMenu(LCD& lcd);
extern void Game_DisplayRules(LCD& lcd);
extern void Game_Start(LCD& lcd,Keypad& keypad);

#endif //GAME_H
