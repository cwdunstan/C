#include "movablestickman.h"
#include "collision.h"
#include <QMessageBox>

MovableStickman::MovableStickman(int floor, int jumpImpulse, int maxJumpCount, int gravity) :
    floor(floor), jumpImpulse(jumpImpulse), jumpVelocity(0), gravity(gravity), jumpCount(0), maxJumpCount(maxJumpCount)  {

}

MovableStickman::~MovableStickman() {

}

void MovableStickman::jump() {
    jumpVelocity = jumpImpulse;
    grounded = false;
    jumpCount++;
}

bool MovableStickman::canJump() {
    return jumpCount < maxJumpCount;
}

void MovableStickman::setLives(int Lives) {
    lives=Lives;
}

int MovableStickman::getLives() {
    return lives;
}

void MovableStickman::handleInput(QKeyEvent &event) {
    if(event.type() == QEvent::KeyPress) {
        if (event.key() == Qt::Key_Space && !event.isAutoRepeat() && canJump()) {
            jump();
        }
        if (event.key() == Qt::Key_Right && !event.isAutoRepeat()) {
            movingRight=true;
            movingLeft=false;
        }
        if (event.key() == Qt::Key_Left && !event.isAutoRepeat()) {
            movingLeft=true;
            movingRight=false;

        }
    }

    if(event.type() == QEvent::KeyRelease) {
        if (event.key() == Qt::Key_Right && !event.isAutoRepeat()) {
            movingRight=false;
        }
        if (event.key() == Qt::Key_Left && !event.isAutoRepeat()) {
            movingLeft=false;
        }
    }

}



void MovableStickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {
    Coordinate &ac = getCoordinate();
    int newY = ac.getYCoordinate() + jumpVelocity;
    colliding = false;

    // Check for collisions
    for (auto &other : obstacles) {
        Collision::CollisonResult col = Collision::moveCast(*this, *other, 0, jumpVelocity);
        if (movingLeft) {
            other->setVelocity(-abs(other->getVelocity()));
        }
        else if (movingRight) {
            other->setVelocity(abs(other->getVelocity()));
        }
        if (col.overlapped) {
            int by = other->getCoordinate().getYCoordinate();
            if (col.down && jumpVelocity < 0) {
                // Hitting obstacle from above
                jumpVelocity = 0;
                grounded = true;
                jumpCount = 0;
                newY = by + other->height() + 1;
            } else if (col.up) {
                // Hitting obstacle from below
                jumpVelocity = 0;
                newY = by - height() - 1;
            } else {
                // Hidding obstacle from the side
                if (!other->getName().compare("Checkpoint")==0) {
                    colliding = true;
                } else {

                }
            }
        }
    }

    // Check if we're below the floor
    if (newY <= floor) {
        newY = floor;
        grounded = true;
        jumpVelocity = 0;
        jumpCount = 0;
    }

    ac.setYCoordinate(newY);
    jumpVelocity += gravity;

}
