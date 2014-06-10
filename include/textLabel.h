/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * textLabel.h
 *
 */

#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include <iostream>
#include <string>
#include <cstdio>
#include <SDL.h>
#include <SDL_ttf.h>

#include "global.h"
#include "window.h"

using namespace std;

class TextLabel
{
	public:
		TextLabel();
		TextLabel(
				string fontPath, int fontSize, string text, SDL_Color color,
				SDL_Renderer* renderer
			 );
		~TextLabel();

		int LoadFontAndText(
				string fontPath, int fontSize, string text, SDL_Color color,
				SDL_Renderer* renderer
				);
		void ReleaseText();

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
