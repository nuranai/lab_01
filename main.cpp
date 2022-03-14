#include <iostream>
#include "Stack.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ofstream file("C:\\bamp\\lab_01\\file.txt");
    string bamp = "opopopo";
    file << bamp << '\n';
    bamp = "opopop";
    file << bamp << '\n';
//    Stack<int> Stack;
//    Stack.Push(1);
//    Stack.Push(2);
//    Stack.Push(3);

//    std::cout << "size: " << Stack.GetSize() << std::endl;
//    int temp = Stack.Pop();
//    std::cout << "key: " << temp << std::endl << Stack.GetSize() << std::endl;

    return 0;
}
