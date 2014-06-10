/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * texture.cpp
 *
 */

#include "texture.h"

Texture::Texture()
{
}

Texture::Texture(string filePath, SDL_Renderer* renderer)
{
	LoadTexture(filePath, renderer);
}

Texture::~Texture()
{
	ReleaseTexture();
}

int
Texture::LoadTexture(string filePath, SDL_Renderer* renderer)
{
	SDL_Surface* loadedImage = NULL;
	string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load((basePath + filePath).c_str());
	if (loadedImage == NULL) {
		fprintf(stderr, "SDL error while loading \"%s\": %s\n", filePath.c_str(), IMG_GetError());
		return -1;
	}

	//Set color key as 0x00, 0xff, 0xff
	SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0X00, 0XFF, 0XFF));
		
	texture_ = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (texture_ == NULL) {
		fprintf(stderr, "SDL error while convering surface into texture: %s\n", SDL_GetError());
		return -1;
	}

	rect_.x = 0;
	rect_.y = 0;
	rect_.h = loadedImage->h;
	rect_.w = loadedImage->w;

	//Don't forget this
	SDL_FreeSurface(loadedImage);
	
	return 0;
}

void
Texture::ReleaseTexture()
{
	SDL_DestroyTexture(texture_);
	texture_ = NULL;
}

void
Texture::SetSize(int w, int h)
{
	rect_.w = w;
	rect_.h = h;
}

void
Texture::SetAlpha(int alpha)
{
	alpha_ = alpha;
	SDL_SetTextureAlphaMod(texture_, alpha_);
}

void
Texture::Move(int x, int y)
{
	rect_.x += x;
	rect_.y += y;
}

void
Texture::MoveXTo(int x)
{
	rect_.x = x;
}

void
Texture::MoveYTo(int y)
{
	rect_.y = y;
}

void
Texture::MoveTo(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

int
Texture::X()
{
	return rect_.x;
}


int
Texture::Y()
{
	return rect_.y;
}

int
Texture::Width()
{
	return rect_.w;
}

int
Texture::Height()
{
	return rect_.h;
}

const SDL_Rect*
Texture::GetRect()
{
	return &rect_;
}


void
Texture::Render()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, &rect_);
}

void
Texture::RenderFullWindow()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, NULL);
}
