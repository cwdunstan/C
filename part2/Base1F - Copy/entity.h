#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cstdlib>
#include <string>
#include <QPixmap>
#include <QPainter>
#include "coordinate.h"

class Entity {
public:
    Entity() = default;
    Entity(std::string name, Coordinate coordinate, int velocit, int size, int offset);
    ~Entity() = default;

    virtual void collisionLogic();
    virtual void updateCoordinate();
    int getOffset();
    Coordinate getCoordinate();
    void incrementVelocity();
    int width();
    void render(QPainter &painter, unsigned int time);

protected:
    std::string name;
    Coordinate coordinate;
    int velocity;
    int size;
    int offset;
    QPixmap sprite;

    void updateSprite(unsigned int time);
};

class Bird: public Entity {
public:
    Bird(Coordinate coordinate, int velocity, int size, int offset);
    void randomiseHeight();
    void collisionLogic() override;
};

class Cactus: public Entity {
public:
    Cactus(Coordinate coordinate, int velocity, int size, int offset);

    void randomiseSprite();
    void collisionLogic() override;
};

class Cloud: public Entity {
public:
    Cloud(Coordinate coordinate, int velocity, int size, int offset);

    void randomiseHeight();
};

// Each entity simply moves horizontally along the background
// As they have slightly different behaviours, they extend a parentsubclass
// And instantiation of each of them occur through the factory method
class EntityFactory {
public:
    void setVelocity(int velocity) {
        this->velocity = velocity;
    }

    Entity getEntity(std::string name, int y, std::string size, int x) {
        int tempsize;
        if(size.compare("n")==0){
            tempsize=1;
        }
        if(size.compare("l")==0){
            tempsize=2;
        }

        if (name == "bird") {
            Coordinate coordinate(800+x, 148+y, 450);
            Bird randomBird(coordinate, velocity, tempsize, x);
            return randomBird;
        } else if (name == "cactus") {
            Coordinate coordinate(800+x, 148+y, 450);
            Cactus randomCactus(coordinate, velocity, tempsize, x);
            randomCactus.randomiseSprite();
            return randomCactus;
        } else if (name == "cloud") {
            Coordinate coordinate(800+x, 148+y, 450);
            Cloud randomCloud(coordinate, velocity / 2, tempsize, x);
            randomCloud.randomiseHeight();
            return randomCloud;
        }
    }

private:
    int velocity;


};

#endif // OBSTACLE_H
