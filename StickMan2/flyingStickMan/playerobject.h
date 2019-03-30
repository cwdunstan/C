#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H


#include <string>
#include "filereader.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>

//game object
class playerObject{
public:
    virtual ~playerObject(){}

    virtual void render(QPainter &painter, unsigned int time, int frameHeight, int xcoord)
    {

        //f for scaling Factor
        double f=m_size;
        //x for x coordinate
        int x = xcoord;
        double y=(frameHeight-(f*(frameHeight/4)));

        //draw head
        if(this->powerlevel==0){
            painter.setPen ( QPen(Qt::black,5));
            painter.setBrush( QBrush( Qt::white ) );
        //draw arms (points = left hand, neck, right hand)
            painter.drawEllipse(x,y,f*(frameHeight/16),f*(frameHeight/16));
        static QPointF arms[3] = {
            QPointF(x-(f*frameHeight/32),y+(f*frameHeight/8)),
            QPointF(x+(f*frameHeight/48),y+(f*frameHeight/16)),
            QPointF(x+(f*frameHeight/16),y+(f*frameHeight/8))
        };
        painter.drawPolyline(arms, 3);
        //draw body
        painter.drawLine(x+(f*frameHeight/48),y+(f*frameHeight/16),x+(f*frameHeight/48),y+(f*frameHeight/6));
        //draw legs (points = left foot, neck, right foot)
        static  QPointF legs[3] = {
            QPointF(x-(f*frameHeight/32),y+(f*frameHeight/4)),
            QPointF(x+(f*frameHeight/48),y+(f*frameHeight/6)),
            QPointF(x+(f*frameHeight/16),y+(f*frameHeight/4)),
        };
        painter.drawPolyline(legs, 3);
        }
        if(this->powerlevel==1){
         painter.setBrush( QBrush( Qt::red) );
         painter.setPen ( QPen(Qt::white,5));
         double y=(frameHeight-(f*(frameHeight/5)));
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
    }

    virtual void setState(int n){
        this->powerlevel=n;
    }
protected:
    //int representation of size
    double m_size=1;
    //int representation of size
    int powerlevel=0;
};

class tinyPlayer:public playerObject{
public:
    tinyPlayer(){
        this->m_size=0.5;
    }
    //int representation of size
};

class normalPlayer:public playerObject{
public:
    normalPlayer(){
        this->m_size=1.5;
    }
    //int representation of size
};

class largePlayer:public playerObject{
public:
    largePlayer(){
        this->m_size=2.5;
    }
    //int representation of size
};

class giantPlayer:public playerObject{
public:
    giantPlayer(){
        this->m_size=3.5;
    }

};


//
class playerFactory{
public:
    virtual playerObject * newPlayer(std::string size){
        if(size.compare("tiny")==0){
                return new tinyPlayer();
        }
        if(size.compare("normal")==0){
                return new normalPlayer();
        }
        if(size.compare("large")==0){
                return new largePlayer();
        }
        if(size.compare("giant")==0){
                return new giantPlayer();
        }
    }
};

#endif // PLAYEROBJECT_H
