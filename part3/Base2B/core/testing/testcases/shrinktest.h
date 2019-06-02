#ifndef SHRINKTEST_H
#define SHRINKTEST_H

#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"

class ShrinkTest : public TestRunner {
public:
    ShrinkTest();
    ~ShrinkTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // SHRINKTEST_H
