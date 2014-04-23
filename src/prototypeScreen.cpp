/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * prototypeScreen.cpp
 *
 */

#include "prototypeScreen.h"

PrototypeScreen::PrototypeScreen()
{
	m_TestPic = SDLToolBox::LoadTexture("game/pic/redSquare.bmp", Window::m_Renderer);
	m_TestPicPos = {
		.x = 50,
		.y = 50,
		.w = 50,
		.h = 50
	};
}

PrototypeScreen::~PrototypeScreen()
{
	CleanUp();
}

void
PrototypeScreen::EventHandler(SDL_Event* event)
{
	switch (event->type){
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = gameQuit;
			break;

		case SDL_MOUSEMOTION:
			m_TestPicPos.x = (event->motion.x - m_TestPicPos.w / 2);
			m_TestPicPos.y = (event->motion.y - m_TestPicPos.h / 2);
			break;
	}
}

void
PrototypeScreen::Update()
{
}

void
PrototypeScreen::Render()
{
	SDL_SetRenderDrawColor(Window::m_Renderer, 51, 51, 51, 10);
	SDL_RenderClear(Window::m_Renderer);

	SDL_RenderCopy(Window::m_Renderer, m_TestPic, NULL, &m_TestPicPos);	

	Window::Present();
}

void
PrototypeScreen::CleanUp()
{
	SDL_DestroyTexture(m_TestPic);
}
