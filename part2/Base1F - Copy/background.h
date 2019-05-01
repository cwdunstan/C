#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <string>
#include "coordinate.h"
#include <QPainter>

class Background {
public:
    Background() = default;

    void setCoordinate(Coordinate coordinate);

    int getVelocity();
    void setVelocity(int velocity);

    void setSprite(std::string path);

    void render(QPainter &painter, unsigned int time);

private:
    Coordinate coordinate;
    int velocity;
    QPixmap sprite;
};

#endif // BACKGROUND_H
