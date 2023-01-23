
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sun 22 Jan 2023 11:28:25 PM EET
brief:
*/
#include <fstream>
namespace smartdoor
{
    constexpr char TempDevice[] = "/dev/TempDriver_DRIVER";
    class TempSensor
    {
    public:
        TempSensor();
        ~TempSensor();
        int getTemp();

    private:
        std::fstream m_TempDeviceFile;
    };
}
