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

		bool Init( char* windowTitle, int width, int height );

		void Clear();
		void Present();

		void Quit();

		SDL_Window* GetWindow();
	private:
		//SDL window
		SDL_Window* m_Window;
		SDL_Surface* m_WindowSurface;

		float m_WindowAspect;

		bool m_IsWindowed;
};

#endif
