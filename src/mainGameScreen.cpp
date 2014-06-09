/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * mainGameScreen.cpp
 *
 */

#include "mainGameScreen.h"

MainGameScreen::MainGameScreen()
{
	//Open new lua state
	ScriptManager::NewState((char*)"game/script/mainGameScreen.lua");

	enemy1_ = new Enemy((char*)"testEnemy1");
	enemy2_ = new Enemy((char*)"testEnemy2");
}

MainGameScreen::~MainGameScreen()
{
	CleanUp();
}

void
MainGameScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			gameIsRunning = false;
			gameStatusFlag = GAME_QUIT;
			break;
		case SDL_KEYDOWN:
			if (event->key.keysym.sym == SDLK_t)
				Window::Resize(224, 299);
			break;
	}

	player_.EventHandler(event);
	enemy1_->EventHandler(event);
	enemy2_->EventHandler(event);
}

void
MainGameScreen::Update()
{
	player_.Update();
	enemy1_->Update();
	enemy2_->Update();

	//If Enemy is out of window
	if (SDL_HasIntersection(Window::GetWindowRect(), enemy1_->GetRect()) == SDL_FALSE) {
		delete enemy1_;
		enemy1_ = new Enemy((char*)"testEnemy1");
		enemy1_->Update();
	}

	if (SDL_HasIntersection(Window::GetWindowRect(), enemy2_->GetRect()) == SDL_FALSE) {
		delete enemy2_;
		enemy2_ = new Enemy((char*)"testEnemy2");
		enemy2_->Update();
	}
}

void
MainGameScreen::Render()
{
	Window::Clear();

	//Render white background
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 0xcc);
	SDL_RenderFillRect(Window::m_Renderer, NULL);

	//Render other objects
	player_.Render();
	enemy1_->Render();
	enemy2_->Render();

	Window::Present();
}

void
MainGameScreen::CleanUp()
{
	//Clean lua state
	ScriptManager::CloseState();
}
