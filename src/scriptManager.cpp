/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * scriptManager.cpp
 *
 */

#include "scriptManager.h"

lua_State* ScriptManager::L;

void
ScriptManager::NewState()
{
	//Create a new lua state
	L = luaL_newstate();

	//Load Lua build-in libs
	luaL_openlibs(L);
}

void
ScriptManager::CleanState()
{
	lua_close(L);
}

void
ScriptManager::LoadFile(char* filePath)
{
	//Load Lua script and check error
	if (luaL_dofile(L, filePath)){
		fprintf(stderr, "Lua error: %s.\n", lua_tostring( L, -1 ));
		exit(1);
	}
}

int
ScriptManager::GetInteger(char* filePath, char* variableName)
{
	//Load global varible into Lua stack
	lua_getglobal(L, variableName);

	if (lua_type(L, -1) == LUA_TNUMBER)
		return lua_tointeger( L, -1 );
	else {
		fprintf(stderr, "Lua error in script file: %s in %s is not a number or does not exist.\n", variableName, filePath);
		exit(1);
	}
}

const char*
ScriptManager::GetString(char* filePath, char* variableName)
{
	//Load global varible into Lua stack
	lua_getglobal(L, variableName);

	if (lua_type(L, -1) == LUA_TSTRING)
		return lua_tostring(L, -1);
	else {
		fprintf(stderr, "Lua error in script file: %s in %s is not a number or does not exist.\n", variableName, filePath);
		exit(1);
	}
}
