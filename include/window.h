/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.h
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>

using namespace std;

class Window
{
	public:
		Window();
		~Window();

		static bool Init(const char* windowTitle, int width, int height);

		static void Clear();
		static void Present();

		static void Resize(int width, int height);

		static int X();
		static int Y();
		static int Width();
		static int Height();

		static const SDL_Rect* GetWindowRect();

		static void Quit();

		//SDL_Window and SDL_Renderer
		static SDL_Window* m_Window;
		static SDL_Renderer* m_Renderer;
	private:
		//Store game window's size
		static SDL_Rect m_WindowRect;

		static bool m_IsWindowed;
};

#endif
