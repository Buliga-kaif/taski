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
