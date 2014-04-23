/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * main.cpp
 *
 */

#include <iostream>

#include "global.h"

#include "gameStatus.h"
#include "startScreen.h"
#include "menuScreen.h"
#include "prototypeScreen.h"
#include "timer.h"

bool gameIsRunning = true;

enum GameStatusFlag gameStatusFlag;

int
main(int argc, char* argv[])
{
	GameStatus* game = NULL;

	SDL_Event event;

	Timer timer;

	Window::Init("RainbowDOT", GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);

	gameStatusFlag = prototypeScreen;

	//Here we go!
	while (1){

		//Swtich game status
		switch (gameStatusFlag){
			case startScreen:
				game = new StartScreen();
				gameIsRunning = true;
				break;

			case menuScreen:
				game = new MenuScreen();
				gameIsRunning = true;
				break;

			case prototypeScreen:
				game = new PrototypeScreen();
				gameIsRunning = true;
				break;

			case gameQuit:
				return 0;
				break;
		}

		//Main game loop
		while (gameIsRunning){
			timer.Start();

			while (SDL_PollEvent(&event))
					game->EventHandler(&event);

			game->Update();
			game->Render();	

			if(timer.GetTicks() < (1000 / GAME_FPS))
				SDL_Delay((1000 / GAME_FPS) - timer.GetTicks());
		}

		delete game;
	}

	return 0;
}
