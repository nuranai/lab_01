#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
public:
    //конструкторы
    Person();
    Person(const Person& arg);
    Person(string firstArg, string secondArg, string patronimicArg);
    Person &operator= (Person const& arg);
    //деструктор
    ~Person();
    //получаем полное имя
    string getFullName();
    //гетеры для каждого члена данных
    const string getFirstName() const;
    const string getLastName() const;
    const string getPatronimic() const;
    //сеттеры для каждого члена данных
    void setFirstName(string name);
    void setLastName(string name);
    void setPatronimic(string name);
private:
    string firstName_; //имя
    string lastName_; //фамилия
    string patronimic_; //отчество
};

#endif // PERSON_H
