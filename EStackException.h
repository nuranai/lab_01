#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H

#include <string.h>

class EStackException {
    private:
        char* message;
    public:
        EStackException(const char* arg_message) {
            size_t length = strlen(arg_message)+1;
            message = new char[length];
            strcpy_s(message, length, arg_message);
        }
        EStackException(const EStackException& exception) {
            size_t length = strlen(exception.message)+1;
            message = new char[length];
            strcpy_s(message, length, exception.message);
        }
        ~EStackException() {
            delete message;
        }
        const char* what() {
            return message;
        }
};

#endif // ESTACKEXCEPTION_H
