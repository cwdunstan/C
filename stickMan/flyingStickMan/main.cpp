#include "dialog.h"
#include "filereader.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //create a filereader object, takes the config file path as input, extracts useful data.
    fileReader f("../flyingStickMan/config.txt");

    //create a pointer to the filereader.
    fileReader * fp = &f;

    //create & call dialog w, passing the pointer to filereader object.
    Dialog w(fp);
    w.show();

    return a.exec();
}
