#include "context.h"

context::context()
{

}

void context::StateChanged() {
    if (m_state){
        level* nextState = m_state->getNextLevel();
        delete m_state;
        m_state = nextState;
    }
}
