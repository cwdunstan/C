#include "background.h"
#include <QMessageBox>

//background constructor, width & height of image (not frame) and the scrolling speed.
Background::Background(int width, int height, int speed, std::string bgPath):
    m_width(width),
    m_height(height),
    m_speed(speed),
    m_bgPath(bgPath)
{}


void Background::render(QPainter &painter, unsigned int time)
{
    //convert file path to Qstring, used to draw onto background rectangle
    QPixmap bgimg;
    QString imgpath=QString::fromStdString(m_bgPath);
    //if backgorund filepath is loaded
    if(bgimg.load(imgpath)){
        double currentx = (time*m_speed)%m_width;//-((time%(m_width/m_speed))*m_speed);
        painter.drawPixmap(-currentx,0,m_width,m_height,bgimg);
        painter.drawPixmap(-currentx+m_width,0,m_width,m_height,bgimg);


    }

}
