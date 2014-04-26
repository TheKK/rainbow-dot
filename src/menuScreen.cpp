/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * menuScreen.cpp
 *
 */

#include "menuScreen.h"

MenuScreen::MenuScreen()
{
	//Load and set m_Logo
	m_Background = SDLToolBox::LoadTexture("game/pic/menuBG.bmp", Window::m_Renderer);

	//Load and set m_TransferPic
	m_TransferPic = SDLToolBox::LoadTexture("game/pic/transfer.bmp", Window::m_Renderer);

	m_TransferPicClip.x = 0;
	m_TransferPicClip.y = 0;
	m_TransferPicClip.w = GAME_WINDOW_WIDTH;
	m_TransferPicClip.h = GAME_WINDOW_HEIGHT;

	gameStatusMode = GAME_NORMAL;
}

MenuScreen::~MenuScreen()
{
	CleanUp();
}

void
MenuScreen::EventHandler(SDL_Event* event)
{
	//Not in trasfer animation
	if (gameStatusMode == GAME_NORMAL) {
		switch (event->type) {
			case SDL_QUIT:
				gameIsRunning = false;
				gameStatusFlag = GAME_QUIT;
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (event->button.button == SDL_BUTTON_LEFT) {
					gameStatusMode = GAME_TRANSFER_OUT;
				}
		}
	}
}

void
MenuScreen::Update()
{
	if (gameStatusMode == GAME_TRANSFER_OUT) {
		if ((m_TransferPicClip.x += 50) >= (GAME_WINDOW_WIDTH * 2)) {
			m_TransferPicClip.x = GAME_WINDOW_WIDTH * 2;

			gameIsRunning = false;
			gameStatusFlag = GAME_SELECT_SCREEN;
		}
	}
}

void
MenuScreen::Render()
{
	Window::Clear();

	SDL_RenderCopy(Window::m_Renderer, m_Background, NULL, &Window::m_WindowRect);	

	if (gameStatusMode == GAME_TRANSFER_OUT)
		SDL_RenderCopy(Window::m_Renderer, m_TransferPic, &m_TransferPicClip, &Window::m_WindowRect);	

	Window::Present();
}

void
MenuScreen::CleanUp()
{
	SDL_DestroyTexture(m_Background);
	SDL_DestroyTexture(m_TransferPic);

	m_Background = NULL;
	m_TransferPic = NULL;
}
