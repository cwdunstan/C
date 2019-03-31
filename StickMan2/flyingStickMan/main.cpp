#include "dialog.h"

//creates a new dialog
//sets title, then calls show
int main (int argc, char *argv[]) {
    QApplication a(argc, argv);
    Dialog game_dialog;
    game_dialog.setWindowTitle("Flying Stickman.");
    game_dialog.show();
    return a.exec();
}
