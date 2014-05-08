/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * SDLToolBox.cpp
 *
 */

#include "SDLToolBox.h"

SDLToolBox::SDLToolBox()
{
	if (!IMG_Init(IMG_INIT_PNG)) {
		fprintf(stderr, "Error while init SDL_image: %s\n", IMG_GetError());
		exit(1);
	}
}

SDLToolBox::~SDLToolBox()
{
	IMG_Quit();
}

SDL_Texture*
SDLToolBox::LoadTexture(string filename, SDL_Renderer* renderer)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Texture* optimizedImage = NULL;

	string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load((basePath + filename).c_str());
	if (loadedImage == NULL){
		fprintf(stderr, "SDL error while loading \"%s\": %s\n", filename.c_str(), IMG_GetError());
		exit(1);
	}

	//Set color key as 0x00, 0xff, 0xff
	SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0X00, 0XFF, 0XFF));
		
	optimizedImage = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (optimizedImage == NULL){
		fprintf(stderr, "SDL error while convering surface into texture: %s\n", SDL_GetError());
		exit(1);
	}

	//Don't forget this
	SDL_FreeSurface(loadedImage);

	return optimizedImage;
}
