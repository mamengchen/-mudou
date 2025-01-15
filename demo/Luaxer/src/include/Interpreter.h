#include "Parser.h"
#include "VirtualStack.h"
#include <memory>

class Interpreter
{
private:
    VirtualStack stack_;
public:
    Interpreter(/* args */):stack_(){};
    ~Interpreter() {};
    
    void interpret(ASTNode* node) {
        if (!node) return;
    }

    void interpretAdd(int a, int b) {
        stack_.push(a);
        stack_.push(b);
    }

    
};

