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
	backgroundPic_= new Texture("game/pic/menuScreenBackground.png", Window::m_Renderer);

	title_[0] = new Texture("game/pic/menuScreenTitle1.png", Window::m_Renderer);
	title_[1] = new Texture("game/pic/menuScreenTitle2.png", Window::m_Renderer);
	title_[2] = new Texture("game/pic/menuScreenTitle3.png", Window::m_Renderer);

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

	backgroundPic_->RenderFullWindow();
	title_[currentTitle_]->RenderFullWindow();

	Window::Present();
}

void
MenuScreen::CleanUp()
{
	delete backgroundPic_;
	backgroundPic_ = NULL;
	
	for (int i = 0; i < 3; i++ ) {
		delete title_[i];
		title_[i] = NULL;
	}

}
