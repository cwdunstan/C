#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include<iostream>
#include <fstream>
#include <stdlib.h>

class fileReader
{
public:
    fileReader(std::string filePath);

    ~fileReader(){}
    //get x starting coordinate
    int getX();
    //get frame width
    int getFrameWidth();
    //get frame height
    int getFrameHeight();
    //get man size
    double getSize();
    //get man velocity
    int getVelocity();
    //get background file path
    std::string getBgPath();

private:
    int m_frameWidth;
    int m_frameHeight;
    int m_xcoord;
    double m_size;
    int m_velocity;
    std::string m_bgPath;


};

#endif // FILEREADER_H
