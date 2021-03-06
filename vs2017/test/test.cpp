#include "lua_wrap.h"

#include <string>
#include <iostream>
using namespace std;

#pragma comment (lib, "lua53.lib")
#pragma comment (lib, "lua_wrap.lib")

void printMessage(const std::string& s) {
	cout << "print = " << s << endl;
}

int main() {
	Lua lua;
	lua.open("script.lua");
	
	lua.addFunc("printMessage", printMessage);

	auto win = lua.get("window");
	auto title = win["title"];
	cout << "Title: " << title.cast<string>() << endl;

	auto size = win["size"];
	auto width = size["width"];
	cout << "Width = " << width.cast<int>() << endl;

	auto height = size["height"];
	cout << "Height = " << height.cast<int>() << endl;

	auto hello_world_sum = lua.get("hello_world_sum");
	int result = hello_world_sum(1, 2);
	cout << "Result = " << result << endl;

	return 0;
}


/*
int main()
{
	Lua lua;
	lua.open("script.lua");

	LuaRef win = getGlobal(lua.L, "window");
	LuaRef title = win["title"];
	cout << "Title: " << title.cast<string>() << endl;
	
	LuaRef size = win["size"];
	LuaRef width = size["width"];
	cout << "Width = " << width.cast<int>() << endl;
	
	LuaRef height = size["height"];
	cout << "Height = " << height.cast<int>() << endl;

	LuaRef hello_world_sum = getGlobal(lua.L, "hello_world_sum");
	int result = hello_world_sum(1, 2);
	cout << "Result = " << result << endl;

    return 0;
}

*/