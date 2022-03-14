#ifndef STACK_H
#define STACK_H

#include "EStackEmpty.h"

template<class T>
class Stack {
private:
    struct Node {
        const T key;
        Node* next;
    };
    Node* top;
    int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }
    Stack(const Stack<T> & S) {
        for (int i = S.size; i > 0; i--) {
            top = nullptr;
            Node* temp = S.top;
            for (int j = 0; j < i; j++) {
                temp = temp->next;
            }
            Node* newNode = new Node{temp->key, top};
            top = newNode;
        }
        size = S.size;
    }
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void Push(T item) {
        Node* newNode = new Node{item, top};

        top = newNode;
        size++;
    }
    const T Pop() {
        if (top == nullptr) {
            throw EStackEmpty();
        }
        T data = top->key;
        Node* temp = top;
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
