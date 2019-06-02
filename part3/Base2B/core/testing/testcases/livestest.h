#ifndef LIVESTEST_H
#define LIVESTEST_H

#include "jumpingstickman.h"
#include "testrunner.h"
#include "entity.h"
#include "lives.h"

class LivesTest : public TestRunner {
public:
    LivesTest();
    ~LivesTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<JumpingStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // LIVESTEST_H
