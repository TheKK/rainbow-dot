/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * startScreen.cpp
 *
 */

#include "startScreen.h"

StartScreen::StartScreen()
{
	logoPic_ = new Texture("game/pic/logo.bmp", Window::m_Renderer);
}

StartScreen::~StartScreen()
{
	CleanUp();
}

void
StartScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = GAME_QUIT;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_RETURN:
				case SDLK_ESCAPE:
					gameIsRunning = false;
					gameStatusFlag = MENU_SCREEN;
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT) {
				gameIsRunning = false;
				gameStatusFlag = MENU_SCREEN;
			}
			break;
	}
}

void
StartScreen::Update()
{
	static int frameCount = 0;
	static unsigned int alpha = 0;

	if (frameCount <= 60)
		alpha = 255 * frameCount / 60;
	else if (frameCount <= 90)
		;
	else if (frameCount <= 150)
		alpha = 255 - (255 * (frameCount - 90) / 60);
	else if (frameCount > 180) {
		gameIsRunning = false;
		gameStatusFlag = MENU_SCREEN;
	}

	logoPic_->SetAlpha(alpha);

	frameCount++;
}

void
StartScreen::Render()
{
	Window::Clear();

	//Draw white background
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 255);
	SDL_RenderFillRect(Window::m_Renderer, NULL);

	//Paste logo
	logoPic_->RenderFullWindow();

	Window::Present();
}

void
StartScreen::CleanUp()
{
	delete logoPic_;
	logoPic_ = NULL;
}
