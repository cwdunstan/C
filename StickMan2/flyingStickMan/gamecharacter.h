#pragma once
#include <string>
#include "filereader.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <cMath>

enum characterType{PLAYER};
//game object
class gameCharacter{
public:
    virtual ~gameCharacter(){}

    virtual void render(QPainter &painter, unsigned int time, int frameheight)=0;
};


//concrete main background
class player:public gameCharacter{
  public:
    player(fileReader f){
        this->m_xcoordinate=f.getX();
        this->m_Velocity=f.getVelocity();
        this->m_size=f.getSize();
    }
    virtual void render(QPainter &painter, unsigned int time, int frameHeight)
    {
        //f for scaling Factor
        double f=m_size;
        //x for x coordinate
        int x=m_xcoordinate;
        double y=(frameHeight-(f*(frameHeight/5)));
        painter.setPen ( QPen(Qt::black,5));
        painter.setBrush( QBrush( Qt::white ) );

        //draw head
        painter.drawEllipse(x,y,f*(frameHeight/16),f*(frameHeight/16));
        //draw arms (points = left hand, neck, right hand)
        static QPointF arms[3] = {
            QPointF(x-(f*frameHeight/11),y+(f*frameHeight/14)),
            QPointF(x+(f*frameHeight/48),y+(f*frameHeight/16)),
            QPointF(x-(f*frameHeight/13),y+(f*frameHeight/18))
        };
        painter.drawPolyline(arms, 3);
        //draw body

        painter.drawLine(x+(f*frameHeight/48),y+(f*frameHeight/16),x-(f*frameHeight/16),y+(f*frameHeight/8));
        //draw legs (points = left foot, neck, right foot)
        static  QPointF legs[5] = {
            QPointF(x-(f*frameHeight/8),y+(f*frameHeight/5)),
            QPointF(x-(f*frameHeight/13),y+(f*frameHeight/6)),
            QPointF(x-(f*frameHeight/16),y+(f*frameHeight/8)),
            QPointF(x,y+(f*frameHeight/7)),
            QPointF(x-(f*frameHeight/32),y+(f*frameHeight/5)),
        };
        painter.drawPolyline(legs, 5);

    }
 private:
    // x coordinate
    int m_xcoordinate;
    // y coordinate
    int m_ycoordinate;
    //starting velocity
    double m_Velocity;
    //int representation of size
    double m_size;
};

//creator
class characterFactory{
public:
    virtual gameCharacter * newCharacter(enum characterType type, fileReader filep){
        switch(type){
        case PLAYER:
                return new player(filep);
        default:
            return nullptr;
        }
    }
};


