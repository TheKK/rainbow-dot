/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.cpp
 *
 */

#include "window.h"

Window::Window ()
{
	m_IsWindowed = true;
	m_WindowAspect = 0;

	m_Window = NULL;
	m_WindowSurface = NULL;
}

Window::~Window ()
{
	Quit();
}

bool
Window::Init ( char* windowTitle, int width, int height )
{
	//Recored window aspect
	m_WindowAspect = ( float )width / ( float )height;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
		return false;

	//Create and setup new SDL window, and check error
	m_Window = SDL_CreateWindow(
			windowTitle,					//Window title
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//Position of window
			width, height,					//Size of window
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE		//Window flags
			);
	if( m_Window == NULL ){
		fprintf( stderr, "SDL error: %s\n", SDL_GetError() );
		return false;
	}

	m_WindowSurface = SDL_GetWindowSurface( m_Window );

	//Lock mouse
	//SDL_SetRelativeMouseMode( SDL_TRUE );

	srand( time( NULL ) );

	return true;
}

void
Window::Clear ()
{
}

void
Window::Present ()
{
	SDL_UpdateWindowSurface( m_Window );
}

void
Window::Quit ()
{
	SDL_DestroyWindow( m_Window );
	m_Window = NULL;

	SDL_Quit();
}

SDL_Window*
Window::GetWindow ()
{
	return m_Window;
}
