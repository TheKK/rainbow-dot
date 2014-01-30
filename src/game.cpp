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
}

Game::~Game ()
{
}

void
Game::Execute ()
{
	//Init our game
	Init();

	pWindow->Present();
	
	SDL_Delay( 3000 );

	delete pWindow;
}

void
Game::Init ()
{
	//Create window class
	pWindow = new Window();

	int width = 500;
	int height = 500;
	char* title = "Rainbow Dot";

	pWindow->Init( title, width, height );
}
