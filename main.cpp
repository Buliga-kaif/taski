#include "Person.h"
#include <iostream>
using namespace std;

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
    person.show();

    cout << "Initials: ";
    person.showFormal();

    return 0;
}
