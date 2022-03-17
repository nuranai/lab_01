#ifndef STACK_H
#define STACK_H

#include "EStackEmpty.h"

//класс узлов

template<class T>
class Node {
public:
    T key;
    Node *next;
    Node() {
        key = nullptr;
        next = nullptr;
    }
    Node(T argKey, Node *argNext) {
        key = argKey;
        next = argNext;
    }
    T GetKey() {
        return key;
    }
};

template<class T>
class Stack {
private:
    Node<T>* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }
    //конструктор копирования
    Stack(const Stack<T> & S) {
        top = nullptr;
        for (int i = S.size; i > 0; i--) {
            Node<T> *temp = S.top;
            for (int j = 0; j < i - 1; j++) {
                temp = temp->next;
            }
            Node<T> *newNode = new Node(temp->key, top);
            top = newNode;
        }
        size = S.size;
    }
    ~Stack() {
        while (top != nullptr) {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void Push(T item) {
        Node<T> *newNode = new Node(item, top);

        top = newNode;
        size++;
    }
    const T Pop() {
        if (top == nullptr) {
            throw EStackEmpty();
        }
        T data = top->key;
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }
    int GetSize() {
        return size;
    }
};

#endif // STACK_H
