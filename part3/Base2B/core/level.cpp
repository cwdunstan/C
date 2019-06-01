#include "level.h"

level::level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
  obstacleLayout(std::move(obstacleLayout))
{
}

void level::setNextLevel(level * nextLevel) {
    this->nextLevel=nextLevel;
}

level* level::getNextLevel() {
    return nextLevel;
}

int level::getStartScore() {
    return this->startScore;
}

void level::setStartScore(int set) {
    this->startScore = set;
}

int level::getIndex() {
    return this->index;
}

void level::setIndex(int set) {
    this->index = set;
}

