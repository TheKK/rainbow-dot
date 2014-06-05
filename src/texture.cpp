/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * Texture.cpp
 *
 */

#include "texture.h"

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
	SDL_Texture* optimizedImage = NULL;

	string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load((basePath + filePath).c_str());
	if (loadedImage == NULL){
		fprintf(stderr, "SDL error while loading \"%s\": %s\n", filePath.c_str(), IMG_GetError());
		return -1;
	}

	//Set color key as 0x00, 0xff, 0xff
	SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0X00, 0XFF, 0XFF));
		
	optimizedImage = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (optimizedImage == NULL){
		fprintf(stderr, "SDL error while convering surface into texture: %s\n", SDL_GetError());
		return -1;
	}

	//Don't forget this
	SDL_FreeSurface(loadedImage);

	texture_ =  optimizedImage;
	
	return 0;
}

void
Texture::ReleaseTexture()
{
	SDL_DestroyTexture(texture_);
	texture_ = NULL;
}

void
Texture::SetPositionAndSize(int x, int y, int w, int h)
{
	position_.x = x;
	position_.y = y;
	position_.w = w;
	position_.h = h;
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
	position_.x += x;
	position_.y += y;
}

const SDL_Rect
Texture::GetRect()
{
	return position_;
}


void
Texture::Render()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, &position_);
}

void
Texture::RenderFullWindow()
{
	SDL_RenderCopy(Window::m_Renderer, texture_, NULL, NULL);
}
