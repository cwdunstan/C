#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "dialog.h"

/**
 * @brief Each game state has a sequence of obstacles
 */
class gameState
{
public:
    gameState();

    virtual gameState* getNextState() =0;

protected:
    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;

};

#endif // GAMESTATE_H
