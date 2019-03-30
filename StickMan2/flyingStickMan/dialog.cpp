#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    std::unique_ptr<fileReader> filep(new fileReader("../flyingStickMan/config.txt"));
    //new game object factory
    backgroundFactory backgroundfactory;
    playerFactory playerfactory;

    m_background= backgroundfactory.newObject(BG,*filep);
    m_stickMan = playerfactory.newPlayer(filep->getSize());


    //music player
    playlist =new QMediaPlaylist();
    playlist->addMedia(QUrl("../FlyingStickMan/soundtrack.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    ui->setupUi(this);
    //resize frame to values from config file
    this->setMaximumWidth(m_background->getWidth());
    this->setMinimumWidth(m_background->getWidth());
    this->setMaximumHeight(m_background->getHeight());
    this->setMinimumHeight(m_background->getHeight());

    //start QTimer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
     m_currentSpeed=16;
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
     //m_stickMan->render(painter,m_counter,m_background->getHeight());
     m_stickMan->render(painter,m_counter,m_background->getHeight(),600);
     m_counter++;
}


//This key event triggers hard mode (on Y) and Normal (on U)
void Dialog::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Y){
       m_stickMan->setState(1);
       timer->start(4);
       m_currentSpeed=4;
       m_background->setTexture("../FlyingStickMan/grassyH.jpg");
       music->setMedia(QUrl("../FlyingStickMan/hardMode.mp3"));
       music->play();
    }
    if(event->key() == Qt::Key_U){
       timer->start(16);
       m_currentSpeed=16;
       m_stickMan->setState(0);
       m_background->setTexture("../FlyingStickMan/grassy.jpg");
       music->setPlaylist(playlist);
       music->play();
    }

    //Key Press P: Pause,
    if(event->key() == Qt::Key_P){
        if(!m_paused){
            timer->stop();
            music->pause();
            m_paused=true;
        }
        else{
            timer->start(m_currentSpeed);
            music->play();
             m_paused=false;
        }

    }
}

