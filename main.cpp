#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"
#include "PersonKeeper.h"

using namespace std;

int main()
{
    //получаем класс синглтон
    PersonKeeper& keeper = PersonKeeper::Instance();
    //указываем путь до файла
    Stack<Person> PersonStack = keeper.readPerson("C:\\bamp\\lab_01\\file.txt");
    //проверяем наш массив
    Person lastPerson = PersonStack.Pop();

    cout << lastPerson.getFullName() << endl;
    //записываем в файл
    keeper.writePerson(PersonStack);

    return 0;
}
