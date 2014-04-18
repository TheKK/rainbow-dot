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

		static bool Init( char* windowTitle, float width, float height );

		static void Clear();
		static void Present();

		static void Quit();

		static SDL_Window* m_Window;
		static SDL_Renderer* m_Renderer;
	private:

		static float m_WindowAspect;

		static bool m_IsWindowed;
};

#endif
