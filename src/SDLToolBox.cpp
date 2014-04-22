/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * SDLToolBox.cpp
 *
 */

#include "SDLToolBox.h"

SDL_Texture*
SDLToolBox::LoadTexture(string filename, SDL_Renderer* renderer)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Texture* optimizedImage = NULL;

	string basePath = SDL_GetBasePath();

	loadedImage = SDL_LoadBMP((basePath + filename).c_str());
	if (loadedImage == NULL){
		fprintf(stderr, "SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	//Set color key as 0x00, 0xff, 0xff
	SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0X00, 0XFF, 0XFF));
		
	optimizedImage = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (optimizedImage == NULL){
		fprintf(stderr, "SDL error: %s\n", SDL_GetError());
		exit(1);
	}

	//Don't forget this
	SDL_FreeSurface(loadedImage);

	return optimizedImage;
}
