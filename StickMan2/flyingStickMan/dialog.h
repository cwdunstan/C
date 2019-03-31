#ifndef DIALOG_H
#define DIALOG_H

#include "filereader.h"
#include "gameobject.h"
#include "playerobject.h"

#include <iostream>
#include <memory>
#include <QDialog>
#include <QTimer>
#include <QMediaContent>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QApplication>

namespace Ui {
  class Dialog;
}
//dialog class
//declares functions
class Dialog : public QDialog {
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
    int m_startingx;
    bool m_paused;
    bool m_hard;
};

#endif // DIALOG_H

