#ifndef STICKMAN_H
#define STICKMAN_H

#include <stdlib.h>
#include <QPainter>
#include <QPen>
#include <string>

class stickMan
{

public:
    stickMan(int x_coordinate, double velocity, double size);

    ~stickMan(){}

    void render(QPainter &painter, unsigned int time);


private:
    // tiny, normal, large, and giant
    //starting x coordinate
    int m_xcoordinate;
    //starting velocity
    double m_Velocity;
    //int representation of size
    double m_size;

};

#endif // STICKMAN_H
