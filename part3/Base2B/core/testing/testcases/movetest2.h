#ifndef MOVETEST2_H
#define MOVETEST2_H

#include <memory>
#include "movablestickman.h"
#include "testrunner.h"
#include "entity.h"

class MoveTest2 : public TestRunner {
public:
    MoveTest2();
    ~MoveTest2() = default;

    void update();
    void render(Renderer &renderer);

private:
    int counter;
    std::unique_ptr<MovableStickman> stickman;
    std::vector<std::unique_ptr<Entity>> obstacles;
};

#endif // MOVETEST2_H
