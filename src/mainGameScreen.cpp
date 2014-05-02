/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * mainGameScreen.cpp
 *
 */

#include "mainGameScreen.h"

MainGameScreen::MainGameScreen()
{
	//Init player parameters
	player = SDLToolBox::LoadTexture("game/pic/mainGameScreenPlayer.png", Window::m_Renderer);
	playerPos = {
		.x = 50,
		.y = 50,
		.w = 15,
		.h = 15 
	};

	playerMoveSpeed = 1;

	playerVelX = 0;
	playerVelY = 0;

	//Init bullet parameters
	bullet = SDLToolBox::LoadTexture("game/pic/mainGameScreenBullet.png", Window::m_Renderer);
	bulletPos = {
		.x = 0,
		.y = 0,
		.w = 3,
		.h = 6
	};

	bulletMoveSpeed = 10;

	bulletIsShot = false;

	//Init key status
	upIsPushed = false;
	downIsPushed = false;
	leftIsPushed = false;
	rightIsPushed = false;

	//Init special flags
	startTransfrom = false;
}

MainGameScreen::~MainGameScreen()
{
	CleanUp();
}

void
MainGameScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = GAME_QUIT;
			break;

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
				case SDLK_t:
					startTransfrom = true;
					break;
				case SDLK_z:
					if (!bulletIsShot) {
						bulletPos.x = playerPos.x + (playerPos.w / 2) - (bulletPos.w / 2);
						bulletPos.y = playerPos.y + bulletPos.h;
						bulletIsShot = true;
					}
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
MainGameScreen::Update()
{
	//Check key status to move player
	if (upIsPushed && downIsPushed)
		playerVelY = 0;
	else if (upIsPushed)
		playerVelY = -playerMoveSpeed;
	else if (downIsPushed)
		playerVelY = playerMoveSpeed;
	else
		playerVelY = 0;

	if (leftIsPushed && rightIsPushed)
		playerVelX = 0;
	else if (leftIsPushed)
		playerVelX = -playerMoveSpeed;
	else if (rightIsPushed)
		playerVelX = playerMoveSpeed;
	else
		playerVelX = 0;
	
	playerPos.x += playerVelX;
	playerPos.y += playerVelY;

	//Check bullet status to shot
	if (bulletIsShot) {
		if ((bulletPos.y -= bulletMoveSpeed) <= -bulletPos.h) {
			bulletIsShot = false;
		}
	}

	//Transform window
	if (startTransfrom) {
		static int frameCount = 0;

		if (frameCount++ < 140) {
			Window::Resize(GAME_WINDOW_WIDTH - frameCount, GAME_WINDOW_HEIGHT + frameCount);
		}
		else
			startTransfrom = false;
	}
}

void
MainGameScreen::Render()
{
	Window::Clear();

	//Render white background
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 0xcc);
	SDL_RenderFillRect(Window::m_Renderer, &Window::m_WindowRect);

	//Render player
	SDL_RenderCopy(Window::m_Renderer, player, NULL, &playerPos);

	//Render bullet
	if (bulletIsShot)
		SDL_RenderCopy(Window::m_Renderer, bullet, NULL, &bulletPos);

	Window::Present();
}

void
MainGameScreen::CleanUp()
{
	SDL_DestroyTexture(player);
	player = NULL;

	SDL_DestroyTexture(bullet);
	bullet = NULL;
}
