#ifndef CONTEXT_H
#define CONTEXT_H

#include "level.h"

class context
{
public:
    context();
    context(level* passedLevel);
    ~context();

    void StateChanged();

protected:
    void cleanup();
    level * m_state;

};

#endif // CONTEXT_H
