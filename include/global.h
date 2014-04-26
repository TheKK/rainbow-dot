/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * glocal.h
 *
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#define GAME_TITLE		"Rainbow-dot"
#define GAME_WINDOW_RATIO	16 / 9
#define GAME_WINDOW_HEIGHT	600
#define GAME_WINDOW_WIDTH	GAME_WINDOW_HEIGHT * GAME_WINDOW_RATIO

#define GAME_FPS		60

#define Config_DebugMode	1

//Recored current game status
enum GameStatusFlag
{
	START_SCREEN = 0,
	MENU_SCREEN,
	GAME_SELECT_SCREEN,
	PROTOTYPE_SCREEN,
	GAME_QUIT
};

enum GameStatusMode
{
	GAME_TRANSFER_IN = 0,
	GAME_NORMAL,
	GAME_TRANSFER_OUT
};

#endif
