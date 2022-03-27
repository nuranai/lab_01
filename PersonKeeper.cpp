#include "PersonKeeper.h"
#include "Stack.cpp"
#include "Person.h"
#include <fstream>
#include <string>

PersonKeeper::PersonKeeper(){}

PersonKeeper::~PersonKeeper() {}

//функция вернет ссылку на экземпляр класса
PersonKeeper &PersonKeeper::Instance() {
    static PersonKeeper p; //static что бы каждый раз не создавался новый экземпляр при вызове функции
    return p;
}

//функция считывает с файла ФИО и запишет их в стек, который вернет
Stack<Person> PersonKeeper::readPerson(string fileName) {
    Stack<Person> stack;
    ifstream file(fileName); //открываем файл для чтения
    if (!file) { //если не удается открыть вызываем исключение
        throw "Error: cannot open file";
    }
    string firstName, secondName, patronimic;
//        записываем имена в переменные пока не конец файла
    while (!file.eof()) {
        file >> secondName >> firstName >> patronimic;
        Person personItem(firstName, secondName, patronimic); //создаем новый класс Person
        stack.Push(personItem); //кладем его в стек
    }
    return stack; //возвращаем стек
}

//функция запишет в файл значения из стека в файл, не изменяя исходный стек
void PersonKeeper::writePerson(string filePath, Stack<Person> stack) {
    Stack<Person> stackCopy(stack); //копируем исходный стек что бы не изменять его
    ofstream file(filePath); //открываем или создаем для записи файл
    if (!file) {
        throw "Error: cannot write to file";
    }
    while (stackCopy.GetSize() > 0) { //пока в стеке есть элементы записываем из в файл
        Person personItem = stackCopy.Pop(); //получаем верхний элемент
        string fullName = personItem.getFullName(); //получаем полное имя
        file << fullName << endl; //записываем в файл
    }
}
