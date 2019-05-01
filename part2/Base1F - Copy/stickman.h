#ifndef STICKMAN_H
#define STICKMAN_H

#include "coordinate.h"
#include <string>
#include <QPainter>

class Stickman {
public:
    Stickman() = default;

    void setCoordinate(Coordinate coordinate);

    void setSize(std::string size);

    void setSprite(std::string path);

    void jump();

    void render(QPainter &painter, unsigned int time);

private:
    Coordinate coordinate;
    std::string size;
    QPixmap sprite;
    //additions
    int jumping=0;
    int initalY;
    int curJump;
    int maxJumps;
    bool falling = false;
    bool djump = false;
};

#endif // STICKMAN_H
