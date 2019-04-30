#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>

class Score {
public:
    Score();

    void increment();
    void render(QPainter &painter);

private:
    unsigned int hiscore;
    unsigned int currScore;
    QPixmap digits[10];
};

#endif // SCORE_H
