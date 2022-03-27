#ifndef STACK_H
#define STACK_H

#include "EStackEmpty.h"

//класс односвязного списка
template<class T>
class Node {
public:
    //конструктор без аргаументов
    Node() {
        key_ = nullptr;
        next_ = nullptr;
    }
    //конструктор с аргументами
    Node(T argKey, Node *argNext) {
        key_ = argKey;
        next_ = argNext;
    }
    //метод получения значения
    T GetKey() {
        return key_;
    }
    //метод получения предыдудщего звена
    Node* GetNode() {
        return next_;
    }
private:
    T key_; //значение узла
    Node *next_; //ссылка на предыдущее звено
};

template<class T>
class Stack {
private:
    Node<T>* top; //полседний элемент стека
    int size; //резмерность стека
public:
    //коструктор
    Stack();
    //конструкторкопирования
    Stack(const Stack<T> & S);
    //деструктор
    ~Stack();
    //метод кладущий значение в стек
    void Push(T item);
    //метод извлекающий из стека
    const T Pop();
    //метод получения размера стека
    int GetSize();
};

#endif // STACK_H
