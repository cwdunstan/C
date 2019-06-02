#ifndef POWERTEST_H
#define POWERTEST_H

#include <memory>
#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"

class PowerTest : public TestRunner {
public:
    PowerTest();
    ~PowerTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // POWERTEST_H
