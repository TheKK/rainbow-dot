/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * startScreen.cpp
 *
 */

#include "startScreen.h"

StartScreen::StartScreen()
{
	m_Logo = SDLToolBox::LoadTexture(LOGO_PATH, Window::m_Renderer);

	m_LogoPos.x = 0;
	m_LogoPos.y = 0;
	m_LogoPos.w = GAME_WINDOW_WIDTH;
	m_LogoPos.h = GAME_WINDOW_HEIGHT;
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
	else if (frameCount > 150){
		gameIsRunning = false;
		gameStatusFlag = MENU_SCREEN;
	}

	SDL_SetTextureAlphaMod(m_Logo, alpha);

	frameCount++;
}

void
StartScreen::Render()
{
	Window::Clear();

	//Draw white background
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 255);
	SDL_RenderFillRect(Window::m_Renderer, &m_LogoPos);

	//Paste logo
	SDL_RenderCopy(Window::m_Renderer, m_Logo, NULL, &m_LogoPos);	

	Window::Present();
}

void
StartScreen::CleanUp()
{
	SDL_DestroyTexture(m_Logo);

	m_Logo = NULL;
}
