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
	playerTex = new Texture("game/pic/mainGameScreenPlayer.png", Window::m_Renderer);
	playerTex->SetPositionAndSize(50, 50, 15, 15);

	//Init control flags
	upIsPushed = false;
	downIsPushed = false;
	leftIsPushed = false;
	rightIsPushed = false;

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
		playerTex->Move(0, -playerMoveSpeed);
	else if (downIsPushed)
		playerTex->Move(0, playerMoveSpeed);

	if (leftIsPushed && rightIsPushed)
		;
	else if (leftIsPushed)
		playerTex->Move(-playerMoveSpeed, 0);
	else if (rightIsPushed)
		playerTex->Move(playerMoveSpeed, 0);
}

void
Player::Render()
{
	playerTex->Render();
}

void
Player::CleanUp()
{
	delete playerTex;
	playerTex = NULL;
}
