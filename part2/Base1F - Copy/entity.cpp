#include "entity.h"


Entity::Entity(std::string name, Coordinate coordinate, int velocity, int size, int offset):
    name(name),
    coordinate(coordinate),
    velocity(velocity),
    offset(offset),
    size(size){
    updateSprite(0);
}

Coordinate Entity::getCoordinate() {
    return coordinate;
}

void Entity::incrementVelocity() {
    velocity++;
}

int Entity::width() {
    return sprite.width();
}

int Entity::getOffset() {
    return offset;
}

void Entity::collisionLogic() {
    return;
}

void Entity::updateCoordinate() {
    coordinate.setXCoordinate(coordinate.getQtRenderingXCoordinate() - velocity);
}

void Entity::updateSprite(unsigned int time) {
    if (name == "cactus" || name == "cloud") {
        return;
    }
    std::string spritePath = ":" + name + std::to_string(((time/10)%2)).append(".png");
    QPixmap sprite(QString::fromStdString(spritePath));
    this->sprite=sprite.scaled(size*50,size*50);
}

void Entity::render(QPainter &painter, unsigned int time) {
    painter.drawPixmap(coordinate.getQtRenderingXCoordinate(), coordinate.getQtRenderingYCoordinate() - sprite.height(), sprite);
    this->updateCoordinate();
    updateSprite(time);

}

Bird::Bird(Coordinate coordinate, int velocity, int size, int offset):
    Entity("bird", coordinate, velocity, size, offset) {}

// Spawn bird at random height in the sky
void Bird::randomiseHeight() {
    this->coordinate.setYCoordinate(150 + 35*(rand() % 4));
}

void Bird::collisionLogic() {
    // TODO
}

Cactus::Cactus(Coordinate coordinate, int velocity, int size, int offset):
    Entity("cactus", coordinate, velocity, size, offset) {}

// Choose from 3 random cactuses
void Cactus::randomiseSprite() {
    std::string spritePath = ":" + name + std::to_string(rand() % 3) + ".png";
    QPixmap sprite(QString::fromStdString(spritePath));
    this->sprite = sprite.scaled(size*40,size*50);
}

void Cactus::collisionLogic() {
    // TODO
}

Cloud::Cloud(Coordinate coordinate, int velocity, int size, int offset):
    Entity("cloud", coordinate, velocity, size, offset) {
    std::string spritePath = name + "0.png";
    QPixmap sprite(QString::fromStdString(spritePath));
    this->sprite = sprite;
}

// Clouds can spawn at random height in the sky
void Cloud::randomiseHeight() {
    this->coordinate.setYCoordinate(coordinate.getQtRenderingYCoordinate() + 30*(rand() % 6));
}

