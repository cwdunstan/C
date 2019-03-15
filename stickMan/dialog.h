#ifndef DIALOG_H
#define DIALOG_H

#include "background.h"
#include "stickMan.h"
#include <QDialog>
#include <Qtimer>
#include <String>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int frameWidth, int frameHeight, int xcoord,double manSize, double velocity, std::string filepath,QWidget *parent = 0);
    ~Dialog();

    stickMan readConfig(std::string filepath);



public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Background m_background;
    stickMan m_stickMan;
    int m_counter;
    int m_frameWidth;
    int m_frameHeight;
    int m_xcoord;
    double m_manSize;
    double m_velocity;
    std::string m_filepath;
};

#endif // DIALOG_H
