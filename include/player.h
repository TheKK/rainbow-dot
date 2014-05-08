/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * player.h
 *
 */

#ifndef PLAYER_H
#define PlAYER_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

class Player
{
	public:
		Player();
		~Player();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		//Player parameters
		SDL_Texture* playerPic;
		SDL_Rect playerPos;

		int playerMoveSpeed;

		int playerVelX;
		int playerVelY;

		//Keyborad status
		bool upIsPushed;
		bool downIsPushed;
		bool leftIsPushed;
		bool rightIsPushed;

		void CleanUp();
};

#endif
