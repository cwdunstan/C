#include "level.h"

level::level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
  obstacleLayout(std::move(obstacleLayout))
{
}

