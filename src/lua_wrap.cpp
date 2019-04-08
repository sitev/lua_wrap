#include "lua_wrap.h"

#pragma comment (lib, "lua53.lib")

Lua::Lua() {
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
}

int Lua::open(string fileName) {
	return luaL_dofile(L, fileName.c_str());
}

/*
template <class FP>
void Lua::addFunc(string name, FP const fp) {
	getGlobalNamespace(L).addFunction("qwerty", fp);
}
*/

LuaRef Lua::get(string name) {
	return getGlobal(L, name.c_str());
}