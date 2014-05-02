/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * startScreen.h 
 *
 */

#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#define LOGO_PATH	"game/pic/logo.bmp"

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

#include "gameStatus.h"

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
		SDL_Texture* m_Logo;
		SDL_Rect m_LogoPos;

		void CleanUp();
};

#endif
