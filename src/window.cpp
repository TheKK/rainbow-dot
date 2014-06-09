/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.cpp
 *
 */

#include "window.h"

//Static variable members
SDL_Window* Window::m_Window;
SDL_Renderer* Window::m_Renderer;

SDL_Rect Window::m_WindowRect;

bool Window::m_IsWindowed;

Window::Window()
{
	m_IsWindowed = true;

	m_Window = NULL;
	m_Renderer = NULL;
}

Window::~Window()
{
	Quit();
}

bool
Window::Init(const char* windowTitle, int width, int height)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		fprintf(stderr, "SDL window error: %s\n", SDL_GetError());
		exit(1);
	}

	//Create and setup new SDL window, and check error
	m_Window = SDL_CreateWindow(
			windowTitle,					//Window title
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//Position where window appear
			width * 2, height * 2,				//Size of window
			SDL_WINDOW_SHOWN			 	//SDL window flags
			);
	if (m_Window == NULL){
		fprintf(stderr, "SDL window error: %s\n", SDL_GetError());
		exit(1);
	}

	//Create and setup new SDL renderer, and check error
	m_Renderer = SDL_CreateRenderer(
			m_Window,			//For which window
			-1,				//The index of rendering driver to initialize
			SDL_RENDERER_ACCELERATED	//SDL renderer flags
			);
	if (m_Renderer == NULL){
		//fprintf( stderr, "SDL renderer error: %s\n" SDL_GetError() );
		fprintf(stderr, "SDL renderer error: %s\n", SDL_GetError());
		exit(1);
	}

	//Make fullscreen fit physical screen
	SDL_RenderSetLogicalSize(m_Renderer, width, height);

	m_WindowRect = {
		.x = 0,
		.y = 0,
		.w = width,
		.h = height
	};	

	srand(time(NULL));

	return true;
}

void
Window::Clear()
{
	SDL_SetRenderDrawColor(m_Renderer, 51, 51, 51, 255);
	SDL_RenderClear(m_Renderer);
}

void
Window::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void
Window::Resize(int width, int height)
{
	SDL_SetWindowSize(m_Window, width * 2, height * 2);
	SDL_RenderSetLogicalSize(m_Renderer, width, height);
	m_WindowRect = {
		.x = 0,
		.y = 0,
		.w = width,
		.h = height
	};	
}

int
Window::X()
{
	return m_WindowRect.x;
}


int
Window::Y()
{
	return m_WindowRect.y;
}

int
Window::Width()
{
	return m_WindowRect.w;
}

int
Window::Height()
{
	return m_WindowRect.h;
}

const SDL_Rect*
Window::GetWindowRect()
{
	return &m_WindowRect;
}

void
Window::Quit()
{
	SDL_DestroyWindow(m_Window);
	m_Window = NULL;

	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = NULL;

	SDL_Quit();
}
