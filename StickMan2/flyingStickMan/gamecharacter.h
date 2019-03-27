#pragma once
#include <string>
#include "filereader.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>

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
        double y=(frameHeight-(f*320));
        painter.setPen ( QPen(Qt::black,7));
        painter.setBrush( QBrush( Qt::white ) );

        //draw head
        painter.drawEllipse(x,y,f*80,f*80);

        //draw arms (points = left hand, neck, right hand)
        static QPointF arms[3] = {
            QPointF(x-(f*5),y+(f*180)),
            QPointF(x+(f*40),y+(f*80)),
            QPointF(x+(f*85),y+(f*180)),
        };
        painter.drawPolyline(arms, 3);
        //draw body
        painter.drawLine(x+(f*40),y+(f*80),x+(f*40),y+(f*220));
        //draw legs (points = left foot, neck, right foot)
        static  QPointF legs[3] = {
            QPointF(x-(f),y+(f*320)),
            QPointF(x+(f*40),y+(f*220)),
            QPointF(x+(f*80),y+(f*320)),
        };
        painter.drawPolyline(legs, 3);

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


