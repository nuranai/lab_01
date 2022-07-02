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

    // проеврим его размер
    cout << "stack Size: " << testStack.GetSize() << endl;

    // добавим в стек число 5
    testStack.Push(5);

    // проверим его размер
    cout << "stack Size: " << testStack.GetSize() << endl;

    // так же добавим в стек число 1
    int num = 1;
    testStack.Push(num);

    // снова проверяем стек
    cout << "stack Size: " << testStack.GetSize() << endl;

    // пока не встретим ошибку
    bool untilError = true;

//    while (untilError) {
//        try {
//            cout << "current Element: " << testStack.Pop() << endl;
//            cout << "stack Size: " << testStack.GetSize() << endl;
//        }  catch (const EStackEmpty & exception) {
//            cout << exception.what() << endl;
//            untilError = false;
//        }
//    }

    //тестирование часть 2

    //получаем класс синглтон
    PersonKeeper& keeper = PersonKeeper::Instance();
    //указываем путь до файла
    try {

        Stack<Person> PersonStack = keeper.readPerson("C:\\bamp\\lab_01\\file.txt");
        //записываем в файл
        keeper.writePerson("C:\\bamp\\lab_01\\writeFile.txt", PersonStack);

    }  catch (const char* exc) {
        cout << exc << endl;
    }

    return 0;
    //проверяем наш стек
//    Person lastPerson = PersonStack.Pop();

//    cout << lastPerson.getFullName() << endl;
    //проверим несуществующий файл
    try {
        Stack<Person> PersonTest = keeper.readPerson("C:\\no\\existing\\path\\file.txt");
    }  catch (const char* exc) {
        cout << exc << endl;
    }

    return 0;
}
