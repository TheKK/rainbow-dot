/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * game.h
 *
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include "window.h"
#include "timer.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void Execute();
	private:
		Window* pWindow;

		bool IsRunning;

		bool Init();

		void EventHandler( SDL_Event* event );
		void Update();
		void Render();
};

#endif
