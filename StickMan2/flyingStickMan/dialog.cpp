#include "dialog.h"
#include "ui_dialog.h"

//Creates a new Dialog
//instantiates a new filereader object from config file path, reading in all required values
//instatiates a new player and background object via factories, using values in the filereader object
//creates a new music player, and sets to looped playback
//restricts frame size to values specified in config file
//creates and sets new timer
Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog) {
    //smart pointer to filereader object. Param: filepath of config file.
    std::unique_ptr<fileReader> filep (new fileReader("../flyingStickMan/config.txt"));
    //initialize and declare factory
    backgroundFactory backgroundfactory;
    playerFactory playerfactory;
    m_background = backgroundfactory.newObject (BG, *filep);
    m_stickMan = playerfactory.newPlayer (filep->getSize());
    m_startingx=filep->getX();
    //music player
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl ("../FlyingStickMan/Resources/soundtrack.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    //setup UI and specify frame size
    ui->setupUi(this);
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

//destructor
Dialog::~Dialog() {
  delete ui;
}

//On next frame calls update
void Dialog::nextFrame() {
  update();
}

//Calls the render functions of all game objects, then updates counter value by 1.
void Dialog::paintEvent (QPaintEvent *event) {
  QPainter painter(this);
  m_background->render(painter, m_counter);
  m_stickMan->render(painter,m_counter,m_background->getHeight(),m_startingx);
  m_counter++;
}

//Key event triggers hard / normal mode (on press: O), and pause / resume (on press: P)
void Dialog::keyPressEvent (QKeyEvent * event) {
  //Change Difficulty
  if (event->key() == Qt::Key_O) {
    if (!m_hard) {
      m_stickMan->setState(1);
      timer->start(4);
      m_currentSpeed=4;
      m_background->setTexture("../FlyingStickMan/Resources/grassyH.jpg");
      music->setMedia(QUrl("../FlyingStickMan/Resources/hardMode.mp3"));
      music->play();
      m_hard=true;
    } else {
      timer->start(16);
      m_currentSpeed=16;
      m_stickMan->setState(0);
      m_background->setTexture("../FlyingStickMan/Resources/grassy.jpg");
      music->setPlaylist(playlist);
      music->play();
      m_hard=false;
    }
  }
  //Pause / resume game
  if (event->key() == Qt::Key_P) {
    if (!m_paused) {
      timer->stop();
      music->pause();
      m_paused = true;
    } else {
      timer->start(m_currentSpeed);
      music->play();
      m_paused = false;
    }
  }
}

