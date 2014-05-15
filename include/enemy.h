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
#include <cstdio>
#include <vector>
#include <SDL.h>
#include <lua.hpp>

#include "global.h"
#include "window.h"
#include "SDLToolBox.h"
#include "scriptManager.h"

using namespace std;

class Enemy
{
	public:
		Enemy();
		~Enemy();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

		const SDL_Rect* GetRect();
	private:
		//Enemy parameters
		SDL_Texture* enemyPic;
		SDL_Rect enemyPos;

		//Lua state
		//lua_State* bulletGenerator;
		lua_State* enemyMovePathScript;

		void CleanUp();
};

#endif
