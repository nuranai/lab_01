#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string patronimic;
public:
    //кончтрукторы
    Person() {}
    Person(const Person& arg) {
        firstName = arg.getFirstName();
        lastName = arg.getLastName();
        patronimic = arg.getPatronimic();
    }
    Person(string firstArg, string secondArg, string patronimicArg) {
        firstName = firstArg;
        lastName = secondArg;
        patronimic = patronimicArg;
    }
    Person &operator= (Person const& arg) {
        if (this != &arg){
            firstName = arg.getFirstName();
            lastName = arg.getLastName();
            patronimic = arg.getPatronimic();
        }
        return *this;
    }
    ~Person() {}
    //получаем полное имя
    string getFullName() {
        string fullName;
        fullName.append(lastName).append(1, ' ').append(firstName).append(1, ' ').append(patronimic);
        return fullName;
    }
    string getFirstName() const {
        return firstName;
    }
    const string getLastName() const {
        return lastName;
    }
    const string getPatronimic() const {
        return patronimic;
    }
    void setFirstName(string name) {
        firstName = name;
    }
    void setLastName(string name) {
        lastName = name;
    }
    void setPatronimic(string name) {
        patronimic = name;
    }
};

#endif // PERSON_H
