#ifndef STICKMAN_H
#define STICKMAN_H

#include "gameobject.h"
#include "coordinate.h"
#include "renderer.h"
#include <string>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <memory>

class Entity;
class Stickman : public GameObject {
public:
    Stickman() = default;
    virtual ~Stickman();

    void setCoordinate(Coordinate coordinate);

    void setSize(std::string size);

    void setSprite(std::string path);

    Coordinate &getCoordinate();

    void render(Renderer &renderer, unsigned int time);

    bool getCheckpoint();
    void setCheckpoint(bool set);
    void setScore(int score);
    int getScore();
    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles);

    bool isMoving();
    void setMoving(bool val);
    bool isMovingRight();
    bool isMovingLeft();
    bool isColliding();
    int width();
    int height();

protected:
    int highscore;
    bool colliding;
    bool movingLeft=false;
    bool movingRight=false;
    bool checkpoint;

private:
    Coordinate coordinate;
    std::string size;
    QPixmap sprite;
};

#endif // STICKMAN_H
