//Person.cpp
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

   
    string getLastName() const;
    string getFirstName() const;
    string getPatronymic() const;
};








//Person.cpp


#include "Person.h"


Person::Person() : lastName(""), firstName(""), patronymic("") {}


Person::Person(const string& ln, const string& fn, const string& pn)
    : lastName(ln), firstName(fn), patronymic(pn) {}


string Person::getLastName() const {
    return lastName;
}

string Person::getFirstName() const {
    return firstName;
}

string Person::getPatronymic() const {
    return patronymic;
}








//main.cpp
#include "Person.h"

int main() {
    string lastName, firstName, patronymic;

   
    cout << "Enter last name: ";
    getline(cin, lastName);
    cout << "Enter first name: ";
    getline(cin, firstName);
    cout << "Enter patronymic: ";
    getline(cin, patronymic);

   
    Person person(lastName, firstName, patronymic);

   
    cout << "FIO: ";
    cout << person.getLastName() << " " << person.getFirstName();
    if (!person.getPatronymic().empty()) {
        cout << " " << person.getPatronymic();
    }
    cout << endl;

   
    cout << "Initials: ";
    cout << person.getLastName() << " " << person.getFirstName()[0] << ".";
    if (!person.getPatronymic().empty()) {
        cout << " " << person.getPatronymic()[0] << ".";
    }
    cout << endl;

    return 0;
}
