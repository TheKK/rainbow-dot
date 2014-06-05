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

#include "texture.h"
#include "gameStatus.h"

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
		Texture* backgroundPic_;

		int currentTitle_;
		Texture* title_[3];

		void CleanUp();
};

#endif
