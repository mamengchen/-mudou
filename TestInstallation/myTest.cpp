#include<iostream>
#include<boost/algorithm/string.hpp>
#include<jsoncpp/json/json.h>

int main() {
    std::string str = "hallo,world";
    boost::to_upper(str);
    std::cout << str << std::endl;
    Json::Value Person;
    Person["name"] = "lijunhua";
    Person["age"] = 11;
    Person["sex"] = "male";
    Json::Value Msg;
    Msg["zzzz"] = "zzzzzzzzz";
    Msg["sssssss"] = "sssssss";
    Person["Msg"].append(Msg);
    std::string strValue = Person.toStyledString();
    std::cout << strValue << std::endl;
    return 0;
}