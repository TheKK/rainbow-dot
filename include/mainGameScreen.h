/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * mainGameScreen.h
 *
 */

#ifndef MAINGAMESCREEN_H
#define MAINGAMESCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

#include "gameStatus.h"
#include "player.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class MainGameScreen: public GameStatus
{
	public:
		MainGameScreen();
		~MainGameScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		Player* player;
		void CleanUp();

		//Event flag
		bool startTransfrom;
};

#endif
