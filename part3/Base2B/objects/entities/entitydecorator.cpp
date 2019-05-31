#include "entitydecorator.h"

EntityDecorator::EntityDecorator(std::unique_ptr<Entity> entity) : entity(std::move(entity)) {

}

EntityDecorator::~EntityDecorator() {

}

std::unique_ptr<Entity> EntityDecorator::clone() {
    return entity->clone();
}

QPixmap &EntityDecorator::getSprite() {
    return entity->getSprite();
}

void EntityDecorator::updateCoordinate() {
    entity->updateCoordinate();
}

void EntityDecorator::collisionLogic(Stickman &player) {
    entity->collisionLogic(player);
}

Coordinate &EntityDecorator::getCoordinate() {
    return entity->getCoordinate();
}

Coordinate &EntityDecorator::getStartCoordinate() {
    return entity->getStartCoordinate();
}

void EntityDecorator::setOffset(int distance) {
    entity->setOffset(distance);
}

int EntityDecorator::getOffset() {
    return entity->getOffset();
}

void EntityDecorator::setVelocity(int v) {
    entity->setVelocity(v);
}

int EntityDecorator::getVelocity() {
    return entity->getVelocity();
}

int EntityDecorator::width() {
    return entity->width();
}

int EntityDecorator::height() {
    return entity->height();
}

void EntityDecorator::render(Renderer &renderer, unsigned int time) {
    entity->render(renderer, time);
}

void EntityDecorator::setSize(int width, int height) {
    entity->setSize(width, height);
}

std::string EntityDecorator::getName(){
    return entity->getName();
}
