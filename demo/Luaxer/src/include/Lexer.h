/*这里是词法分析器 */

#include "LuaType.h"

class Lexer
{
private:
    std::string input_;
    size_t pos_;

    // 跳过空格。
    void skipWhitespace() {
        while (pos_ < input_.size() && std::isspace(input_[pos_]))
        {
            pos_++;
        }
        
    }
    // 解析出不同类型执行
    Token parseIdentifier() {
        size_t start = pos_;
        while (pos_ < input_.size() && std::isalnum(input_[pos_]))
        {
            pos_++;
        }
        input_.substr(start, pos_ - start);
        return {TokenType::Identifier, input_.substr(start, pos_ - start)};
    }

    Token parseNumber() {
        size_t start = pos_;
        while (pos_ < input_.size() && std::isdigit(input_[pos_]))
        {
            pos_++;
        }
        return{TokenType::Identifier, input_.substr(start, pos_ - start)};
    }

    Token parseString() {
        pos_++;  // 跳过退出
        size_t start = pos_;
        while (pos_ < input_.size() && input_[pos_] != '"')
        {
            pos_ ++;
        }
        pos_ ++;
        return {TokenType::String, input_.substr(start, pos_ - start - 1)};
    }
public:
    explicit Lexer(const std::string& input): input_(input), pos_(0) {};
    
    Token nextToken() {
        skipWhitespace();
        // 当执行完进入这里
        if (pos_ >= input_.size())
        {
            return {TokenType::EndOfFile, ""};
        }
        
        char current = input_[pos_];
        if (std::isalpha(current))
        {
            return parseIdentifier();
        }
        if (std::isdigit(current)) {
            return parseNumber();
        }
        if (current == '"')
        {
            return parseString();
        }
        
        //重载运算符
        if (current == '+' || current == '-' || current == '=')
        {
            pos_++;
            return {TokenType::Operator, std::string(1,current)};
        }
        
        // 跳过未定义操作
        pos_++;
        return nextToken();
    }
    ~Lexer() {};
};

