/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * startScreen.h
 *
 */

#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"

#include "gameStatus.h"
#include "texture.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class StartScreen: public GameStatus
{
	public:
		StartScreen();
		~StartScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		//Logo of KK
		Texture* logoPic_;

		void CleanUp();
};

#endif
