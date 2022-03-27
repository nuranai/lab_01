#include "Person.h"

//конструкторы
Person::Person() {}

Person::Person(const Person& arg) {
    firstName_ = arg.getFirstName();
    lastName_ = arg.getLastName();
    patronimic_ = arg.getPatronimic();
}

Person::Person(string firstArg, string secondArg, string patronimicArg) {
    firstName_ = firstArg;
    lastName_ = secondArg;
    patronimic_ = patronimicArg;
}

Person &Person::operator= (Person const& arg) {
    if (this != &arg){
        firstName_ = arg.getFirstName();
        lastName_ = arg.getLastName();
        patronimic_ = arg.getPatronimic();
    }
    return *this;
}
//деструктор
Person::~Person() {}
//метод для получения полного имени
string Person::getFullName() {
    string fullName;
    fullName.append(lastName_).append(1, ' ').append(firstName_).append(1, ' ').append(patronimic_);
    return fullName;
}
//геттеры для каждого члена данных
const string Person::getFirstName() const {
    return firstName_;
}

const string Person::getLastName() const {
    return lastName_;
}

const string Person::getPatronimic() const {
    return patronimic_;
}
//сеттеры для каждого члена данных
void Person::setFirstName(string name) {
    firstName_ = name;
}

void Person::setLastName(string name) {
    lastName_ = name;
}
void Person::setPatronimic(string name) {
    patronimic_ = name;
}
