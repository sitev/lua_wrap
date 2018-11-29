#include "lua_wrap.h"

#pragma comment (lib, "lua51.lib")

Lua::Lua() {
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
}

void Lua::open(string fileName) {
	luaL_dofile(L, fileName.c_str());
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