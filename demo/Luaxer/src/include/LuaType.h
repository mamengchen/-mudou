#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    Identifier,         // 变量名或者函数名
    Number,             // 数字
    String,             // 字符串
    Keyword,            // 关键字
    Operator,           // 操作符
    EndOfFile,          // 文件结束
};


// 词法分析器主要作用就是把输入的源码拆分一系列的标记（Token），供后续的语法分析器(Parser)使用
struct Token
{
    TokenType type;
    std::string value;

    /*位置信息：用于错误报告和调试*/
    int line;
    int column;
    Token(){};
    Token(TokenType emType, std::string sValue):type(emType), value(sValue) {
        // 位置信息暂时不用.
        line = 0;
        column = 0;
    };
};
