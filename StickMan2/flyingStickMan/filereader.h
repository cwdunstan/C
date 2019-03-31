#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <set>
#include <stdlib.h>
#include <string>
#include <QMessageBox>

//filereader class
//generic getters
class fileReader {
  public:
    fileReader(std::string filePath);
    ~fileReader(){}
    int getFrameHeight();
    int getFrameWidth();
    int getVelocity();
    int getX();
    std::string getSize();
    std::string getBgPath();
  private:
    int m_frameWidth;
    int m_frameHeight;
    int m_velocity;
    int m_xcoord;
    std::string m_size;
    std::string m_bgPath;
};

#endif // FILEREADER_H
