#ifndef LIVES_H
#define LIVES_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"

class Lives {
public:
    Lives(int startingLives);

    void increment();
    void decrement();
    int getLives();
    void render(Renderer &renderer);

private:
    unsigned int currLives;
    QPixmap digits[8];
};

#endif // LIVES_H
