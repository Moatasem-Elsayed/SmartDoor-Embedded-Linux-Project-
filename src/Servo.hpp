
#pragma once
/********************************************/
//                                          
//              CopyRight MoatasemElsayed                 
//                                          
/********************************************/
/*
author : MoatasemElsayed
date :Sun 22 Jan 2023 11:28:52 PM EET
brief:
*/
#include <fstream>
#include <iostream>
#include <string>
namespace smartdoor {
constexpr char ServoDevice[]="/dev/Servo_driver";
class Servo{

public:
    Servo();
    ~Servo();
     void open();
     void close();
private:
    std::fstream m_ServoDeviceFile;
};
}

