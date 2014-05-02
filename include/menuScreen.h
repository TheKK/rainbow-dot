/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * menuScreen.h 
 *
 */

#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

#include "gameStatus.h"
#include "button.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class MenuScreen: public GameStatus
{
	public:
		MenuScreen();
		~MenuScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		SDL_Texture* m_Background;

		int m_CurrentTitle;
		SDL_Texture* m_Title[3];

		void CleanUp();
};

#endif
