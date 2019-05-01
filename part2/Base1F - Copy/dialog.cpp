#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog),
    stickman(),
    background(),
    night(false),
    moon(),
    obstacles(),
    clouds(),
    score(),
    factory(EntityFactory()),
    obstacleSpawnFrame(50),
    cloudSpawnFrame(20),
    counter(0) {
        ui->setupUi(this);
        this->resize(800,450);
        this->setStyleSheet("background-color: #F7F7F7;");
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
        timer->start(15);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::setStickman(Stickman stickman) {
    this->stickman = stickman;
}

void Dialog::setBackground(Background background) {
    this->background = background;
}

void Dialog::setMoon(Moon moon) {
    this->moon = moon;
}


void Dialog::setArgs(QStringList list){
    this->args = list;
}

void Dialog::paintEvent(QPaintEvent* /* event */) {
    QPainter painter(this);

    renderBackground(painter, counter);
    renderObstacles(painter, counter);
    spawnObstacles(counter);

    stickman.render(painter, counter);

    score.render(painter);

    speedUp(counter);

    counter++;
    score.increment();
}

// Draws ground and clouds and sets sky colour
void Dialog::renderBackground(QPainter &painter, unsigned int counter) {
    background.render(painter, counter);
    if (moon.render(painter, counter)) {
        if (night) {
            this->setStyleSheet("background-color: #F7F7F7;");
        } else {
            this->setStyleSheet("background-color: #000000;");
        }
        night = !night;
    }
    renderClouds(painter, counter);
}

// Render clouds and delete when they get off the screen
void Dialog::renderClouds(QPainter &painter, unsigned int counter) {
    bool deleteCloud = false;
    for (Entity &c: clouds) {
        c.render(painter, counter);
        if (c.getCoordinate().getQtRenderingXCoordinate() + c.width() < 0) {
            deleteCloud = true;
        }
    }
    if (deleteCloud) {
        clouds.erase(clouds.begin());
    }
}

// Render "obstacles" and delete when they get off the screen
void Dialog::renderObstacles(QPainter &painter, unsigned int counter) {
    bool deleteObstacle = false;
    for (Entity &o: obstacles) {
        o.render(painter, counter);
        if (o.getCoordinate().getQtRenderingXCoordinate() + o.width() < 0) {
            deleteObstacle = true;
        }
    }
    if (deleteObstacle) {
        obstacles.erase(obstacles.begin());
    }
}

// Spawn a new "obstacle" at random every so often
void Dialog::spawnObstacles(unsigned int counter) {


    if (counter == obstacleSpawnFrame) {
//        if(obstacles.size()==0){
//            addObstacle(factory.getEntity("bird",0,"s",0));
//        }else{
//            addObstacle(factory.getEntity("cactus",0,"s",100));
//        }
        for(QString s :args){
            QStringList vals = s.split(",");
            //add bird
            if(vals.value(0).compare("b")==0){
                addObstacle(factory.getEntity("bird",vals.value(1).toInt(),vals.value(2).toStdString(),vals.value(3).toInt()));

            }
            //add bird
            if(vals.value(0).compare("c")==0){
                addObstacle(factory.getEntity("cactus",vals.value(1).toInt(),vals.value(2).toStdString(),vals.value(3).toInt()));
            }
        }
        obstacleSpawnFrame += 300/background.getVelocity();
        //obstacleSpawnFrame += (300 / background.getVelocity()) + ((rand() % 16 )* 3);
    }

//    if (counter == cloudSpawnFrame) {
//        clouds.push_back(factory.getEntity("cloud",50,"s",0));
//        cloudSpawnFrame += ((450 / background.getVelocity()) + (rand() % 64) * 3);
//    }
}


void Dialog::addObstacle(Entity obstacle) {
    obstacles.push_back(obstacle);
}


// Incrementally speed up the scrolling speed
void Dialog::speedUp(unsigned int counter) {
    if (counter % 600 == 0) {
        background.setVelocity(background.getVelocity()+1);
        factory.setVelocity(background.getVelocity());
        // Have to speed up current entities too
        for (Entity &o: obstacles) {
            o.incrementVelocity();
        }
        for (Entity &c: clouds) {
            c.incrementVelocity();
        }
    }
}

//keypress events
void Dialog::keyPressEvent (QKeyEvent * event) {
    if (event->key() == Qt::Key_Space) {
        this->stickman.jump();
    }
}

void Dialog::nextFrame() {
    update();
}
