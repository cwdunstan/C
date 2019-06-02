#ifndef HEALTHTEST_H
#define HEALTHTEST_H

#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"
#include "lives.h"


class HealthTest : public TestRunner {
public:
    HealthTest();
    ~HealthTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    Lives testlives;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // HEALTHTEST_H
