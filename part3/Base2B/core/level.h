#ifndef LEVEL_H
#define LEVEL_H

#include "dialog.h"

class level
{
public:
    level();

    void setNextLevel(level * nextLevel);
    int getTemp();
    void setTemp(int n);

protected:
    int temp;
    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;
private:
    level* currLevel;
    level* nextLevel;
    unsigned int startScore;



};


class first : public level
{

};


class second : public level
{

};

#endif // LEVEL_H
