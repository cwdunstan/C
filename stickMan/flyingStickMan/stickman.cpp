#include "stickman.h"
#include<iostream>


stickMan::stickMan(int x_coordinate, double velocity, double size):
    m_xcoordinate(x_coordinate),
    m_Velocity(velocity),
    m_size(size)
{}

void stickMan::render(QPainter &painter, unsigned int time, int frameHeight)
{
    //f for scaling Factor
    double f=m_size;
    //x for x coordinate
    int x=m_xcoordinate;
    double y=(frameHeight-(f*320));
    painter.setPen ( QPen(Qt::black,5));
    painter.setBrush( QBrush( Qt::white ) );

    //draw head
    painter.drawEllipse(x,y,f*80,f*80);

    //draw arms (points = left hand, neck, right hand)
    static const QPointF arms[3] = {
        QPointF(x-(f*5),y+(f*180)),
        QPointF(x+(f*40),y+(f*80)),
        QPointF(x+(f*85),y+(f*180)),
    };
    painter.drawPolyline(arms, 3);
    //draw body
    painter.drawLine(x+(f*40),y+(f*80),x+(f*40),y+(f*220));
    //draw legs (points = left foot, neck, right foot)
    static const QPointF legs[3] = {
        QPointF(x-(f),y+(f*320)),
        QPointF(x+(f*40),y+(f*220)),
        QPointF(x+(f*80),y+(f*320)),
    };
    painter.drawPolyline(legs, 3);

}

//head = 2*f*80
//body = f*240
