/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * prototypeScreen.cpp
 *
 */

#include "prototypeScreen.h"

PrototypeScreen::PrototypeScreen()
{
	m_TestPic = SDLToolBox::LoadTexture("game/pic/transfer.bmp", Window::m_Renderer);
	m_TestPicPos = {
		.x = 50,
		.y = 50,
		.w = 50,
		.h = 50
	};

	SDL_Rect buttonPos = {
		.x = 50,
		.y = 50,
		.w = 100,
		.h = 50
	};

	button = new Button();
	button->Init("game/pic/buttonOnTest.bmp", "game/pic/buttonOffTest.bmp", "", &buttonPos);
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
			gameStatusFlag = GAME_QUIT;
			break;

		case SDL_MOUSEMOTION:
			m_TestPicPos.x = (event->motion.x - m_TestPicPos.w / 2);
			m_TestPicPos.y = (event->motion.y - m_TestPicPos.h / 2);

			if (button->MouseHovered(event->motion.x, event->motion.y))
				button->ChangeState(BUTTON_HOVERED);
			else
				button->ChangeState(BUTTON_NORMAL);
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
	Window::Clear();

	button->Render();

	SDL_RenderCopy(Window::m_Renderer, m_TestPic, NULL, &m_TestPicPos);	

	Window::Present();
}

void
PrototypeScreen::CleanUp()
{
	SDL_DestroyTexture(m_TestPic);

	delete button;
}
