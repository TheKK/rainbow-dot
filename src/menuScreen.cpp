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
	m_Background = SDLToolBox::LoadTexture("game/pic/menuScreenBackground.png", Window::m_Renderer);
}

MenuScreen::~MenuScreen()
{
	CleanUp();
}

void
MenuScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = GAME_QUIT;
			break;
	}
}

void
MenuScreen::Update()
{
}

void
MenuScreen::Render()
{
	Window::Clear();

	SDL_RenderCopy(Window::m_Renderer, m_Background, NULL, &Window::m_WindowRect);	

	Window::Present();
}

void
MenuScreen::CleanUp()
{
	SDL_DestroyTexture(m_Background);

	m_Background = NULL;
}
