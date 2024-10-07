#include <iostream>
using namespace std;
 
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
 
#include "Student.h"
#include "StudentRegFunc.h"
 
static const luaL_Reg lua_reg_libs[] = {
	{ "base", luaopen_base }, //系统模块
	{ "Student", luaopen_student_libs}, //模块名字Student，注册函数luaopen_student_libs
	{ NULL, NULL }
};
 
int main(int argc, char* argv[])
{
	if (lua_State* L = luaL_newstate()) {
 
		//注册让lua使用的库
		const luaL_Reg* lua_reg = lua_reg_libs;
		for (; lua_reg->func; ++lua_reg) {
			luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
			lua_pop(L, 1);
		}
		//加载脚本，如果出错，则打印错误
		if (luaL_dofile(L, "lua1.lua")) {
			cout << lua_tostring(L, -1) << endl;
		}
 
		lua_close(L);
	}
	else {
		cout << "luaL_newstate error !" << endl;
	}
 
	system("pause");
 
	return 0;
}