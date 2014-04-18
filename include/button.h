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
#include <SDL2/SDL.h>

#include "global.h"
#include "SDLToolBox.h"
#include "window.h"

using namespace std;

class Button
{
	public:
		Button();
		~Button();

		void Init(
				string buttonOnPicture,
				string buttonOffPicture,
				int buttonPosX, int buttonPosY,
				int buttonWidth, int buttonHeight
			 );

		void EventHandler( SDL_Event* event );
		void Update();
		void Render();

		void ButtonOn();
		void ButtonOff();
		void ButtonToggle();

	private:
		SDL_Texture* m_ButtonOnPicture;
		SDL_Texture* m_ButtonOffPicture;

		SDL_Rect m_ButtonPos;

		bool m_IsSelect;

		bool MouseHovered( int mousePosX, int mousePosY );
		void CleanUp();

};

#endif
