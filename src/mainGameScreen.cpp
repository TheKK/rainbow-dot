/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * mainGameScreen.cpp
 *
 */

#include "mainGameScreen.h"

MainGameScreen::MainGameScreen()
{
	player = new Player();
	enemy = new Enemy();

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
	}

	player->EventHandler(event);
	enemy->EventHandler(event);
}

void
MainGameScreen::Update()
{
	player->Update();

	enemy->Update();

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
	player->Render();

	//Render enemy
	enemy->Render();

	Window::Present();
}

void
MainGameScreen::CleanUp()
{
	delete player;
	player = NULL;

	delete enemy;
	enemy = NULL;
}
