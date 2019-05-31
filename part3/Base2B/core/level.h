#ifndef LEVEL_H
#define LEVEL_H

#include "dialog.h"

class level
{
public:
    level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);

    void setNextLevel(level * nextLevel);

    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;

private:
    level* nextLevel;




};


class first : public level
{

};


class second : public level
{

};

#endif // LEVEL_H
