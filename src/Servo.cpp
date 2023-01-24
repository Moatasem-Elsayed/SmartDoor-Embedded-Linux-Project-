
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
        if (m_ServoDeviceFile.is_open())
        {
            m_ServoDeviceFile.close();
        }
    }
    Servo::~Servo()
    {
    }
    void Servo::open()
    {
        controlfile([this]()
                    {
        m_ServoDeviceFile << "open";
        m_ServoDeviceFile.flush();
        std::cout << "Servo is open right now " << std::endl; });
    }
    void Servo::close()
    {
        controlfile([this]()
                    {
                                m_ServoDeviceFile << "close" << std::endl;
        m_ServoDeviceFile.flush();
        std::cout << "Servo is close right now " << std::endl; });
    }

    void Servo::controlfile(std::function<void()> fp)
    {
        m_ServoDeviceFile.open(ServoDevice, std::ios::out);
        if (m_ServoDeviceFile.good())
        {
            // calling callback
            fp();
        }
        if (m_ServoDeviceFile.is_open())
        {
            m_ServoDeviceFile.close();
        }
    }
}
