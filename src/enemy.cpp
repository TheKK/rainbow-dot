/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * enemy.cpp
 *
 */

#include "enemy.h"

Enemy::Enemy()
{
	//Init player parameters
	enemyPic = SDLToolBox::LoadTexture("game/pic/mainGameScreenEnemy.png", Window::m_Renderer);
	enemyPos = {
		.x = 0,
		.y = 0,
		.w = 15,
		.h = 15
	};

	lua_getglobal(ScriptManager::L, "testEnemy");
	if (lua_pcall(ScriptManager::L, 0, 1, 0) != 0) {
		fprintf(stderr, "Lua error while run function\n");
		exit(1);
	}

	enemyMovePathScript = lua_tothread(ScriptManager::L, -1);
	if (enemyMovePathScript == NULL) {
		fprintf(stderr, "This is not a thread\n");
		exit(1);
	}
}

Enemy::~Enemy()
{
	CleanUp();
}

void
Enemy::EventHandler(SDL_Event* event)
{
}

void
Enemy::Update()
{
	if (lua_status(enemyMovePathScript) == LUA_OK || lua_status(enemyMovePathScript) == LUA_YIELD)
		lua_resume(enemyMovePathScript, NULL, 0);

	enemyPos.x = lua_tointeger(enemyMovePathScript, 1);
	enemyPos.y = lua_tointeger(enemyMovePathScript, 2);

	lua_pop(enemyMovePathScript, 2);
}

void
Enemy::Render()
{
	SDL_RenderCopy(Window::m_Renderer, enemyPic, NULL, &enemyPos);
}

const SDL_Rect*
Enemy::GetRect()
{
	return &enemyPos;
}

void
Enemy::CleanUp()
{
	SDL_DestroyTexture(enemyPic);
	enemyPic = NULL;
}
