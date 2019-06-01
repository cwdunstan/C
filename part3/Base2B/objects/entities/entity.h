#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cstdlib>
#include <string>
#include <QPixmap>
#include <QPainter>
#include <memory>
#include "stickman.h"
#include "coordinate.h"
#include "gameobject.h"
#include "renderer.h"

class Entity : public GameObject {
public:
    Entity() = default;
    Entity(std::string name, Coordinate coordinate, int velocity);
    virtual ~Entity() = default;

    virtual void collisionLogic(Stickman &player);
    virtual void updateCoordinate();
    virtual void render(Renderer &renderer, unsigned int time);

    virtual Coordinate &getCoordinate();
    virtual Coordinate &getStartCoordinate();
    virtual void setOffset(int distance);
    virtual int getOffset();
    virtual QPixmap &getSprite();
    virtual int width();
    virtual int height();
    virtual void setSize(int width, int height);
    virtual int getVelocity();
    virtual void setVelocity(int v);
    virtual std::string getName();
    virtual bool getPointsGiven();
    virtual void setPointsGiven(bool status);

    virtual std::unique_ptr<Entity> clone();

protected:
    std::string name;
    Coordinate coordinate;
    Coordinate startCoordinate;
    int offset;
    int velocity;
    QPixmap sprite;
    int widthOverride;
    int heightOverride;
    bool pointsGiven;

    void setSprite(QPixmap &pm);
    void updateSprite(unsigned int time);
};

class Bird: public Entity {
public:
    Bird(Coordinate coordinate, int velocity);

    void randomiseHeight();
};

class Cactus: public Entity {
public:
    Cactus(Coordinate coordinate, int velocity);

    void randomiseSprite();
};

class Cloud: public Entity {
public:
    Cloud(Coordinate coordinate, int velocity);

    void randomiseHeight();
};

class Checkpoint: public Entity {
public:
    Checkpoint(Coordinate coordinate, int velocity);

};

class PowerUp: public Entity {
public:
    PowerUp(Coordinate coordinate, int velocity);
};

class speedBoost: public Entity {
public:
    speedBoost(Coordinate coordinate, int velocity);
};

class health: public Entity {
public:
    health(Coordinate coordinate, int velocity);
};

class points: public Entity {
public:
    points(Coordinate coordinate, int velocity);
};


#endif // OBSTACLE_H
