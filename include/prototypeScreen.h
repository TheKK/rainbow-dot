/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * testScreen.h 
 *
 */

#ifndef PROTOTYPESCREEN_H
#define PROTOTYPESCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"

#include "gameStatus.h"
#include "button.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class PrototypeScreen: public GameStatus
{
	public:
		PrototypeScreen();
		~PrototypeScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		void CleanUp();
};

#endif
