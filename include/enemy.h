/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * enemy.h
 *
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <cmath>
#include <vector>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"

using namespace std;

typedef struct bullet* bulletPtr;
struct bullet
{
	int startX;
	int startY;
	float uniVectorX;
	float uniVectorY;
	SDL_Rect pos;
	int frameCount = 0;
	struct bullet* next = NULL;
};

class Enemy
{
	public:
		Enemy();
		~Enemy();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

	private:
		//Enemy parameters
		SDL_Texture* enemyPic;
		SDL_Rect enemyPos;

		SDL_Texture* bulletPic;
		vector<struct bullet> bulletList;

		bulletPtr firstBullet;

		int mouseX;
		int mouseY;

		void CleanUp();
};

#endif
