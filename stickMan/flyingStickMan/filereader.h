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
    //get background image width
    int getImgWidth();
    //get background image height
    int getImgHeight();
    //get man size
    double getSize();
    //get man velocity
    double getVelocity();
    //get background file path
    std::string getBgPath();

private:
    int m_frameWidth;
    int m_frameHeight;
    int m_imgWidth;
    int m_imgHeight;
    int m_xcoord;
    double m_size;
    double m_velocity;
    std::string m_bgPath;


};

#endif // FILEREADER_H
