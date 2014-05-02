/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * main.cpp
 *
 */

#include <iostream>

#include "global.h"
#include "window.h"
#include "scriptManager.h"

#include "gameStatus.h"
#include "startScreen.h"
#include "menuScreen.h"
#include "gameSelectScreen.h"
#include "prototypeScreen.h"
#include "timer.h"

bool gameIsRunning = true;

enum GameStatusFlag gameStatusFlag;

#ifdef Config_DebugMode
enum GameStatusFlag previousFlag;
#endif

int
main(int argc, char* argv[])
{
	GameStatus* game = NULL;

	SDL_Event event;

	Timer timer;

	Window::Init(GAME_TITLE, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);

	//gameStatusFlag = START_SCREEN;
	gameStatusFlag = PROTOTYPE_SCREEN;

	//Here we go!
	while (1){

		//Swtich game status
		switch (gameStatusFlag){
			case START_SCREEN:
				game = new StartScreen();
				gameIsRunning = true;
				break;

			case MENU_SCREEN:
				game = new MenuScreen();
				gameIsRunning = true;
				break;

			case GAME_SELECT_SCREEN:
				game = new GameSelectScreen();
				gameIsRunning = true;
				break;

			case PROTOTYPE_SCREEN:
				game = new PrototypeScreen();
				gameIsRunning = true;
				break;

			case GAME_QUIT:
				return 0;
				break;
		}

		//Main game loop
		while (gameIsRunning){
			timer.Start();

			while (SDL_PollEvent(&event)) {
					game->EventHandler(&event);

					#ifdef Config_DebugMode
					if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F12) {
						if (gameStatusFlag == PROTOTYPE_SCREEN)
							gameStatusFlag = previousFlag;
						else {
							previousFlag = gameStatusFlag;
							gameStatusFlag = PROTOTYPE_SCREEN;
						}
						gameIsRunning = false;
					}
					#endif
			}

			game->Update();
			game->Render();	

			if(timer.GetTicks() < (1000 / GAME_FPS))
				SDL_Delay((1000 / GAME_FPS) - timer.GetTicks());
		}

		delete game;
	}

	return 0;
}
