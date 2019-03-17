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
    //convert file path to Qstring, used to draw onto background rectangle
    QPixmap bgimg;
    QString imgpath=QString::fromStdString(m_bgPath);

    //if backgorund filepath is loaded
    if(bgimg.load(imgpath)){

        //current x = starting x, moving to the left with each render
        double currentx=(framewidth-(time*m_speed))-framewidth;

        //if there is still image left to the right of the screen, keep scrolling
        if(currentx+m_width>framewidth){
            painter.drawPixmap(currentx,0,m_width,m_height,bgimg);
        }
        //end of image reached, draw static image
        else{
             painter.drawPixmap((-m_width)+framewidth,0,m_width,m_height,bgimg);
        }
    }

}
