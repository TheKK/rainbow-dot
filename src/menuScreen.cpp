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

	m_Title[0] = SDLToolBox::LoadTexture("game/pic/menuScreenTitle1.png", Window::m_Renderer);
	m_Title[1] = SDLToolBox::LoadTexture("game/pic/menuScreenTitle2.png", Window::m_Renderer);
	m_Title[2] = SDLToolBox::LoadTexture("game/pic/menuScreenTitle3.png", Window::m_Renderer);

	m_CurrentTitle = 0;
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

		case SDL_MOUSEBUTTONDOWN:
			gameIsRunning = false;
			gameStatusFlag = MAIN_GAME_SCREEN;
			break;
	}
}

void
MenuScreen::Update()
{
	static int frameCount = 0;

	if (++frameCount >= 15) {
		frameCount = 0;
		if (++m_CurrentTitle > 2)
			m_CurrentTitle = 0;
	}
}

void
MenuScreen::Render()
{
	Window::Clear();

	SDL_RenderCopy(Window::m_Renderer, m_Background, NULL, &Window::m_WindowRect);	
	SDL_RenderCopy(Window::m_Renderer, m_Title[m_CurrentTitle], NULL, &Window::m_WindowRect);	

	Window::Present();
}

void
MenuScreen::CleanUp()
{
	SDL_DestroyTexture(m_Background);
	m_Background = NULL;
	
	for (int i = 0; i < 3; i++ ) {
		SDL_DestroyTexture(m_Title[i]);
		m_Title[i] = NULL;
	}

}
