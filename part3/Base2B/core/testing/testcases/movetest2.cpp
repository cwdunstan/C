#include "movetest.h"
#include "coordinate.h"

MoveTest::MoveTest() : TestRunner("JumpTest") {
    stickman = std::make_unique<MovableStickman>(50);
    stickman->setSprite(":sprites/sprite0.png");
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSize("normal");

    obstacles.push_back(std::move(std::make_unique<Bird>(Coordinate(400, 50, 450), 2)));
}

void MoveTest::update() {
    stickman->update(obstacles);
    if (stickman->isColliding()) {
        stickman->jump();
    }

    auto &o = obstacles[0];
    o->collisionLogic(*stickman);
    if (o->getCoordinate().getXCoordinate() < 0) {
        status = Status::Passed;
    }
}

void MoveTest::render(Renderer &renderer) {
    stickman->render(renderer, counter++);
    obstacles[0]->render(renderer, counter);
}
