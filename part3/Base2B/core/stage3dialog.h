#ifndef STAGE3DIALOG_H
#define STAGE3DIALOG_H

#include "dialog.h"

class Stage3Dialog : public Dialog {
public:
    /**
     * @brief Stage3Dialog
     * @param game The container of the dialog
     * @param stickman The player's stickman object
     * @param factory An entity factory for producing obstacles
     * @param obstacleLayout Pairs of (obstacle, space_until_next_obstacle) describing the sequence in which obstacles will be spawned
     */
    Stage3Dialog(Game &game, std::unique_ptr<Stickman> stickman, std::unique_ptr<EntityFactory> factory, std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);

    void update();


protected:
    virtual void spawnObstacles(unsigned int counter);

private:
    std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout;
    int distanceToSpawn;
    int nextObstacle;
};

#endif // STAGE3DIALOG_H
