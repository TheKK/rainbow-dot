/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * gameStatus.h
 *
 */

#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <iostream>
#include <SDL.h>

using namespace std;

class GameStatus
{
	public:
		virtual void EventHandler(SDL_Event* event) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
	private:
};

#endif
