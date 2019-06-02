#include "powertest.h"
#include "coordinate.h"

PowerTest::PowerTest() : TestRunner("PowerTest") {
    stickman = std::make_unique<JumpingStickman>(50);
    stickman->setSprite(":sprites/sprite0.png");
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSize("normal");
    stickman->setMoving(true);

    obstacles.push_back(std::move(std::make_unique<PowerUp>(Coordinate(400, 50, 450), 2)));
    obstacles.push_back(std::move(std::make_unique<Bird>(Coordinate(500, 50, 450), 2)));
}

void PowerTest::update() {
    stickman->update(obstacles);

    for (auto &o : obstacles) {
        o->collisionLogic(*stickman);
    }

    if (obstacles[obstacles.size()-1]->getCoordinate().getXCoordinate() < 0) {
        status = Status::Passed;
    }

}

void PowerTest::render(Renderer &renderer) {
    stickman->render(renderer, counter++);

    for (auto &o : obstacles) {
        o->render(renderer, counter);
    }
}
