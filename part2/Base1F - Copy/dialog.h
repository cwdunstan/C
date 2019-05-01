#ifndef DIALOG_H
#define DIALOG_H

#include <vector>
#include <QDialog>
#include <QPainter>
#include <QFile>
#include <QTimer>
#include <QKeyEvent>
#include "stickman.h"
#include "background.h"
#include "entity.h"
#include "moon.h"
#include "score.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void setStickman(Stickman stickman);
    void setBackground(Background background);
    void setMoon(Moon moon);
    void setArgs(QStringList list);

protected:
    void paintEvent(QPaintEvent *event);
    void renderBackground(QPainter &painter, unsigned int counter);
    void renderClouds(QPainter &painter, unsigned int counter);
    void renderObstacles(QPainter &painter, unsigned int counter);
    void spawnObstacles(unsigned int counter);
    void addObstacle(Entity obstacle);
    void speedUp(unsigned int counter);
    void keyPressEvent(QKeyEvent *event);



private:
    Ui::Dialog *ui;
    Stickman stickman;
    Background background;
    bool night;
    Moon moon;
    std::vector<Entity> obstacles;
    std::vector<Entity> clouds;
    Score score;
    EntityFactory factory;
    int obstacleSpawnFrame;
    int cloudSpawnFrame;
    int counter;
    //addition
    QStringList args;

public slots:
    void nextFrame();
};

#endif // DIALOG_H
