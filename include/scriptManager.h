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
#include <lua.hpp>
}

using namespace std;

class ScriptManager
{
	public:
		ScriptManager(){};
		~ScriptManager(){};

		static void NewState(char* filePath);
		static void CloseState();

		static void LoadFile(char* filePath);

		static int GetGlobalInteger(char* variableName);
		static const char* GetGlobalString(char* variableName);

	private:
		static lua_State* L;
};

#endif
