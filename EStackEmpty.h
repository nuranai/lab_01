#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H

#include "EStackException.h"

class EStackEmpty : public EStackException
{
public:
    //конструктор по умолчанию
    explicit EStackEmpty() : EStackException("Error: Stack is empty!") {} //инициализируем базовый класс с сообщением об ошибке
    //конструктор копирования
    explicit EStackEmpty(const EStackEmpty &object) : EStackException(object) {} //инициализируем базовый класс переданным аргуметом
};

#endif // ESTACKEMPTY_H
