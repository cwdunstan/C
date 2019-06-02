#ifndef POWERUPTEST_H
#define POWERUPTEST_H

#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"

class PowerUpTest : public TestRunner {
public:
    PowerUpTest();
    ~PowerUpTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // POWERUPTEST_H
