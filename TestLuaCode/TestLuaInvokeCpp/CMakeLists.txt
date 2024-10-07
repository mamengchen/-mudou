cmake_minimum_required(VERSION 2.8)

project(MyLuaTest)

set(CMAKE_CXX_STANDARD 11)

# 手动指定 lua 库和头文件的路径
set(LUA_INCLUDE_DIR "/usr/include/lua5.4")    # lua 头文件路径
set(LUA_LIBRARY "/usr/lib/x86_64-linux-gnu/liblua5.4.so") # lua 库路径


# 添加头文件
include_directories(${LUA_INCLUDE_DIR})

add_executable(MyLuaTest Student.h
Student.cpp
StudentRegFunc.h
StudentRegFunc.cpp
lua4.cpp)

target_link_libraries(MyLuaTest ${LUA_LIBRARY})