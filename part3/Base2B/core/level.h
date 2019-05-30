#ifndef LEVEL_H
#define LEVEL_H

#include "dialog.h"

class level
{
public:
    level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);

    void setNextLevel(level * nextLevel);
    int getTemp();
    void setTemp(int n);
    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;

protected:
    int temp;
private:
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
