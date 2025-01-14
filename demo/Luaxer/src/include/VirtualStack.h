// 定于虚拟栈，用来做lua和C++交互

#include <vector>
#include <variant>
#include <string>
#include <iostream>


// 支持的栈数据类型
using Value = std::variant<int, double, std::string>;