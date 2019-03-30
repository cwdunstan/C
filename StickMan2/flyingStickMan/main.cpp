#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create game dialog, set the window title and call show
    Dialog game_dialog;

    game_dialog.setWindowTitle("Flying Stickman.");
    game_dialog.show();

    return a.exec();
}
