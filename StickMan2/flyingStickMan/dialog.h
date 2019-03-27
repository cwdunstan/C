#pragma once
#include "filereader.h"
#include "gameobject.h"
#include "gamecharacter.h"
#include <QMessageBox>
#include <QDialog>
#include <QTimer>
#include <QMediaContent>
#include <QMediaPlayer>



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
    gameCharacter* m_stickMan;
    gameObject* m_background;
    QMediaPlaylist * playlist;
    QMediaPlayer * music;
    int m_counter;
};


