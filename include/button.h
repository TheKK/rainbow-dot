/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * button.h
 *
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <cstdio>
#include <string>
#include <SDL.h>

#include "global.h"
#include "SDLToolBox.h"
#include "window.h"

using namespace std;

enum ButtonState
{
	BUTTON_NORMAL = 0,
	BUTTON_HOVERED,
	BUTTON_PUSHED
};

class Button
{
	public:
		Button();
		~Button();

		void Init(
				string buttonNormal,
				string buttonHovered,
				string buttonPushed,
				SDL_Rect* posAndSize
			 );

		void Render();

		bool MouseHovered(int mousePosX, int mousePosY);

		void ChangeState(enum ButtonState buttonState);

	private:
		//Point out what button picture we should render
		SDL_Texture* m_CurrentButtonState;

		SDL_Texture* m_ButtonPicture[3];
		SDL_Rect m_ButtonPos;

		void CleanUp();
};

#endif
