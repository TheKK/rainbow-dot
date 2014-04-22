/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * menuScreen.cpp
 *
 */

#include "menuScreen.h"

MenuScreen::MenuScreen()
{
	m_Logo = SDLToolBox::LoadTexture("game/pic/menuBG.bmp", Window::m_Renderer);

	m_LogoPos.x = 0;
	m_LogoPos.y = 0;
	m_LogoPos.w = GAME_WINDOW_WIDTH;
	m_LogoPos.h = GAME_WINDOW_HEIGHT;
}

MenuScreen::~MenuScreen()
{
	CleanUp();
}

void
MenuScreen::EventHandler(SDL_Event* event)
{
	switch(event->type){
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = gameQuit;
			break;

		case SDL_KEYDOWN:
			switch(event->key.keysym.sym){
			}
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

	//Paste logo
	SDL_RenderCopy(Window::m_Renderer, m_Logo, NULL, &m_LogoPos);	

	Window::Present();
}

void
MenuScreen::CleanUp()
{
	SDL_DestroyTexture(m_Logo);
}
