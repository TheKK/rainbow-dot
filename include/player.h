/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * player.h
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "texture.h"

class Player
{
	public:
		Player();
		~Player();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		//Player texture
		Texture* playerTex;

		int playerMoveSpeed;

		//Keyborad status
		bool upIsPushed;
		bool downIsPushed;
		bool leftIsPushed;
		bool rightIsPushed;

		void CleanUp();
};

#endif
