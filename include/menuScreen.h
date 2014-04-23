/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * menuScreen.h 
 *
 */

#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>
#include <SDL2/SDL.h>

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
		//Logo of KK
		SDL_Texture* m_Logo;
		SDL_Rect m_LogoPos;

		void CleanUp();
};

#endif
