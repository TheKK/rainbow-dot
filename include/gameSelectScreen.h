/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * gameSelectScreen.h 
 *
 */

#ifndef GAMESELECTSCREEN_H
#define GAMESELECTSCREEN_H

#include <iostream>
#include <SDL2/SDL.h>

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

		SDL_Texture* m_TransferPic;
		SDL_Rect m_TransferPicClip;

		enum GameStatusMode gameStatusMode;

		void CleanUp();
};

#endif
