#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "filereader.h"

#include <string>
#include <QPainter>
#include <QPen>
#include <QPixmap>

//Generic Player object factory
//has global render function to draw a stick man in 2 states, normal and powerful
//uses dynamic x and y values to calculate and draw stick man. Each draw function takes into
//account frame size and hight to ensure scalability.
//has setState function to change player power level
class playerObject {
  public:
    virtual ~playerObject(){}
    virtual void render(QPainter &painter, unsigned int time, int frameHeight, int xcoord) {
      double f = m_size;
      int x = xcoord;
      //set relative y value
      double y = (frameHeight - (f * (frameHeight / 4)));
      // Default power level, draws standard Player
      if (this->powerlevel == 0) {
        painter.setPen (QPen (Qt::black, 5));
        painter.setBrush (QBrush (Qt::white));
        //draw head
        painter.drawEllipse (x, y, f * (frameHeight / 16), f * (frameHeight / 16));
        //draw arms - 3 points
        static QPointF arms[3] = {
          QPointF (x - (f * frameHeight / 32), y + (f * frameHeight / 8)),
          QPointF (x + (f * frameHeight / 48), y + (f * frameHeight / 16)),
          QPointF (x + (f * frameHeight / 16), y + (f * frameHeight / 8))
        };
        painter.drawPolyline(arms, 3);
        //draw body - 2 points
        painter.drawLine (x + (f * frameHeight / 48), y + (f * frameHeight / 16),
                          x + (f * frameHeight / 48), y + (f * frameHeight / 6));
        //draw legs - 3 points
        static  QPointF legs[3] = {
            QPointF(x-(f*frameHeight/32),y+(f*frameHeight/4)),
            QPointF(x+(f*frameHeight/48),y+(f*frameHeight/6)),
            QPointF(x+(f*frameHeight/16),y+(f*frameHeight/4)),
        };
        painter.drawPolyline(legs, 3);
      }
      //Higher Power Level, Draws Naruto Running Player, and changes colour
      if (this->powerlevel == 1) {
        painter.setBrush (QBrush (Qt::red));
        painter.setPen (QPen (Qt::white, 5));
        //set relative y value
        double y = (frameHeight - (f * (frameHeight / 5)));
        //draw head
        painter.drawEllipse (x, y, f * (frameHeight / 16), f * (frameHeight / 16));
        //draw arms - 3 points
        static QPointF arms[3] = {
          QPointF (x - (f * frameHeight / 11), y + (f * frameHeight / 14)),
          QPointF (x + (f * frameHeight / 48), y + (f * frameHeight / 16)),
          QPointF (x - (f * frameHeight / 13), y + (f * frameHeight / 18))
        };
        painter.drawPolyline(arms, 3);
        //draw body - 2 points
        painter.drawLine (x + (f * frameHeight / 48), y + (f * frameHeight / 16),
                          x - (f * frameHeight / 16), y + (f * frameHeight / 8));
        //draw legs - 3 points
        static  QPointF legs[5] = {
          QPointF(x - (f * frameHeight / 8), y + (f * frameHeight / 5)),
          QPointF(x - (f * frameHeight / 13), y + (f * frameHeight / 6)),
          QPointF(x - (f * frameHeight / 16), y+ (f * frameHeight / 8)),
          QPointF(x, y + (f * frameHeight / 7)),
          QPointF(x - (f * frameHeight / 32), y + (f * frameHeight / 5)),
        };
        painter.drawPolyline (legs, 5);
      }
    }
    virtual void setState (int n) {
      this->powerlevel = n;
    }
  protected:
    double m_size=1;
    int powerlevel=0;
};
//tiny player object
class tinyPlayer : public playerObject {
  public:
    tinyPlayer() {
      this->m_size=0.5;
    }
};
//normal player object
class normalPlayer : public playerObject {
  public:
    normalPlayer() {
      this->m_size=1.5;
    }
};
//large player object
class largePlayer : public playerObject {
  public:
    largePlayer() {
      this->m_size=2.5;
    }
};
//giant player object
class giantPlayer : public playerObject {
  public:
    giantPlayer() {
      this->m_size=3.5;
    }
};

//initialize playerobject factory
class playerFactory {
  public:
    virtual playerObject * newPlayer (std::string size) {
      if (size.compare("tiny")  ==  0) {
        return new tinyPlayer();
      }
      if (size.compare("normal") == 0) {
        return new normalPlayer();
      }
      if (size.compare ("large") == 0) {
        return new largePlayer();
      }
      if (size.compare("giant") == 0) {
        return new giantPlayer();
      }
    }
};

#endif // PLAYEROBJECT_H
