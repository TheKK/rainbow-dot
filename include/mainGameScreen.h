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

#include "gameStatus.h"
#include "player.h"
#include "enemy.h"

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

		//For lua to call
		static void AddBulletToPoll();
	private:
		Player player_;
		Enemy* enemy1_;
		Enemy* enemy2_;

		//Event flag
		bool startTransfrom_;

		//Bullet pool
		//vector<Bullet> bulletPoll;

		void CleanUp();
};

#endif
