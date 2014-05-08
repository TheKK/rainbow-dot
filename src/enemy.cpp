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
		.x = 50,
		.y = 50,
		.w = 15,
		.h = 15
	};

	bulletPic = SDLToolBox::LoadTexture("game/pic/enemyBullet1.png", Window::m_Renderer);

	mouseX = 0;
	mouseY = 0;
}

Enemy::~Enemy()
{
	CleanUp();
}

void
Enemy::EventHandler(SDL_Event* event)
{
	if (event->type == SDL_MOUSEMOTION) {
		mouseX = event->motion.x;
		mouseY = event->motion.y;
	}
}

void
Enemy::Update()
{
	//bulletPtr newBullet = new struct bullet;
	struct bullet newBullet;
	newBullet.startX = 100;
	newBullet.startY = 10;

	double length = (double)sqrt(pow(mouseX - 100, 2) + pow(mouseY - 10, 2));
	newBullet.uniVectorX = (double)(mouseX - 100) / length;
	newBullet.uniVectorY = (double)(mouseY - 10) / length;
	newBullet.pos.w = 10;
	newBullet.pos.h = 10;

	//Insert into bulletList
	bulletList.push_back(newBullet);

	for (vector<struct bullet>::size_type i = 0; i < bulletList.size(); i++) {
		bulletList[i].frameCount++;
		bulletList[i].uniVectorY += 0.01;
		bulletList[i].pos.x = bulletList[i].startX + bulletList[i].uniVectorX * bulletList[i].frameCount * 2;
		bulletList[i].pos.y = bulletList[i].startY + bulletList[i].uniVectorY * bulletList[i].frameCount * 2;

		//If bullet if out of screen
		if (SDL_HasIntersection(&bulletList[i].pos, &Window::m_WindowRect) == SDL_FALSE)
			bulletList.erase(bulletList.begin() + i);
	}
}

void
Enemy::Render()
{
	for (vector<struct bullet>::size_type i = 0; i < bulletList.size(); i++)
		SDL_RenderCopy(Window::m_Renderer, bulletPic, NULL, &bulletList[i].pos);

	SDL_RenderCopy(Window::m_Renderer, enemyPic, NULL, &enemyPos);
}

void
Enemy::CleanUp()
{
	SDL_DestroyTexture(enemyPic);
	enemyPic = NULL;

	SDL_DestroyTexture(bulletPic);
	bulletPic = NULL;

	bulletList.clear();
}
