/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * player.cpp
 *
 */

#include "player.h"

Player::Player()
{
	//Init player parameters
	playerPic = SDLToolBox::LoadTexture("game/pic/mainGameScreenPlayer.png", Window::m_Renderer);
	playerPos = {
		.x = 50,
		.y = 50,
		.w = 15,
		.h = 15
	};

	playerMoveSpeed = 1;
}

Player::~Player()
{
	CleanUp();
}

void
Player::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_UP:
					upIsPushed = true;
					break;
				case SDLK_DOWN:
					downIsPushed = true;
					break;
				case SDLK_LEFT:
					leftIsPushed = true;
					break;
				case SDLK_RIGHT:
					rightIsPushed = true;
					break;
			}
			break;

		case SDL_KEYUP:
			switch (event->key.keysym.sym) {
				case SDLK_UP:
					upIsPushed = false;
					break;
				case SDLK_DOWN:
					downIsPushed = false;
					break;
				case SDLK_LEFT:
					leftIsPushed = false;
					break;
				case SDLK_RIGHT:
					rightIsPushed = false;
					break;
			}
			break;
	}
}

void
Player::Update()
{
	//Check key status to move player
	if (upIsPushed && downIsPushed)
		;
	else if (upIsPushed)
		playerPos.y += -playerMoveSpeed;
	else if (downIsPushed)
		playerPos.y += playerMoveSpeed;

	if (leftIsPushed && rightIsPushed)
		;
	else if (leftIsPushed)
		playerPos.x += -playerMoveSpeed;
	else if (rightIsPushed)
		playerPos.x += playerMoveSpeed;
}

void
Player::Render()
{
	SDL_RenderCopy(Window::m_Renderer, playerPic, NULL, &playerPos);
}

void
Player::CleanUp()
{
	SDL_DestroyTexture(playerPic);
	playerPic = NULL;
}
