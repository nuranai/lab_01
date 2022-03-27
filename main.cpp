#include <iostream>
#include <string>
//#include "EStackEmpty.h"
#include <fstream>
#include "Stack.cpp"
//#include "Person.h"
#include "PersonKeeper.h"

using namespace std;

int main()
{
    //тестирование часть 1

    Stack<int> testStack; // создаем пустой стек

    int num = 5;
    testStack.Push(num);
    testStack.Push(10);
    cout << testStack.Pop() << ' ' << testStack.Pop() << endl;
    try {
        testStack.Pop(); // пытаемся получить последний элемент
    }  catch (const EStackEmpty & exception) {
        cout << exception.what() << endl; //выводим ошибку
    }

    //тестирование часть 2

    //получаем класс синглтон
    PersonKeeper& keeper = PersonKeeper::Instance();
    //указываем путь до файла
    Stack<Person> PersonStack = keeper.readPerson("C:\\bamp\\lab_01\\file.txt");
    //проверяем наш стек
    Person lastPerson = PersonStack.Pop();

    cout << lastPerson.getFullName() << endl;
    //записываем в файл
    keeper.writePerson("C:\\bamp\\lab_01\\writeFile.txt", PersonStack);

    //проверим несуществующий файл
    try {
        Stack<Person> PersonTest = keeper.readPerson("C:\\no\\existing\\path\\file.txt");
    }  catch (const char* exc) {
        cout << exc << endl;
    }


    return 0;
}
