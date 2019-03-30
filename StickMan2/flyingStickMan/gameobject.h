#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "filereader.h"
#include <QPixmap>
#include <QPainter>

//List of objects, BG = Background.
enum objectType{BG};
//game object
class gameObject{
public:
    virtual ~gameObject(){}
    virtual int getWidth(){return this->m_width;}
    virtual int getHeight(){return this->m_height;}
    virtual void setTexture(std::string path)=0;
    virtual void render(QPainter &painter, unsigned int time)=0;
protected:
    int m_width=1200;
    int m_height=800;
};


//concrete main background
class background:public gameObject{
  public:
    background(fileReader f){
        this->m_bgPath=f.getBgPath();
        this->m_height=f.getFrameHeight();
        this->m_speed=f.getVelocity();
        this->m_width=f.getFrameWidth();
        this->m_startspeed=f.getVelocity();
    }

    virtual void setTexture(std::string path){m_bgPath=path;}
    virtual void render(QPainter &painter, unsigned int time){
        //convert file path to Qstring, used to draw onto background rectangle
        QPixmap bgimg;
        QString imgpath=QString::fromStdString(m_bgPath);
        //if backgorund filepath is loaded
        if(bgimg.load(imgpath)){
            double currentx = (time*m_speed)%m_width;
            painter.drawPixmap(-currentx,0,m_width,m_height,bgimg);
            painter.drawPixmap(-currentx+m_width,0,m_width,m_height,bgimg);
        }
    }
 private:
    unsigned int m_width;
    unsigned int m_height;
    int m_speed;
    int m_startspeed;
    std::string m_bgPath;
};

//creator
class backgroundFactory{
public:
    virtual gameObject * newObject(enum objectType type, fileReader filep){
        switch(type){
        case BG:
                return new background(filep);
        default:
            return nullptr;
        }
    }
};

#endif // GAMEOBJECT_H


