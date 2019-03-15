#include "dialog.h"
#include "ui_dialog.h"
#include<iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

Dialog::Dialog(int frameWidth, int frameHeight, int xcoord, double manSize, double velocity, std::string filepath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_background(Background(2000,600,velocity,filepath)),
    m_xcoord(xcoord),
    m_stickMan(stickMan(xcoord,velocity,manSize)),
    m_counter(0),
    m_frameHeight(frameHeight),
    m_frameWidth(frameWidth),
    m_manSize(manSize),
    m_velocity(velocity),
    m_filepath(filepath)
{
    ui->setupUi(this);
    this->resize(frameWidth, frameHeight);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    bool animation = true;
    if (animation) {
        QPainter painter(this);
        m_background.render(painter, m_counter,m_frameWidth);
        m_stickMan.render(painter,m_counter);
        m_counter++;
    }
}

