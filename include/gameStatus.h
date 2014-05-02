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
		GameStatus(){};
		virtual ~GameStatus(){};

		virtual void EventHandler(SDL_Event* event){};
		virtual void Update(){};
		virtual void Render(){};

	private:
};

#endif
