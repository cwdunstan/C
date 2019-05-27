#ifndef MOVETEST_H
#define MOVETEST_H

#include <memory>
#include "movablestickman.h"
#include "testrunner.h"
#include "entity.h"

class MoveTest : public TestRunner {
public:
    MoveTest();
    ~MoveTest() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<MovableStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // MOVETEST_H
