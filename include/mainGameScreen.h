/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * mainGameScreen.h
 *
 */

#ifndef MAINGAMESCREEN_H
#define MAINGAMESCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

#include "gameStatus.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStatusFlag gameStatusFlag;

class MainGameScreen: public GameStatus
{
	public:
		MainGameScreen();
		~MainGameScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		//Player parameters
		SDL_Texture* player;
		SDL_Rect playerPos;

		int playerMoveSpeed;

		int playerVelX;
		int playerVelY;

		//Bullet parameter
		SDL_Texture* bullet;
		SDL_Rect bulletPos;

		int nextToShot;

		int bulletMoveSpeed;

		bool bulletIsShot;

		//Keyborad status
		bool upIsPushed;
		bool downIsPushed;
		bool leftIsPushed;
		bool rightIsPushed;

		void CleanUp();

		//Event flag
		bool startTransfrom;
};

#endif
