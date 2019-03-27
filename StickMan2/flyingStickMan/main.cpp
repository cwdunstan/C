#include "dialog.h"
#include <QApplication>
#include <QMediaPlayer>
#include <memory>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create & call dialog w
    Dialog w;
    w.setWindowTitle("FlyingStickMan");
    w.show();

    return a.exec();
}
