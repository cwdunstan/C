#include "level.h"

level::level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
  obstacleLayout(std::move(obstacleLayout))
{
}

int level::getStartScore() {
    return this->startScore;
}

void level::setStartScore(int set) {
    startScore = set;
}
