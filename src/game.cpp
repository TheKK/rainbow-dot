/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * game.cpp
 *
 */

#include "game.h"

Game::Game ()
{
	pWindow = NULL;
	
	IsRunning = true;
}

Game::~Game ()
{
	delete pWindow;
}

void
Game::Execute ()
{
	//Init our game
	if( Init() == false )
		IsRunning = false;

	//pWindow->Present();
	
	//SDL_Delay( 3000 );
	
	Timer* timer = new Timer();	
	SDL_Event event;

	while( IsRunning ){
		//Start timer
		timer->Start();

		EventHandler( &event );

		Update();

		Render();

		//Use timer to limit max frame rate per second( FPS )
		if( timer->GetTicks() < 1000 / 60 )
			SDL_Delay( ( 1000 / 60 ) - timer->GetTicks() );
	}
}

bool
Game::Init ()
{
	bool flag;

	//Create window class
	pWindow = new Window();

	int width = 500;
	int height = 500;
	char* title = "Rainbow Dot";

	flag = pWindow->Init( title, width, height );
	if( flag == false )
		return false;
	
	return true;
}

void
Game::EventHandler ( SDL_Event* event )
{
	while( SDL_PollEvent( event ) ){
		if( event->type == SDL_QUIT )
			IsRunning = false;
	}
}

void
Game::Update ()
{
}

void
Game::Render ()
{
	pWindow->Clear();
	
	/*
	 * Render stuff
	 */

	pWindow->Present();	
}
