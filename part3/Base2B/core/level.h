#ifndef LEVEL_H
#define LEVEL_H

#include "dialog.h"

class level
{
public:
    level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);

    void setNextLevel(level * nextLevel);
    level* getNextLevel();
    int getStartScore();
    void setStartScore(int set);
    int getIndex();
    void setIndex(int set);

    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;



protected:
    int startScore;
    int index;
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
