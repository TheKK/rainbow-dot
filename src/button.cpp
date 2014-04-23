/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * button.cpp
 *
 */

#include "button.h"

Button::Button()
{
	m_ButtonOnPicture = NULL;
	m_ButtonOffPicture = NULL;

	m_IsSelect = false;
}

Button::~Button()
{
	CleanUp();
}

void
Button::Init(string buttonOnPicture, string buttonOffPicture, int buttonPosX, int buttonPosY, int buttonWidth, int buttonHeight)
{
	m_ButtonOnPicture = SDLToolBox::LoadTexture(buttonOnPicture, Window::m_Renderer);
	m_ButtonOffPicture = SDLToolBox::LoadTexture(buttonOffPicture, Window::m_Renderer);

	m_ButtonPos.x = buttonPosX;
	m_ButtonPos.y = buttonPosY;
	m_ButtonPos.w = buttonWidth;
	m_ButtonPos.h = buttonHeight;
}

void
Button::EventHandler(SDL_Event* event)
{
	switch (event->type){
		case SDL_MOUSEMOTION:
			if (MouseHovered(event->motion.x, event->motion.y))
				ButtonOn();
			else
				ButtonOff();
			break;
	}
}

void
Button::Update()
{
}

void
Button::Render()
{
	if (m_IsSelect)
		SDL_RenderCopy(Window::m_Renderer, m_ButtonOnPicture, NULL, &m_ButtonPos);
	else
		SDL_RenderCopy(Window::m_Renderer, m_ButtonOffPicture, NULL, &m_ButtonPos);
}

void
Button::ButtonOn()
{
	m_IsSelect = true;
}

void
Button::ButtonOff()
{
	m_IsSelect = false;
}

void
Button::ButtonToggle()
{
	m_IsSelect = !m_IsSelect;
}

bool
Button::MouseHovered(int mousePosX, int mousePosY)
{
	if (
			mousePosX < (m_ButtonPos.x + m_ButtonPos.w) &&
			mousePosX > m_ButtonPos.x &&
			mousePosY < (m_ButtonPos.y + m_ButtonPos.h) &&
			mousePosY > m_ButtonPos.y
	   )
		return true;
	else
		return false;
}

void
Button::CleanUp()
{
	SDL_DestroyTexture(m_ButtonOnPicture);
	SDL_DestroyTexture(m_ButtonOffPicture);
}
