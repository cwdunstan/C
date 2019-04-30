#include "dialog.h"
#include <QApplication>

#include <iostream>
#include <QTextStream>
#include <QFileInfo>

using namespace std;

inline bool exists(const std::string& name) {
    QFileInfo fileInfo(name.c_str());
    return fileInfo.exists();
}

bool isNumber(string value) {
    for (int i = 0; i < value.length(); i++) {
        if(!isdigit(value[i])) {
            return false;
        }
    }
    return true;
}
#include <QMessageBox>
int main(int argc, char *argv[]) {
    srand(time(NULL));

    QApplication a(argc, argv);
    Dialog gameDisplay;

    // Set up stickman player
    Stickman player;
    player.setSprite(":sprite0.png");

    // Set up background
    Background background;
    background.setSprite(":ground.png");
    background.setCoordinate(Coordinate(0, 150, 450));

    EntityFactory factory;

    // Read config file and set basic game attributes
    if (!exists("../Base1F/config.txt")) {
        cout << "Config file not found. Terminating" << endl;
        return 0;
    }
    QFile inputFile(QString("../Base1F/config.txt"));
    inputFile.open(QIODevice::ReadOnly);
    QTextStream stream(&inputFile);
    QString line = stream.readLine();
    while (!line.isNull()) {
        QStringList args = line.split(" ");
        if (args.length() < 2) {
            cout << "Invalid config format. Terminating" << endl;
            return 0;
        }
        string setting = line.split(" ").at(0).toStdString();
        //check if obstacle value
        if (setting.compare("obstacles:") != 0) {
            QString value = line.split(" ").at(1);
            if (setting.compare("size:") == 0) {
                string size = value.toStdString();
                if (size.compare("tiny") == 0 ||
                        size.compare("normal") == 0 ||
                        size.compare("large") == 0 ||
                        size.compare("giant") == 0) {
                    player.setSize(size);
                } else {
                    cout << "Size must be tiny, normal, large or giant. Terminating" << endl;
                    return 0;
                }
            } else if (setting.compare("x:") == 0) {
                if (!isNumber(value.toStdString())) {
                    cout << "X coordinate must be set to a postive integer. Terminating";
                    return 0;
                }
                int x = value.toInt();
                if (x < 0 || x > 800) {
                    cout << "X coordinate must be between 0 and 800. Terminating";
                    return 0;
                }
                player.setCoordinate(Coordinate(value.toInt(), 150, 450));
            } else if (setting.compare("velocity:") == 0) {
                if (!isNumber(value.toStdString())) {
                    cout << "Velocity must be set to a positive integer. Terminating";
                    return 0;
                }
                background.setVelocity(value.toInt());
                factory.setVelocity(value.toInt());
            } else if (setting.compare("background:") == 0) {
                string path = value.toStdString();
                if (exists(path)) {
                    background.setSprite(path);
                } else {
                    cout << "File \"" + path + "\" not found. Terminating";
                    return 0;
                }
            }
        }
        //obstacle list
        else if(setting.compare("obstacles:") == 0){
            //args[1] = first obstacle
            QStringList validObs;
            for(QString s :args.mid(1,args.length())){
                QStringList vals = s.split(",");
                if(vals.length()==4){
                    if((vals.value(0).compare("c")==0 || vals.value(0).compare("b")==0)
                            && (vals.value(2).compare("n")==0 || vals.value(2).compare("l")==0)){
                        if(isNumber(vals.value(1).toStdString()) && isNumber(vals.value(3).toStdString())){
                            validObs.push_back(s);
                        }
                    }
                }
            }
             gameDisplay.setArgs(validObs);

        }
        line = stream.readLine();
    };
    gameDisplay.setStickman(player);
    gameDisplay.setBackground(background);

    Coordinate origin(400, -140, 450);
    Moon moon(origin, 181.0, 550);

    gameDisplay.setMoon(moon);

    gameDisplay.show();

    return a.exec();
}



//to add
//obstacle sequence with y coordinates, sizing and spacing
//c = cactus+b=bird, y-coord, size: small+medium+large, spacing: x coord;
//e.g.

//obstacles: c,0,s,10 c,5,s,10
