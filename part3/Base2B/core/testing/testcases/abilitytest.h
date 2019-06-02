#ifndef ABILITYTEST_H
#define ABILITYTEST_H

#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"

class AbilityTest : public TestRunner {
public:
    AbilityTest();
    ~AbilityTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // ABILITYTEST_H
