#ifndef SPEEDTEST_H
#define SPEEDTEST_H

#include <memory>
#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"

class SpeedTest : public TestRunner {
public:
    SpeedTest();
    ~SpeedTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // SPEEDTEST_H
