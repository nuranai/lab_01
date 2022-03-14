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
    ~Person() {}
    string getFullName() {
        string boop;
        boop.append(firstName).append(1, ' ').append(lastName).append(1, ' ').append(patronimic);
        return boop;
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
