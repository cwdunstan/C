#include "level.h"

level::level(std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
  obstacleLayout(std::move(obstacleLayout))
{

}

int level::getTemp(){
    return temp;
}
void level::setTemp(int n){
    this->temp = n;
}





