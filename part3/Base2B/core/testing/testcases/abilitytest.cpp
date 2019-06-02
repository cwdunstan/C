#include "abilitytest.h"
#include "coordinate.h"

AbilityTest::AbilityTest() : TestRunner("CollisionTest") {
    stickman = std::make_unique<JumpingStickman>(50);
    stickman->setSprite(":sprites/sprite0.png");
    stickman->setCoordinate(Coordinate(50, 50, 450));
    stickman->setSize("normal");
    stickman->setMoving(true);


    obstacles.push_back(std::move(std::make_unique<PowerUp>(Coordinate(400, 50, 450), 2)));
    obstacles.push_back(std::move(std::make_unique<speedBoost>(Coordinate(500, 50, 450), 2)));
    obstacles.push_back(std::move(std::make_unique<health>(Coordinate(600, 50, 450), 2)));
    obstacles.push_back(std::move(std::make_unique<points>(Coordinate(700, 50, 450), 2)));

}

void AbilityTest::update() {
    stickman->update(obstacles);
    for(auto &o : obstacles) {
        o->collisionLogic(*stickman);
    }
}

void AbilityTest::render(Renderer &renderer) {
    stickman->render(renderer, counter++);
    for(auto &o : obstacles) {
        o->render(renderer, counter);
    }
}
