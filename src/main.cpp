/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * main.cpp
 *
 */

#include <iostream>
#include "game.h"

using namespace std;

int
main ( int argc, char* argv[] )
{
	Game* game = new Game();

	game->Execute();
	
	return 0;
}
