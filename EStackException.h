#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H

#include <string.h>

class EStackException {
public:
        EStackException(const char* arg_message) { //конструктор
            size_t length = strlen(arg_message)+1; //получаем длину сообщения
            message_ = new char[length]; // выделяем память под сообщение
            strcpy_s(message_, length, arg_message); //сохраняем сообщение
        }
        // конструктор покирования
        EStackException(const EStackException& exception) {
            size_t length = strlen(exception.message_)+1; //получаем длину сообщения
            message_ = new char[length]; // выделяем память под сообщение
            strcpy_s(message_, length, exception.message_); //сохраняем сообщение
        }
        ~EStackException() { //деструктор
            delete message_;
        }
        const char* what() const {
            return message_;
        }
private:
    char* message_;
};

#endif // ESTACKEXCEPTION_H
