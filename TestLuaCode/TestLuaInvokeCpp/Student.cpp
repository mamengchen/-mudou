#include "Student.h"
using namespace std;

Student::Student():_name("Empty"), _age(0) {
    cout << "Student Constructor" << endl;
}

Student::~Student() {
    cout << "Student Destructor" << endl;
}

string Student::get_name() {
    return _name;
}

void Student::set_name(string name) {
    _name = name;
}

unsigned Student::get_age() {
    return _age;
}

void Student::set_age(unsigned age) {
    _age = age;
}

void Student::print() {
    cout << "name: " << _name << "\nage: " << _age << endl;
}