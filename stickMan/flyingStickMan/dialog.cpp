#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(fileReader * f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    //set all of the local variables from the filereader object
    m_filepath(f->getBgPath()),
    m_manSize(f->getSize()),
    m_xcoord(f->getX()),
    m_velocity(f->getVelocity()),
    m_frameWidth(f->getFrameWidth()),
    m_frameHeight(f->getFrameHeight()),
    m_imgWidth(f->getImgWidth()),
    m_imgHeight(f->getImgHeight()),
    //create a new background object
    m_background(Background(m_imgWidth,m_imgHeight,m_velocity,m_filepath)),
    m_stickMan(stickMan(m_xcoord,m_velocity,m_manSize))

{
    ui->setupUi(this);
    //resize frame to values from config file
    this->resize(m_frameWidth, m_frameHeight);
    //new background image
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

     QPainter painter(this);
     m_background.render(painter, m_counter,m_frameWidth);
     m_stickMan.render(painter,m_counter,m_frameHeight);
     m_counter++;

}
