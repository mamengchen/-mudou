#include "StudentRegFunc.h"

int lua_create_new_student(lua_State* L) {
    // 创建一个对象指针放到stack里，返回给Lua中使用
    Student** s = (Student**)lua_newuserdata(L, sizeof(Student*));
    *s = new Student;
    return 1;
}

int lua_get_name(lua_State* L) {
    // 得到第一个传入的对象参数
    Student** s = (Student**)lua_touserdata(L, 1);
    luaL_argcheck(L, s != NULL, 1, "invalid user data");

    // 清空stack
    lua_settop(L, 0);

    // 将数据放入stack中，供Lua使用
    lua_pushstring(L, (*s)->get_name().c_str());

    return 1;
}

int lua_set_name(lua_State* L){
    // 得到第一个传入的对象参数
    Student** s = (Student**)lua_touserdata(L, 1);
    luaL_argcheck(L, s != NULL, 1, "invalid user data");
    luaL_checktype(L, -1, LUA_TSTRING);
    std::string name = lua_tostring(L, -1);
    (*s)->set_name(name);
    return 0;
}

int lua_get_age(lua_State* L)
{
	Student** s = (Student**)lua_touserdata(L, 1);
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
 
	lua_pushinteger(L, (*s)->get_age());
 
	return 1;
}
 
int lua_set_age(lua_State* L)
{
	Student** s = (Student**)lua_touserdata(L, 1);
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
 
	luaL_checktype(L, -1, LUA_TNUMBER);
    cout << "修改年龄：" << (unsigned)lua_tointeger(L, -1) << endl;
	(*s)->set_age((unsigned)lua_tointeger(L, -1));
 
	return 0;
}
 
int lua_print(lua_State* L)
{
	Student** s = (Student**)lua_touserdata(L, 1);
	luaL_argcheck(L, s != NULL, 1, "invalid user data");
 
	(*s)->print();
 
	return 0;
}
 
int luaopen_student_libs(lua_State* L)
{
	// 创建一张新的表，并把列表的函数注册进去
	luaL_newlib(L, lua_reg_student_funcs);
	return 1;
}