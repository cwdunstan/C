#include "poweruptest.h"
#include "coordinate.h"

PowerUpTest::PowerUpTest() : TestRunner("PowerUpTest") {
    stickman = std::make_unique<JumpingStickman>(50);
    stickman->setSprite(":sprites/sprite0.png");
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSize("normal");
    stickman->setMoving(true);
    obstacles.push_back(std::move(std::make_unique<PowerUp>(Coordinate(400, 50, 450), 2)));

}

void PowerUpTest::update() {
    stickman->update(obstacles);
    for(auto &o : obstacles) {
        o->collisionLogic(*stickman);
        if (o->getCoordinate().getXCoordinate() < -10 && stickman->getSize()=="giant") {
            status = Status::Passed;
        }
    }

}

void PowerUpTest::render(Renderer &renderer) {
    stickman->render(renderer, counter++);
    for(auto &o : obstacles) {
        o->render(renderer, counter);
    }
}
