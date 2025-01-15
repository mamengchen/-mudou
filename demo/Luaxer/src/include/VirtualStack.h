// 定于虚拟栈，用来做lua和C++交互

#include <vector>
#include <variant>
#include <string>
#include <iostream>


// 支持的栈数据类型
using Value = std::variant<int, double, std::string>;
class VirtualStack {
public:
    void push(const Value& value) {
        stack_.push_back(value);
    }

    Value pop() {
        if (stack_.empty()) {
            throw std::runtime_error("Stack underflow");
        }
        Value top = stack_.back();
        stack_.pop_back();
        return top;
    }

    Value peek() const {
        if (stack_.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return stack_.back();
    }

    void printStack() const {
        std::cout << "Stack (top -> bottom):" << std::endl;
        for (auto it = stack_.rbegin(); it != stack_.rend(); ++it) {
            std::visit([](auto&& value) { std::cout << value << std::endl; }, *it);
        }
    }

private:
    std::vector<Value> stack_;
};
