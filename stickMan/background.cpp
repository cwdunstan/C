#include "background.h"

//background constructor, width & height of image (not frame) and the scrolling speed.
Background::Background(int width, int height, double speed, std::string bgPath):
    m_width(width),
    m_height(height),
    m_speed(speed),
    m_bgPath(bgPath)
{}


void Background::render(QPainter &painter, unsigned int time,int framewidth)
{
    painter.setPen ( Qt::transparent );
    painter.setBrush( QBrush( Qt::yellow ) );
    QPixmap bgimg;
    QString imgpath="../stickMan/fish.png";
            //QString::fromStdString(m_bgPath);

    if(bgimg.load(imgpath)){
       painter.drawPixmap((framewidth-(time*m_speed))-framewidth,0,m_width,m_height,bgimg);
    }
    else{
    //draw one background in frame
    if((framewidth-(time*m_speed))+m_width>0){
        painter.drawRect((framewidth-(time*m_speed))-framewidth,0,m_width,m_height);
    }
    //draw one completely off frame
    //every update, push to the right
    }

}

