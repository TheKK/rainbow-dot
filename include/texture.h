/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * texture.h
 *
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

#include "global.h"
#include "window.h"

using namespace std;

class Texture
{
	public:
		Texture();
		Texture(string filePath, SDL_Renderer* renderer);
		~Texture();

		int LoadTexture(string filePath, SDL_Renderer* renderer);
		void ReleaseTexture();

		void SetSize(int w, int h);
		void SetAlpha(int alpha);

	  	void Move(int x, int y);
	  	void MoveXTo(int x);
	  	void MoveYTo(int y);
	  	void MoveTo(int x, int y);

		int X();
		int Y();
		int Width();
		int Height();

		const SDL_Rect* GetRect();

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_;

		SDL_Rect rect_;

		int alpha_;
};

#endif
