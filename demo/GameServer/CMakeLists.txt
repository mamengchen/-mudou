cmake_minimum_required(VERSION 3.10)

project(GameServer)

set(CMAKE_CXX_STANDARD 11)


add_executable(GameServer src/task_queue.h src/task_queue.cpp src/server.h src/server.cpp)

target_link_libraries(GameServer muduo_net muduo_base pthread)