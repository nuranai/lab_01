#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> Stack;
    Stack.Push(1);
    Stack.Push(2);
    Stack.Push(3);

    std::cout << "size: " << Stack.GetSize() << std::endl;
    int temp = Stack.Pop();
    std::cout << "key: " << temp << std::endl << Stack.GetSize() << std::endl;
    return 0;
}
