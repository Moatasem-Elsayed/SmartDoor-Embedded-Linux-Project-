
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:28:26 PM EET
brief:
*/
#include "TempSensor.hpp"
#include <iostream>
#include <regex>
namespace smartdoor
{
    TempSensor::TempSensor()
    {
        m_TempDeviceFile.open(TempDevice, std::ios::in);
        if (m_TempDeviceFile.good())
        {
            std::cout << "the file is opened successfully " << std::endl;
        }
        else
        {
            std::cout << "[Error] cannot open the file   " << std::endl;
        }
    }

    TempSensor::~TempSensor()
    {
        if (m_TempDeviceFile.is_open())
        {
            m_TempDeviceFile.close();
        }
    }

    int TempSensor::getTemp()
    {
        std::string value;
        std::getline(m_TempDeviceFile, value);
  	    std::regex regex("[\\d]+");
        std::smatch m;
        std::regex_search(value, m, regex);
        // for (auto &i : m)
        // {
        //     std::cout << i << std::endl;
        // }
        int valueinInt = std::atoi(m[0].str().c_str());
        std::cout << "the temp value is " << value << std::endl;
        return valueinInt;
    }
}
