#include "Person.h"

Person::Person() : lastName(""), firstName(""), patronymic("") {}

Person::Person(const string& ln, const string& fn, const string& pn)
    : lastName(ln), firstName(fn), patronymic(pn) {}

void Person::show() {
    cout << lastName << " " << firstName << " " << patronymic << endl;
}

void Person::showFormal() {
    cout << lastName << " " << firstName[0] << ". " << patronymic[0] << "." << endl;
}
