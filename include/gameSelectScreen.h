/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * gameSelectScreen.h 
 *
 */

#ifndef GAMESELECTSCREEN_H
#define GAMESELECTSCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

#include "gameStatus.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class GameSelectScreen: public GameStatus
{
	public:
		GameSelectScreen();
		~GameSelectScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		SDL_Texture* m_Background;

		void CleanUp();
};

#endif
