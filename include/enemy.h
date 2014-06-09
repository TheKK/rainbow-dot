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
#include "scriptManager.h"

#include "texture.h"

using namespace std;

class Enemy
{
	public:
		Enemy();
		Enemy(char* enemyProfile);
		~Enemy();

		int LoadEnemyProfile(char* enemyPorfile);

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

		const SDL_Rect* GetRect();
	private:
		//Enemy parameters
		Texture enemyPic_;

		//Lua state
		//lua_State* bulletGenerator;
		lua_State* enemyMovePathScript_;

		void CleanUp();
};

#endif
