#pragma once

#include <string>
using namespace std;

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <LuaBridge/LuaBridge.h>
using namespace luabridge;

class Lua {
	lua_State *L;
public:
	Lua();
	virtual int open(string fileName);
	template <class FP>
	void addFunc(string name, FP const fp) {
		getGlobalNamespace(L).addFunction(name.c_str(), fp);
	}
	virtual LuaRef get(string name);
};