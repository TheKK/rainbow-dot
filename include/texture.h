/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * Texture.h
 *
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "global.h"
#include "window.h"

using namespace std;

class Texture
{
	public:
		Texture(string filePath, SDL_Renderer* renderer);
		~Texture();

		int LoadTexture(string filePath, SDL_Renderer* renderer);
		void ReleaseTexture();

		void SetPositionAndSize(int x, int y, int w, int h);
		void SetAlpha(int alpha);

		void Move(int x, int y);

		const SDL_Rect GetRect();

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_;

		SDL_Rect position_;

		int alpha_;
};

#endif
