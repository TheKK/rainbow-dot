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
	backgroundPic_.LoadTexture("game/pic/menuScreenBackground.png", Window::m_Renderer);

	title_[0].LoadTexture("game/pic/menuScreenTitle1.png", Window::m_Renderer);
	title_[1].LoadTexture("game/pic/menuScreenTitle2.png", Window::m_Renderer);
	title_[2].LoadTexture("game/pic/menuScreenTitle3.png", Window::m_Renderer);

	currentTitle_ = 0;
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
		if (++currentTitle_ > 2)
			currentTitle_ = 0;
	}
}

void
MenuScreen::Render()
{
	Window::Clear();

	backgroundPic_.RenderFullWindow();
	title_[currentTitle_].RenderFullWindow();

	Window::Present();
}

void
MenuScreen::CleanUp()
{
}
