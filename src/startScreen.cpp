/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * startScreen.cpp
 *
 */

#include "startScreen.h"

StartScreen::StartScreen()
{
	m_Logo = SDLToolBox::LoadTexture( LOGO_PATH, Window::m_Renderer );

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
StartScreen::EventHandler( SDL_Event* event )
{
	switch( event->type ){
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = gameQuit;
			break;

		case SDL_KEYDOWN:
			switch( event->key.keysym.sym ){
				case SDLK_c:
			}
	}
}

void
StartScreen::Update()
{
}

void
StartScreen::Render()
{
	Window::Clear();

	SDL_RenderCopy( Window::m_Renderer, m_Logo, NULL, &m_LogoPos );	

	Window::Present();
}

void
StartScreen::CleanUp()
{
	SDL_DestroyTexture( m_Logo );
	//SDL_DestroyTexture( m_Picture );
}
