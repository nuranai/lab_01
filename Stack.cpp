#include "Stack.h"

//коструктор
template <class T> Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}
//конструктор копирования
template <class T> Stack<T>::Stack(const Stack<T> & S) {
    top = nullptr; //врехний элемент стека
    for (int i = S.size; i > 0; i--) { //пока в стеке не пройдем все элементы будем ханосить их в список
        Node<T> *temp = S.top; //временный указатель по которому будем находить следующий элемент списка сохраняя порядок
        for (int j = 0; j < i - 1; j++) { //цикл для нахождения следующего элемента
            temp = temp->GetNode();
        }
        Node<T> *newNode = new Node(temp->GetKey(), top);//сохдаем новй узел
        top = newNode; //присваиваем его как верщину
    }
    size = S.size; //копируем размер стека
}
//деструктор
template <class T> Stack<T>::~Stack<T>() {
    while (top != nullptr) { //пока есть элементы удаляем узлы
        Node<T> *temp = top;
        top = top->GetNode();
        delete temp;
    }
}
//метод кладущий значение в стек
template <class T> void Stack<T>::Push(T item) {
    Node<T> *newNode = new Node(item, top); //создаем новый узел

    top = newNode; //присваиваем вершину к новуму узлу
    size++; //увеличиваем размер
}
//метод извлекающий из стека
// и возвращающий этот элемент
template <class T> const T Stack<T>::Pop() {
    if (top == nullptr) { // если стек пуст вызываем исключение
        throw EStackEmpty();
    }
    T data = top->GetKey(); // получаем значения которое удалится
    Node<T> *temp = top; //запоминаем узел который будет удален
    top = top->GetNode(); //присваиваем верщине следующее значение
    delete temp; // удаляем предыдущий узел
    size--; //уменьшаем размер стека
    return data; // возвращаем значение
}
template <class T> int Stack<T>::GetSize() {
    return size; // размер стека
}
