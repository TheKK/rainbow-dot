/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * button.cpp
 *
 */

#include "button.h"

Button::Button()
{
	m_CurrentButtonState = NULL;

	for (int i = 0; i < 3; i++ )
		m_ButtonPicture[i] = NULL;
}

Button::~Button()
{
	CleanUp();
}

void
Button::Init(string buttonNormal, string buttonHovered, string buttonPushed, SDL_Rect* buttonPos )
{
	//Load button picture for each state
	if (buttonNormal != "")
		m_ButtonPicture[0] = SDLToolBox::LoadTexture(buttonNormal, Window::m_Renderer);

	if (buttonHovered != "")
		m_ButtonPicture[1] = SDLToolBox::LoadTexture(buttonHovered, Window::m_Renderer);

	if (buttonPushed != "")
		m_ButtonPicture[2] = SDLToolBox::LoadTexture(buttonPushed, Window::m_Renderer);

	//Set current state as normal state
	m_CurrentButtonState = m_ButtonPicture[0];

	//Set up button position
	m_ButtonPos = *buttonPos;
}

void
Button::Render()
{
	SDL_RenderCopy(Window::m_Renderer, m_CurrentButtonState, NULL, &m_ButtonPos);
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
Button::ChangeState(enum ButtonState buttonState)
{
	switch (buttonState){
		case BUTTON_NORMAL:
			m_CurrentButtonState = m_ButtonPicture[0];
			break;

		case BUTTON_HOVERED:
			m_CurrentButtonState = m_ButtonPicture[1];
			break;

		case BUTTON_PUSHED:
			m_CurrentButtonState = m_ButtonPicture[2];
			break;
	}
}

void
Button::CleanUp()
{
	m_CurrentButtonState = NULL;

	for (int i = 0; i < 3; i++ ){
		if (m_ButtonPicture[i] != NULL)
			SDL_DestroyTexture(m_ButtonPicture[i]);
	}
}
