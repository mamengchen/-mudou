#include <stdio.h>
#include <iostream>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

static int average(lua_State *L) {
    int n = lua_gettop(L);
    double sum = 0;
    int i;
    /* 循环求参数之和 */
    for (i = 1; i <= n; i++) {
        /* 求和 */
        sum += lua_tonumber(L, i);
    }
    /*压入平均值*/
    lua_pushnumber(L, sum / n);
    /*压入和*/
    lua_pushnumber(L, sum);
    return 2;
}

// 1.列出需要封装的C++函数，luaL_Reg 为注册函数的数组类型
static const luaL_Reg mylibs_funcs[] = {
    {"aveeerage", average},
    {NULL, NULL}
};

// 2.将所有函数放到一个table中，并压入栈中
int lua_openmylib(lua_State* L) {
    // 创建一个新的表，将所有函数放到一个table中，将这个table压到stack里
    luaL_newlib(L, mylibs_funcs);
    return 1;
}

// 3.将自定义模块加到注册列表里
static const luaL_Reg lua_reg_libs[] = {
    {"base", luaopen_base},
    {"mylib", lua_openmylib},  //这里为自定义的
    {NULL, NULL}
};


int main(int argc, char *argv[]) {
    /* 初始化lua，指向lua解释器的指针 */
    lua_State * L = luaL_newstate();

    /* 载入lua基本库 */
    luaL_openlibs(L);

    // 4.注册让lua使用的模块
    const luaL_Reg* lua_reg = lua_reg_libs;
    for(; lua_reg->func; ++lua_reg) {
        // 加载模块：首先查找 package, loaded 表，检测modname是否被加载过。
        // 如果被加载过，require 返回 package.loaded[modname] 中保存的值。
        // 如果 modname ， 不在 package.loaded 中，则调用函数 openf, 并传入字符串
        // 将其返回值置入 package.loaded[modname].
        // 如果最后一个参数为真，同时也将模块设到全局变量modname里。在栈上留下该模块的副本
        luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
        // 从栈中弹出 1 个元素
        lua_pop(L, 1);
    }

    /*运行脚本*/
    luaL_dofile(L, "./avg.lua");
    if (luaL_dofile(L, "avg.lua")) {
        std::cout << "error" << std::endl;
    }
    /*清除lua*/
    lua_close(L);

    printf("press enter to exit...\n");

    return 0;
}