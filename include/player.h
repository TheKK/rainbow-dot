/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * player.h
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <SDL.h>

#include "global.h"
#include "window.h"
#include "texture.h"

enum MoveDirection
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

struct bulletPos
{
	int x;
	int y;
};

class Bullet
{
	public:
		Bullet(int X, int Y)
		{
			x = X;
			y = Y;
		}
		~Bullet()
		{
		}

		int x;
		int y;
};

class Player
{
	public:
		Player();
		~Player();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();

		void Move(enum MoveDirection moveDircection);
	private:
		//Player texture
		Texture playerTexture_ = Texture("game/pic/mainGameScreenPlayer.png", Window::m_Renderer);
		Texture bulletTexture_ = Texture("game/pic/playerBullet.png", Window::m_Renderer);

		int moveSpeed_ = 2;

		//Keyborad status
		bool upIsPushed_ = false;
		bool downIsPushed_ = false;
		bool leftIsPushed_ = false;
		bool rightIsPushed_ = false;

		//Player state
		bool isShooting_ = false;

		vector<Bullet>bulletPool_;

		void CleanUp();
};

#endif
