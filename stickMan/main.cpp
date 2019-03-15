#include "dialog.h"
#include "filereader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //read in values from config file
    fileReader f("../stickMan/config.txt");

    //Pass file values to dialog object
    //frame width, frame height, x coordinate, man Size, velocity, background image filepath.
    Dialog w(f.getWidth(),f.getHeigth(),f.getX(),f.getSize(),f.getVelocity(),f.getBgPath());
    w.show();

    return a.exec();
}
