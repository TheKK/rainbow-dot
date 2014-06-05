/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * enemy.cpp
 *
 */

#include "enemy.h"

Enemy::Enemy(char* enemyType)
{
	//Init player parameters
	enemyPic_ = new Texture("game/pic/mainGameScreenEnemy.png", Window::m_Renderer);
	enemyPic_->SetPositionAndSize(0, 0, 15, 15);

	lua_getglobal(ScriptManager::L, enemyType);
	if (lua_pcall(ScriptManager::L, 0, 1, 0) != 0) {
		fprintf(stderr, "Lua error while run function\n");
		exit(1);
	}

	//Make a Lua thread
	enemyMovePathScript_ = lua_tothread(ScriptManager::L, -1);
	if (enemyMovePathScript_ == NULL) {
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
	if (lua_status(enemyMovePathScript_) == LUA_OK || lua_status(enemyMovePathScript_) == LUA_YIELD)
		lua_resume(enemyMovePathScript_, NULL, 0);

	int x = lua_tointeger(enemyMovePathScript_, 1);
	int y = lua_tointeger(enemyMovePathScript_, 2);
	enemyPic_->MoveTo(x, y);

	lua_pop(enemyMovePathScript_, 2);
}

void
Enemy::Render()
{
	enemyPic_->Render();
}

const SDL_Rect*
Enemy::GetRect()
{
	return enemyPic_->GetRect();
}

void
Enemy::CleanUp()
{
	delete enemyPic_;
	enemyPic_ = NULL;
}
