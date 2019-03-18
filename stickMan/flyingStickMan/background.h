#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPixmap>
#include <QPainter>

class Background
{

public:
    Background(int width, int height, int speed, std::string bgPath);

    ~Background(){}

    void render(QPainter &painter, unsigned int time);

private:
    unsigned int m_width;
    unsigned int m_height;
    int m_speed;
    std::string m_bgPath;
};

#endif // BACKGROUND_H
