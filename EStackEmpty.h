#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H

#include "EStackException.h"

class EStackEmpty : public EStackException
{
public:
    explicit EStackEmpty() : EStackException("Error: Stack is empty!") {}

    explicit EStackEmpty(const EStackEmpty &object) : EStackException(object) {}
};

#endif // ESTACKEMPTY_H
