# g++ -o a.out myTest.cpp -lboost_system -lboost_filesystem

cmake_minimum_required (VERSION 3.10)

# 项目名称
project (main)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(JSONCPP_DIR "/usr/lib/x86_64-linux-gnu")

# 查找 JsonCpp 库
find_package(jsoncpp REQUIRED HINTS ${JSONCPP_DIR})

# 添加可执行文件
add_executable(main myTest.cpp)

# 链接 jsoncpp 动态库到可执行文件
target_link_libraries(main PRIVATE ${JSONCPP_DIR}/libjsoncpp.so)