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

	//Load and set m_TransferPic
	m_TransferPic = SDLToolBox::LoadTexture("game/pic/transfer1.bmp", Window::m_Renderer);

	m_TransferPicClip.x = 0;
	m_TransferPicClip.y = 0;
	m_TransferPicClip.w = GAME_WINDOW_WIDTH;
	m_TransferPicClip.h = GAME_WINDOW_HEIGHT;

	gameStatusMode = GAME_TRANSFER_IN;
}

GameSelectScreen::~GameSelectScreen()
{
	CleanUp();
}

void
GameSelectScreen::EventHandler(SDL_Event* event)
{
	//Not in trasfer animation
	if (gameStatusMode == GAME_NORMAL) {
		switch (event->type) {
			case SDL_QUIT:
				gameIsRunning = false;
				gameStatusFlag = GAME_QUIT;
				break;
		}
	}
}

void
GameSelectScreen::Update()
{
	if (gameStatusMode == GAME_TRANSFER_IN) {
		if ((m_TransferPicClip.x += 50) >= (GAME_WINDOW_WIDTH * 2)) {
			m_TransferPicClip.x = GAME_WINDOW_WIDTH;

			gameStatusMode = GAME_NORMAL;
		}
	}
}

void
GameSelectScreen::Render()
{
	Window::Clear();

	SDL_RenderCopy(Window::m_Renderer, m_Background, NULL, &Window::m_WindowRect);	

	if (gameStatusMode == GAME_TRANSFER_IN)
		SDL_RenderCopy(Window::m_Renderer, m_TransferPic, &m_TransferPicClip, &Window::m_WindowRect);	

	Window::Present();
}

void
GameSelectScreen::CleanUp()
{
	SDL_DestroyTexture(m_Background);
	SDL_DestroyTexture(m_TransferPic);

	m_Background = NULL;
	m_TransferPic = NULL;
}
