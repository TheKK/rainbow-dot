/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * window.cpp
 *
 */

#include "window.h"
SDL_Window* Window::m_Window;
SDL_Renderer* Window::m_Renderer;

float Window::m_WindowAspect;
bool Window::m_IsWindowed;

Window::Window ()
{
	m_IsWindowed = true;
	m_WindowAspect = 0;

	m_Window = NULL;
	m_Renderer = NULL;
}

Window::~Window ()
{
	Quit();
}

bool
Window::Init ( string windowTitle, float width, float height )
{
	//Recored window aspect
	m_WindowAspect = width / height;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
		fprintf( stderr, "SDL window error: %s\n", SDL_GetError() );
		exit( 1 );
	}


	//Set texture filtering to linear
	if( SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "linear" ) == false )
		fprintf( stderr, "Warning: Linear textrue filtering not enableed\n" );

	//Create and setup new SDL window, and check error
	m_Window = SDL_CreateWindow(
			windowTitle.c_str(),					//Window title
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,	//Position where window appear
			width, height,					//Size of window
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE		//SDL window flags
			);
	if( m_Window == NULL ){
		fprintf( stderr, "SDL window error: %s\n", SDL_GetError() );
		exit( 1 );
	}

	//Create and setup new SDL renderer, and check error
	m_Renderer = SDL_CreateRenderer(
			m_Window,			//For which window
			-1,				//The index of rendering driver to initialize
			SDL_RENDERER_ACCELERATED	//SDL renderer flags
			);
	if( m_Renderer == NULL ){
		//fprintf( stderr, "SDL renderer error: %s\n" SDL_GetError() );
		fprintf( stderr, "SDL renderer error: %s\n", SDL_GetError() );
		exit( 1 );
	}

	srand( time( NULL ) );

	return true;
}

void
Window::Clear ()
{
	SDL_SetRenderDrawColor( m_Renderer, 51, 51, 51, 255 );
	SDL_RenderClear( m_Renderer );
}

void
Window::Present ()
{
	SDL_RenderPresent( m_Renderer );
}

void
Window::Quit ()
{
	SDL_DestroyWindow( m_Window );
	m_Window = NULL;

	SDL_DestroyRenderer( m_Renderer );
	m_Renderer = NULL;

	SDL_Quit();
}
