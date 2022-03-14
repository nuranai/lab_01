#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "Stack.h"
#include <string>
#include <fstream>
#include "Person.h"

using namespace std;

class PersonKeeper {
public:
    static PersonKeeper& Instance() {
        static PersonKeeper p;
        return p;
    }
    Stack<Person> readPerson(string name) {
        Stack<Person> stack;
        ifstream file(name);
        if (!file) {
            throw "Error: cannot open file";
        }
        string firstName, secondName, patronimic;
        while (!file.eof()) {
            file >> firstName >> secondName >> patronimic;
            Person personItem(firstName, secondName, patronimic);
            stack.Push(personItem);
        }
        return stack;
    }
    void writePerson(Stack<Person> stack) {
        ofstream file("C:\\bamp\\lab_01\\writeFile.txt");
        Stack<Person> stackCopy(stack);
        while (stackCopy.GetSize() > 0) {
            Person personItem = stackCopy.Pop();
            string fullName = personItem.getFullName();
            file << fullName;
        }
    }
private:
    PersonKeeper() {}
    ~PersonKeeper() {}
    PersonKeeper(PersonKeeper const&); // реализация не нужна
    PersonKeeper& operator= (PersonKeeper const&);
};

#endif // PERSONKEEPER_H
