#ifndef DIALOG_H
#define DIALOG_H

#include "filereader.h"
#include "background.h"
#include "stickman.h"
#include <QDialog>
#include <Qtimer>
#include <Qpainter>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(fileReader * f, QWidget *parent = 0);
    ~Dialog();

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    std::string m_filepath;
    int m_counter;
    int m_frameWidth;
    int m_frameHeight;
    int m_imgWidth;
    int m_imgHeight;
    int m_xcoord;
    double m_manSize;
    int m_velocity;
    Background m_background;
    stickMan m_stickMan;
};

#endif // DIALOG_H
