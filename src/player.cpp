/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * player.cpp
 *
 */

#include "player.h"

Player::Player()
{
	//Init player parameters
	playerTexture_.MoveTo(50, 50);
}

Player::~Player()
{
	CleanUp();
}

void
Player::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_UP:
					upIsPushed_ = true;
					break;
				case SDLK_DOWN:
					downIsPushed_ = true;
					break;
				case SDLK_LEFT:
					leftIsPushed_ = true;
					break;
				case SDLK_RIGHT:
					rightIsPushed_ = true;
					break;
				case SDLK_z:
					isShooting_ = true;
					break;
			}
			break;
		case SDL_KEYUP:
			switch (event->key.keysym.sym) {
				case SDLK_UP:
					upIsPushed_ = false;
					break;
				case SDLK_DOWN:
					downIsPushed_ = false;
					break;
				case SDLK_LEFT:
					leftIsPushed_ = false;
					break;
				case SDLK_RIGHT:
					rightIsPushed_ = false;
					break;
				case SDLK_z:
					isShooting_ = false;
					break;
			}
			break;
	}
}

void
Player::Update()
{
	//Check key status to move player
	if (upIsPushed_ && downIsPushed_)
		;
	else if (upIsPushed_)
		Move(UP);
	else if (downIsPushed_)
		Move(DOWN);

	if (leftIsPushed_ && rightIsPushed_)
		;
	else if (leftIsPushed_)
		Move(LEFT);
	else if (rightIsPushed_)
		Move(RIGHT);

	//Handler shooting stuffs
	if (isShooting_) {
		Bullet tmp(playerTexture_.X(), playerTexture_.Y());
		bulletPool_.push_back(tmp);
	}

	for (vector<Bullet>::size_type i = 0; i < bulletPool_.size(); i++) {
		bulletPool_[i].y -= 15;

		if (bulletPool_[i].y + bulletTexture_.Height() < 0)
			bulletPool_.erase(bulletPool_.begin() + i);
	}

			
}

void
Player::Render()
{
	for (vector<Bullet>::size_type i = 0; i < bulletPool_.size(); i++) {
		bulletTexture_.MoveTo(bulletPool_[i].x, bulletPool_[i].y);
		bulletTexture_.Render();
	}

	playerTexture_.Render();
}

void
Player::Move(enum MoveDirection moveDircection)
{
	switch (moveDircection) {
		case UP:
			playerTexture_.Move(0, -moveSpeed_);
			if (playerTexture_.Y() < 0)
				playerTexture_.MoveYTo(0);
			break;
		case DOWN:
			playerTexture_.Move(0, moveSpeed_);
			if (playerTexture_.Y() + playerTexture_.Height() > Window::Height())
				playerTexture_.MoveYTo(Window::Height()- playerTexture_.Height());
			break;
		case LEFT:
			playerTexture_.Move(-moveSpeed_, 0);
			if (playerTexture_.X() < 0)
				playerTexture_.MoveXTo(0);
			break;
		case RIGHT:
			playerTexture_.Move(moveSpeed_, 0);
			if (playerTexture_.X() + playerTexture_.Width() > Window::Width())
				playerTexture_.MoveXTo(Window::Width() - playerTexture_.Width());
			break;
	}
}

void
Player::CleanUp()
{
}
