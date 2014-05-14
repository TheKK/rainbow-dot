/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * scriptManager.cpp
 *
 */

#include "scriptManager.h"

lua_State* ScriptManager::L;

void
ScriptManager::NewState(char* filePath)
{
	L = luaL_newstate();
	luaL_openlibs(L);

	//Load Lua script and check error
	if (luaL_dofile(L, filePath)) {
		fprintf(stderr, "Lua error: %s.\n", lua_tostring( L, -1 ));
		exit(1);
	}
}

void
ScriptManager::CloseState()
{
	lua_close(L);
}

void
ScriptManager::LoadFile(char* filePath)
{
	//Load Lua script and check error
	if (luaL_dofile(L, filePath)) {
		fprintf(stderr, "Lua error: %s.\n", lua_tostring(L, -1));
		exit(1);
	}
}

int
ScriptManager::GetGlobalInteger(char* variableName)
{
	//Load global varible into Lua stack
	lua_getglobal(L, variableName);

	switch (lua_type(L, -1)) {
		case LUA_TNUMBER:
			return lua_tointeger(L, -1);

		case LUA_TNIL:
			fprintf(stderr, "Lua error: variable \"%s\" does not exist\n", variableName);
			break;

		default:
			fprintf(stderr, "Lua error: %s is not a string\n", variableName);
			break;
	}

	//Get here only when error occur
	exit(1);
}

const char*
ScriptManager::GetGlobalString(char* variableName)
{
	//Load global varible into Lua stack
	lua_getglobal(L, variableName);

	switch (lua_type(L, -1)) {
		case LUA_TSTRING:
			return lua_tostring(L, -1);

		case LUA_TNIL:
			fprintf(stderr, "Lua error: variable \"%s\" does not exist\n", variableName);
			break;

		default:
			fprintf(stderr, "Lua error: %s is not a string\n", variableName);
			break;
	}

	//Get here only when error occur
	exit(1);
}
