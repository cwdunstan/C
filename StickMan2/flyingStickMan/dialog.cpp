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
    playlist =new QMediaPlaylist();
    playlist->addMedia(QUrl("../FlyingStickMan/soundtrack.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //keyboard

    ui->setupUi(this);
    //resize frame to values from config file
    this->setMaximumWidth(m_background->getWidth());
    this->setMinimumWidth(m_background->getWidth());
    this->setMaximumHeight(m_background->getHeight());
    this->setMinimumHeight(m_background->getHeight());
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
       m_stickMan->setState(1);
       m_background->setSpeed(60);
       m_background->setImage("../FlyingStickMan/grassyH.jpg");
       music->setMedia(QUrl("../FlyingStickMan/hardMode.mp3"));
        music->play();
    }
    if(event->key() == Qt::Key_U){
       m_background->revertspeed();
       m_stickMan->setState(0);
       m_background->setImage("../FlyingStickMan/grassy.jpg");
       music->setPlaylist(playlist);
       music->play();


    }
}

