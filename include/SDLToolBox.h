/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * SDLToolBox.h
 *
 */

#ifndef SDLTOOLBOX_H
#define SDLTOOLBOX_H

#include <iostream>
#include <cstdio>
#include <string>
#include <SDL2/SDL.h>


#include "global.h"

using namespace std;

class SDLToolBox
{
	public:
		SDLToolBox(){};
		~SDLToolBox(){};

		static SDL_Texture* LoadTexture( string fileName, SDL_Renderer* renderer );
};

#endif
