
/********************************************/
//
//              CopyRight MoatasemElsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:28:53 PM EET
brief:
*/
#include "Servo.hpp"

namespace smartdoor
{
    Servo::Servo()
    {
        m_ServoDeviceFile.open(ServoDevice, std::ios::out);
        if (m_ServoDeviceFile.good())
        {
            std::cout << "the Servo file is opened successfully " << std::endl;
        }
        else
        {
            std::cout << "[Error] cannot open the Servo file   " << std::endl;
        }
    }
    Servo::~Servo()
    {
        if (m_ServoDeviceFile.is_open())
        {
            m_ServoDeviceFile.close();
        }
    }
    void Servo::open()
    {
        m_ServoDeviceFile << "open";
        m_ServoDeviceFile.flush();
        std::cout << "Servo is open right now " << std::endl;
    }
    void Servo::close()
    {
        m_ServoDeviceFile << "close" << std::endl;
        m_ServoDeviceFile.flush();
        std::cout << "Servo is open right now " << std::endl;
    }
}
