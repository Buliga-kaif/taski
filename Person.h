#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person {
private:
    string lastName;
    string firstName;
    string patronymic;

public:
    Person();
    Person(const string& ln, const string& fn, const string& pn = "");

    void show();
    void showFormal();
};
