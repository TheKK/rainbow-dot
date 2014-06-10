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

	SDL_Color color = {0, 0, 0};
	label.LoadFontAndText(
			"game/fonts/hachicro/hachicro.TTF", 8, "PRESS ANY BUTTON TO START", color,
			Window::m_Renderer
			);
	label.MoveTo(70, 135);

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

		case SDL_KEYDOWN:
			if (event->key.keysym.sym == SDLK_RETURN)
		case SDL_MOUSEBUTTONDOWN:
			gameIsRunning = false;
			gameStatusFlag = MAIN_GAME_SCREEN;
			break;
	}
}

void
MenuScreen::Update()
{
	static int titleFrameCount = 0;
	static int labelFrameCount = 0;

	//For title image changing
	if (++titleFrameCount >= 15) {
		titleFrameCount = 0;
		if (++currentTitle_ > 2)
			currentTitle_ = 0;
	}

	//For text label changing
	labelFrameCount++;
	if (labelFrameCount == 90)
		label.SetAlpha(0);

	if (labelFrameCount == 120) {
		label.SetAlpha(255);
		labelFrameCount = 0;
	}

		
}

void
MenuScreen::Render()
{
	Window::Clear();

	backgroundPic_.RenderFullWindow();
	title_[currentTitle_].RenderFullWindow();

	label.Render();

	Window::Present();
}

void
MenuScreen::CleanUp()
{
}
