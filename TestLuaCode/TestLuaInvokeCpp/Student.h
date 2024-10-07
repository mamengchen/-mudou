#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    // 构造函数
    Student();
    // 析构函数
    ~Student();

    string get_name();
    void set_name(string name);
    unsigned get_age();
    void set_age(unsigned age);

    // 打印函数
    void print();
private:
    string _name;
    unsigned _age;
};