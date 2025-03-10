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
