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

    int getWidth();

    int getX();

    int getHeigth();

    double getSize();

    double getVelocity();

    std::string getBgPath();

private:
    int m_width;
    int m_heigth;
    int m_xcoord;
    double m_size;
    double m_velocity;
    std::string m_bgPath;


};

#endif // FILEREADER_H
