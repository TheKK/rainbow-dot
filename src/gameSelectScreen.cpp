/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * gameSelectScreen.cpp
 *
 */

#include "gameSelectScreen.h"

GameSelectScreen::GameSelectScreen()
{
	//Load and set m_Background
	m_Background = SDLToolBox::LoadTexture("game/pic/gameSelectScreenBG.bmp", Window::m_Renderer);
}

GameSelectScreen::~GameSelectScreen()
{
	CleanUp();
}

void
GameSelectScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = GAME_QUIT;
			break;
	}
}

void
GameSelectScreen::Update()
{
}

void
GameSelectScreen::Render()
{
	Window::Clear();

	Window::Present();
}

void
GameSelectScreen::CleanUp()
{
	SDL_DestroyTexture(m_Background);

	m_Background = NULL;
}
