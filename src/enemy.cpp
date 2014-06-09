/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * enemy.cpp
 *
 */

#include "enemy.h"

Enemy::Enemy(char* enemyProfile)
{
	LoadEnemyProfile(enemyProfile);
}

Enemy::~Enemy()
{
	CleanUp();
}

int
Enemy::LoadEnemyProfile(char* enemyProfile)
{
	//Init player parameters
	enemyPic_.LoadTexture("game/pic/mainGameScreenEnemy.png", Window::m_Renderer);

	lua_getglobal(ScriptManager::L, enemyProfile);
	if (lua_pcall(ScriptManager::L, 0, 1, 0) != 0) {
		fprintf(stderr, "Lua error while run function\n");
		return -1;
	}

	//Make a Lua thread
	enemyMovePathScript_ = lua_tothread(ScriptManager::L, -1);
	if (enemyMovePathScript_ == NULL) {
		fprintf(stderr, "This is not a thread\n");
		return -1;
	}

	return 0;
}

void
Enemy::EventHandler(SDL_Event* event)
{
}

void
Enemy::Update()
{
	if (lua_status(enemyMovePathScript_) == LUA_OK || lua_status(enemyMovePathScript_) == LUA_YIELD)
		lua_resume(enemyMovePathScript_, NULL, 0);

	int x = lua_tointeger(enemyMovePathScript_, 1);
	int y = lua_tointeger(enemyMovePathScript_, 2);
	enemyPic_.MoveTo(x, y);

	lua_pop(enemyMovePathScript_, 2);
}

void
Enemy::Render()
{
	enemyPic_.Render();
}

const SDL_Rect*
Enemy::GetRect()
{
	return enemyPic_.GetRect();
}

void
Enemy::CleanUp()
{
}
