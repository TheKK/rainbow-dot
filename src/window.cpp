/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.cpp
 *
 */

#include "window.h"
SDL_Window* Window::m_Window;
SDL_Renderer* Window::m_Renderer;

SDL_Rect Window::m_WindowRect;

float Window::m_WindowAspect;
bool Window::m_IsWindowed;

Window::Window()
{
	m_IsWindowed = true;
	m_WindowAspect = 0;

	m_Window = NULL;
	m_Renderer = NULL;
}

Window::~Window()
{
	Quit();
}

bool
Window::Init(char* windowTitle, float width, float height)
{
	//Recored window aspect
	m_WindowAspect = width / height;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		fprintf(stderr, "SDL window error: %s\n", SDL_GetError());
		exit(1);
	}

	//Create and setup new SDL window, and check error
	m_Window = SDL_CreateWindow(
			windowTitle,					//Window title
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//Position where window appear
			width, height,					//Size of window
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

	//Make fullscreen fit out physical screen
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
Window::Present ()
{
	SDL_RenderPresent(m_Renderer);
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
