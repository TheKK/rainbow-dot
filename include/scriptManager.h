/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * scriptManager.h
 *
 */

#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <iostream>
#include <cstdlib>

extern "C" {
#include <lua5.2/lua.hpp>
}

using namespace std;

class ScriptManager
{
	public:
		ScriptManager(){};
		~ScriptManager(){};

		static void NewState();
		static void CleanState();

		static void LoadFile(char* filePath);

		static int GetInteger(char* filePath, char* variableName);
		static const char* GetString(char* filePath, char* variableName);

	private:
		static lua_State* L;
};

#endif
