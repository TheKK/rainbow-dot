/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * textLabel.cpp
 *
 */

#include "textLabel.h"

TextLabel::TextLabel()
{
}

TextLabel::TextLabel(
		string fontPath, int fontSize, string text, SDL_Color color,
		SDL_Renderer* renderer
		)
{
	LoadFontAndText(fontPath, fontSize, text, color, renderer);
}

TextLabel::~TextLabel()
{
	ReleaseText();
}

int
TextLabel::LoadFontAndText(
		string fontPath, int fontSize, string text, SDL_Color color,
		SDL_Renderer* renderer
		)
{
	SDL_Surface* tmpSurface = NULL;
	TTF_Font* font = NULL;
	string basePath = SDL_GetBasePath();

	font = TTF_OpenFont((basePath + fontPath).c_str(), fontSize);
	if (font == NULL) {
		fprintf(stderr, "Error while open font: %s\n", TTF_GetError());
		return -1;
	}

	tmpSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (tmpSurface == NULL) {
		fprintf(stderr, "SDL error while rendering text: %s\n", TTF_GetError());
		return -1;
	}
		
	texture_ = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	if (texture_ == NULL) {
		fprintf(stderr, "SDL error while convering surface into texture: %s\n", SDL_GetError());
		return -1;
	}

	rect_.x = 0;
	rect_.y = 0;
	rect_.h = tmpSurface->h;
	rect_.w = tmpSurface->w;

	//Don't forget these
	SDL_FreeSurface(tmpSurface);
	tmpSurface = NULL;

	TTF_CloseFont(font);
	font = NULL;
	
	return 0;
}

void
TextLabel::ReleaseText()
{
	SDL_DestroyTexture(texture_);
	texture_ = NULL;
}

void
TextLabel::SetSize(int w, int h)
{
	rect_.w = w;
	rect_.h = h;
}

void
TextLabel::SetAlpha(int alpha)
{
	alpha_ = alpha;
	SDL_SetTextureAlphaMod(texture_, alpha_);
}

void
TextLabel::Move(int x, int y)
{
	rect_.x += x;
	rect_.y += y;
}

void
TextLabel::MoveXTo(int x)
{
	rect_.x = x;
}

void
TextLabel::MoveYTo(int y)
{
	rect_.y = y;
}

void
TextLabel::MoveTo(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

int
TextLabel::X()
{
	return rect_.x;
}


int
TextLabel::Y()
{
	return rect_.y;
}

int
TextLabel::Width()
{
	return rect_.w;
}

int
TextLabel::Height()
{
	return rect_.h;
}

const SDL_Rect*
TextLabel::GetRect()
{
	return &rect_;
}


void
TextLabel::Render()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, &rect_);
}

void
TextLabel::RenderFullWindow()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, NULL);
}
