#ifndef MOVABLESTICKMAN_H
#define MOVABLESTICKMAN_H

#include <memory>
#include "entity.h"
#include "stickman.h"

class MovableStickman : public Stickman {
public:
    /**
     * @brief JumpingStickman An extension of the Stickman class which adds jumping and collision detection
     * @param floor The y position which is considered the floor (i.e. will stop falling at)
     * @param jumpImpulse The vertical velocity applied when jumping
     * @param maxJumpCount The maximum amount of jumps that can be peformed mid-air (including the initial jump)
     * @param gravity The falling rate
     */
    MovableStickman(int floor, int jumpImpulse = 15, int maxJumpCount = 2, int gravity = -1);
    ~MovableStickman();

    void jump();
    bool canJump();
    void handleInput(QKeyEvent &event);
    void update(std::vector<std::unique_ptr<Entity>> &obstacles);

private:
    int floor;
    int jumpImpulse;
    int jumpVelocity;
    int gravity;
    bool grounded;
    int jumpCount;
    int maxJumpCount;
};

#endif // MOVABLESTICKMAN_H
