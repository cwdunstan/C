#ifndef DIALOG_H
#define DIALOG_H

#include "filereader.h"
#include "gameobject.h"
#include "playerobject.h"
#include <QDialog>
#include <QTimer>
#include <QMediaContent>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <iostream>
#include <QKeyEvent>
#include <QApplication>
#include <memory>



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


public slots:
    void nextFrame();


protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Dialog *ui;
    gameObject* m_background;
    playerObject * m_stickMan;
    QMediaPlaylist * playlist;
    QMediaPlayer * music;
    QTimer *timer;
    int m_counter;
    int m_currentSpeed;
    bool m_paused;
};

#endif // DIALOG_H

