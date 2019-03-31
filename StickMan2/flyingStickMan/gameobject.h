#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "filereader.h"

#include <string>
#include <QPainter>
#include <QPixmap>

//enumerator for object types
//currently only background (BG), but other generic objects could be added here
enum objectType { BG };

//generic object factory design
//currenty used to create game background object,
//other objects can be added if of the same type (i.e. boxes, background objects).
//sets background texture from filepath read from filereader object
//pure virtual render function
class gameObject {
  public:
    virtual ~gameObject() {}
    virtual int getHeight() {
      return this->m_height;
    }
    virtual int getWidth() {
      return this->m_width;
    }
    virtual void setTexture(std::string path)=0;
    virtual void render(QPainter &painter, unsigned int time)=0;
protected:
    int m_width = 1200;
    int m_height = 800;
};

//background implementation of gameobject
//renders two background objects, one in frame, one fully out of frame
//moves objects from left to right, repeating loop when first on is out of frame
class background : public gameObject {
  public:
    background(fileReader f){
      this->m_height = f.getFrameHeight();
      this->m_width = f.getFrameWidth();
      this->m_speed = f.getVelocity();
      this->m_bgPath = f.getBgPath();
    }
    virtual void setTexture(std::string path){
      m_bgPath = path;
    }
    virtual void render(QPainter &painter, unsigned int time) {
      QPixmap bgimg;
      QString imgpath = QString::fromStdString(m_bgPath);
      if (bgimg.load(imgpath)) {
        //current x represents where background image is drawn from, % modulo is used to loop drawing when out of frame
        double currentx = (time * m_speed) % m_width;
        //two objects are drawn to mimic and endless scrolling background, each looping at different intervals
        painter.drawPixmap(-currentx, 0, m_width, m_height, bgimg);
        painter.drawPixmap(-currentx + m_width, 0, m_width, m_height, bgimg);
      }
    }
  private:
    int m_width;
    int m_height;
    int m_speed;
    std::string m_bgPath;
};

//background factory implementation
class backgroundFactory {
  public:
    virtual gameObject * newObject(enum objectType type, fileReader filep) {
      switch(type){
        case BG :
          return new background(filep);
      }
    }
};

#endif // GAMEOBJECT_H


