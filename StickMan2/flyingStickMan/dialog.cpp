#include "dialog.h"
#include "ui_dialog.h"
#include "memory"
#include <iostream>
#include <QKeyEvent>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    std::unique_ptr<fileReader> filep(new fileReader("../flyingStickMan/config.txt"));
    //new game object factory
    backgroundFactory backgroundfactory;
    characterFactory characterfactory;
    m_stickMan=characterfactory.newCharacter(PLAYER,*filep);
    m_background= backgroundfactory.newObject(BG,*filep);


    //QMessageBox log;
    //log.setText(QString::fromStdString(m_background->tell()));
    //log.exec();

    //music player
    music=new QMediaPlayer();
    music->setMedia(QUrl("../FlyingStickMan/soundtrack.mp3"));
    music->play();

    //keyboard

    ui->setupUi(this);
    //resize frame to values from config file
    this->resize(m_background->getWidth(),m_background->getHeight());
    //start QTimer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);

    //read keys



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
     //call render function within background object.
     m_background->render(painter, m_counter);
     m_stickMan->render(painter,m_counter,m_background->getHeight());
     m_counter++;

}


//This key event triggers hard mode (on Y) and Normal (on U)
void Dialog::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Y){
       m_background->setSpeed(60);
       m_background->setImage("../FlyingStickMan/grassyH.jpg");
       music->setMedia(QUrl("../FlyingStickMan/hardMode.mp3"));
        music->play();
    }
    if(event->key() == Qt::Key_U){
       m_background->revertspeed();
       m_background->setImage("../FlyingStickMan/grassy.jpg");
       music->setMedia(QUrl("../FlyingStickMan/soundtrack.mp3"));
        music->play();
    }
}

