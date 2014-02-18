/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.h
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Window
{
	public:
		Window();
		~Window();

		bool Init( char* windowTitle, float width, float height );

		void Clear();
		void Present();

		void Quit();

		SDL_Window* GetWindow();
	private:
		//SDL window pointer
		SDL_Window* m_Window;
		//SDL renderer pointer
		SDL_Renderer* m_Renderer;

		float m_WindowAspect;

		bool m_IsWindowed;
};

#endif
