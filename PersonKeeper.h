#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Stack.h"
#include <string>
#include "Person.h"

using namespace std;

class PersonKeeper {
public:
    //статический метод в котором хранится единственный экземпляр
    static PersonKeeper& Instance();
    //прочитать все ФИО из файла в стек
    Stack<Person> readPerson(string name);
    //записать все ФИО из стека в файл
    void writePerson(string filePath, Stack<Person> stack);
private:
    PersonKeeper();
    ~PersonKeeper();
};

#endif // PERSONKEEPER_H
